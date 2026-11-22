// lp_core DSP building blocks (JUCE-free).

#include <lp_core/dsp/AdsrEnvelope.h>
#include <lp_core/dsp/LinearSmoother.h>
#include <lp_core/dsp/MonoNoteStack.h>
#include <lp_core/dsp/PolyBlepSaw.h>
#include <lp_core/dsp/TptSvf.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <cmath>
#include <random>

using namespace lp::dsp;

TEST_CASE ("MonoNoteStack: last-note priority", "[dsp]")
{
    MonoNoteStack s;
    CHECK (s.isEmpty());
    s.push (60, 1.0f);
    s.push (64, 0.5f);
    s.push (67, 0.2f);
    CHECK (s.top().number == 67);
    CHECK (s.remove (64));
    CHECK (s.top().number == 67);
    CHECK (s.remove (67));
    CHECK (s.top().number == 60);
    s.push (60, 0.9f); // re-press: no duplicate
    CHECK (s.size() == 1);
    CHECK_FALSE (s.remove (99));
    s.push (200, 1.0f); // out of range ignored
    CHECK (s.size() == 1);
}

TEST_CASE ("PolyBlepSaw: bounded at all pitches", "[dsp]")
{
    for (double sr : { 44100.0, 48000.0, 96000.0 })
    {
        PolyBlepSaw osc;
        osc.prepare (sr);
        for (double hz : { 20.0, 440.0, 5000.0, 15000.0, 30000.0 })
        {
            osc.setFrequency (hz);
            float maxAbs = 0.0f;
            for (int i = 0; i < 10000; ++i)
                maxAbs = std::max (maxAbs, std::abs (osc.next()));
            INFO ("sr " << sr << " hz " << hz);
            CHECK (maxAbs <= 1.1f);
            if (hz <= 1000.0)
                CHECK (maxAbs > 0.9f); // few samples per period at high pitch: peak not sampled
        }
    }
}

TEST_CASE ("TptSvf: stable for any cutoff and resonance", "[dsp]")
{
    std::mt19937 rng (3);
    std::uniform_real_distribution<float> noise (-1.0f, 1.0f);

    for (double sr : { 22050.0, 44100.0, 192000.0 })
    {
        TptSvf f;
        f.prepare (sr);
        for (float cutoff : { 1.0f, 20.0f, 1000.0f, 20000.0f, 1.0e6f })
        {
            for (float res : { 0.0f, 0.5f, 1.0f })
            {
                f.setParameters (cutoff, res);
                float maxAbs = 0.0f;
                bool finite = true;
                for (int i = 0; i < 20000; ++i)
                {
                    const float y = f.processLowpass (noise (rng));
                    finite = finite && std::isfinite (y);
                    maxAbs = std::max (maxAbs, std::abs (y));
                }
                CHECK (finite);
                CHECK (maxAbs < 50.0f);
            }
        }
    }
}

TEST_CASE ("TptSvf: unity gain at DC", "[dsp]")
{
    TptSvf f;
    f.prepare (48000.0);
    f.setParameters (1000.0f, 0.3f);
    float y = 0.0f;
    for (int i = 0; i < 48000; ++i)
        y = f.processLowpass (1.0f);
    CHECK_THAT (y, Catch::Matchers::WithinAbs (1.0, 1.0e-4));
}

TEST_CASE ("LinearSmoother: reaches the target in exactly the ramp length", "[dsp]")
{
    LinearSmoother s;
    s.prepare (1000.0, 0.01); // 10 samples
    s.reset (0.0f);
    s.setTarget (1.0f);
    for (int i = 0; i < 9; ++i)
        CHECK (s.next() < 1.0f);
    CHECK (s.next() == 1.0f);
    CHECK_FALSE (s.isSmoothing());
}

TEST_CASE ("AdsrEnvelope: attack, sustain, release to idle", "[dsp]")
{
    AdsrEnvelope e;
    e.prepare (1000.0);
    e.setParameters (0.01f, 0.05f, 0.5f, 0.05f);
    CHECK_FALSE (e.isActive());
    e.noteOn();
    for (int i = 0; i < 10; ++i)
        e.next();
    CHECK (e.getLevel() == 1.0f);
    for (int i = 0; i < 200; ++i)
        e.next();
    CHECK_THAT (e.getLevel(), Catch::Matchers::WithinAbs (0.5, 1.0e-3));
    e.noteOff();
    for (int i = 0; i < 500; ++i)
        e.next();
    CHECK_FALSE (e.isActive());
    CHECK (e.getLevel() == 0.0f);
}
