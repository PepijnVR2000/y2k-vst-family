#include "RenderHelpers.h"

#include <PluginProcessor.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <random>

using namespace lp::test;
using disc1::Disc1Processor;
namespace ids = disc1::ids;

namespace
{
// A phrase that exercises the mono logic: a plain note, legato overlap (glide),
// return to a held note, a gap (retrigger), several events on one sample.
std::vector<NoteEvent> phrase (double sr)
{
    auto s = [sr] (double seconds) { return static_cast<int> (seconds * sr); };
    return {
        { s (0.00), 45, 0.8f },
        { s (0.20), 52, 0.6f }, // legato -> glide up
        { s (0.30), 52, 0.0f }, // release top note -> glide back to 45
        { s (0.45), 45, 0.0f },
        { s (0.60), 57, 1.0f }, // retrigger after release
        { s (0.60), 60, 0.5f }, // same sample: last note wins
        { s (0.75), 60, 0.0f },
        { s (0.75), 57, 0.0f },
        { s (0.80), 40, 0.9f },
        { s (0.95), 40, 0.0f },
    };
}

std::function<int()> randomBlocks (unsigned seed)
{
    auto rng = std::make_shared<std::mt19937> (seed);
    return [rng] { return std::uniform_int_distribution<int> (1, maxBlockSize) (*rng); };
}

float maxAbsDiff (const std::vector<float>& a, const std::vector<float>& b)
{
    REQUIRE (a.size() == b.size());
    float d = 0.0f;
    for (size_t i = 0; i < a.size(); ++i)
        d = std::max (d, std::abs (a[i] - b[i]));
    return d;
}
} // namespace

TEST_CASE ("Disc1: identity comes from the central CMake names", "[disc1]")
{
    Disc1Processor p;
    CHECK (p.getName() == juce::String (LP_PLUGIN_NAME_EXPECTED));
    CHECK (p.acceptsMidi());
    CHECK_FALSE (p.producesMidi());
    CHECK (p.getParameters().size() == 6);
}

TEST_CASE ("Disc1: offline render of a note is audible, finite and not clipping", "[disc1][render]")
{
    const double sr = GENERATE (44100.0, 48000.0, 96000.0);
    Disc1Processor p;

    const int total = static_cast<int> (1.5 * sr);
    const std::vector<NoteEvent> events { { 0, 45, 1.0f }, { static_cast<int> (0.5 * sr), 45, 0.0f } };
    const auto out = render (p, sr, total, events, fixedBlocks (512));

    REQUIRE (allFinite (out.left));
    REQUIRE (allFinite (out.right));

    const auto held = static_cast<size_t> (0.5 * sr);
    CHECK (rms (out.left, 0, held) > 0.02f);      // non-silent
    CHECK (peak (out.left) < 0.99f);              // not clipping
    CHECK (maxAbsDiff (out.left, out.right) == 0.0f);

    // After the release (0.15 s default) the tail has died away.
    CHECK (peak (out.left, static_cast<size_t> (1.2 * sr)) < 1.0e-3f);
}

TEST_CASE ("Disc1: random block sizes 1..2048 render the same as fixed blocks", "[disc1][blocks]")
{
    const double sr = 48000.0;
    const int total = static_cast<int> (1.2 * sr);
    const auto events = phrase (sr);

    Disc1Processor reference;
    const auto fixed = render (reference, sr, total, events, fixedBlocks (512));
    REQUIRE (rms (fixed.left) > 0.01f);

    SECTION ("random sizes")
    {
        for (unsigned seed : { 1u, 2u, 3u, 1234u })
        {
            Disc1Processor p;
            const auto randomOut = render (p, sr, total, events, randomBlocks (seed));
            CHECK (maxAbsDiff (fixed.left, randomOut.left) < 1.0e-6f);
        }
    }

    SECTION ("single-sample and odd sizes")
    {
        for (int size : { 1, 7, 64, 2048 })
        {
            Disc1Processor p;
            const auto out = render (p, sr, total, events, fixedBlocks (size));
            CHECK (maxAbsDiff (fixed.left, out.left) < 1.0e-6f);
        }
    }
}

TEST_CASE ("Allocation guard detects heap allocations", "[realtime]")
{
    ScopedAllocationCheck check;
    auto v = std::make_unique<std::vector<int>> (100);
    CHECK (check.count() >= 2);
}

TEST_CASE ("Disc1: processBlock does not allocate", "[disc1][realtime]")
{
    const double sr = 48000.0;
    Disc1Processor p;
    std::mt19937 rng (7);
    auto& state = p.getState();

    // Parameter changes every block, random block sizes, the full phrase.
    const auto out = render (p, sr, static_cast<int> (1.2 * sr), phrase (sr), randomBlocks (99), [&] (int) {
        setParam (state, ids::cutoff, std::uniform_real_distribution<float> (20.0f, 20000.0f) (rng));
        setParam (state, ids::level, std::uniform_real_distribution<float> (-48.0f, 0.0f) (rng));
    });

    CHECK (out.allocations == 0);
}

TEST_CASE ("Disc1: extreme and random parameter changes never produce NaN/Inf", "[disc1][params]")
{
    const double sr = GENERATE (44100.0, 48000.0, 96000.0, 192000.0);
    Disc1Processor p;
    std::mt19937 rng (static_cast<unsigned> (sr));

    std::vector<NoteEvent> events;
    for (int i = 0; i < 40; ++i)
    {
        const int at = static_cast<int> (i * 0.05 * sr);
        events.push_back ({ at, 24 + (i * 7) % 84, (i % 3 == 0) ? 0.0f : 1.0f });
    }

    auto* const params = &p.getParameters();
    const auto out = render (p, sr, static_cast<int> (2.0 * sr), events, randomBlocks (5), [&] (int) {
        for (auto* param : *params)
        {
            // Mix of extremes (0, 1) and random values.
            const int mode = std::uniform_int_distribution<int> (0, 3) (rng);
            const float v = mode == 0 ? 0.0f
                          : mode == 1 ? 1.0f
                                      : std::uniform_real_distribution<float> (0.0f, 1.0f) (rng);
            param->setValueNotifyingHost (v);
        }
    });

    REQUIRE (allFinite (out.left));
    // Max level + max resonance on a harmonic is loud by design; this only
    // guards against blow-ups (unstable filter, runaway glide).
    CHECK (peak (out.left) < 100.0f);
    CHECK (out.allocations == 0);
}

TEST_CASE ("Disc1: sample-rate changes re-prepare correctly (pitch stays right)", "[disc1][samplerate]")
{
    Disc1Processor p;
    auto& state = p.getState();
    setParam (state, ids::cutoff, 20000.0f);
    setParam (state, ids::resonance, 0.0f);

    // Same instance, different rates in sequence (as a host does on a device change).
    for (double sr : { 44100.0, 96000.0, 22050.0, 48000.0 })
    {
        const int total = static_cast<int> (1.0 * sr);
        const auto out = render (p, sr, total, { { 0, 69, 1.0f } }, randomBlocks (11));
        REQUIRE (allFinite (out.left));

        // A saw has one upward zero crossing per period: 440 Hz -> ~220 in 0.5 s.
        int crossings = 0;
        for (size_t i = static_cast<size_t> (0.5 * sr); i < out.left.size(); ++i)
            if (out.left[i - 1] < 0.0f && out.left[i] >= 0.0f)
                ++crossings;
        INFO ("sample rate " << sr);
        CHECK (std::abs (crossings - 220) <= 2);
    }
}

TEST_CASE ("Disc1: state round-trip restores every parameter", "[disc1][state]")
{
    Disc1Processor a;
    setParam (a.getState(), ids::cutoff, 432.0f);
    setParam (a.getState(), ids::resonance, 0.77f);
    setParam (a.getState(), ids::attack, 0.25f);
    setParam (a.getState(), ids::release, 1.5f);
    setParam (a.getState(), ids::glide, 0.2f);
    setParam (a.getState(), ids::level, -3.0f);

    juce::MemoryBlock saved;
    a.getStateInformation (saved);
    REQUIRE (saved.getSize() > 0);

    Disc1Processor b;
    b.setStateInformation (saved.getData(), static_cast<int> (saved.getSize()));

    const auto& pa = a.getParameters();
    const auto& pb = b.getParameters();
    REQUIRE (pa.size() == pb.size());
    for (int i = 0; i < pa.size(); ++i)
    {
        INFO (pa[i]->getName (64));
        CHECK_THAT (pb[i]->getValue(), Catch::Matchers::WithinAbs (pa[i]->getValue(), 1.0e-6));
    }

    // And the restored instance sounds identical.
    const auto ra = render (a, 48000.0, 24000, phrase (48000.0), fixedBlocks (256));
    const auto rb = render (b, 48000.0, 24000, phrase (48000.0), fixedBlocks (256));
    CHECK (maxAbsDiff (ra.left, rb.left) == 0.0f);

    SECTION ("garbage state is ignored")
    {
        const char junk[] = "not a plugin state";
        b.setStateInformation (junk, static_cast<int> (sizeof (junk)));
        b.setStateInformation (nullptr, 0);
        for (int i = 0; i < pa.size(); ++i)
            CHECK_THAT (pb[i]->getValue(), Catch::Matchers::WithinAbs (pa[i]->getValue(), 1.0e-6));
    }
}

TEST_CASE ("Disc1: last-note priority and legato glide", "[disc1][mono]")
{
    disc1::Disc1Voice v;
    disc1::VoiceParams params;
    params.glideSec = 0.1f;
    const double sr = 48000.0;
    v.prepare (sr, params);
    std::vector<float> buf (4800);

    v.noteOn (60, 1.0f);
    v.render (buf.data(), 480);
    CHECK (v.currentNote() == 60);
    CHECK (v.currentPitch() == 60.0); // first note: no glide

    v.noteOn (64, 1.0f); // legato
    CHECK (v.currentNote() == 64);
    v.render (buf.data(), 2400); // half the glide time
    CHECK (v.currentPitch() > 61.5);
    CHECK (v.currentPitch() < 62.5);
    v.render (buf.data(), 2400);
    CHECK (v.currentPitch() == 64.0);

    v.noteOff (64); // falls back to the held 60, gliding
    CHECK (v.currentNote() == 60);
    CHECK (v.isActive());
    v.render (buf.data(), 4800);
    CHECK (v.currentPitch() == 60.0);

    v.noteOff (60);
    for (int i = 0; i < 10; ++i) // 1 s, well past the 0.15 s release
        v.render (buf.data(), 4800);
    CHECK_FALSE (v.isActive());

    // Non-legato note after release jumps (no glide).
    v.noteOn (72, 1.0f);
    v.render (buf.data(), 1);
    CHECK (v.currentPitch() == 72.0);
}
