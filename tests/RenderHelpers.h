#pragma once

// Host-less offline rendering of a processor with arbitrary block splitting.

#include "AllocationGuard.h"

#include <juce_audio_processors/juce_audio_processors.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <vector>

namespace lp::test
{
struct NoteEvent
{
    int sample;
    int note;
    float velocity; // 0 = note off
};

struct RenderResult
{
    std::vector<float> left, right;
    int allocations = 0;
};

inline constexpr int maxBlockSize = 2048;

// Renders `totalSamples` samples. `nextBlockSize` returns the next block length
// (clamped to 1..maxBlockSize). `beforeBlock` may tweak parameters per block.
inline RenderResult render (juce::AudioProcessor& processor,
                            double sampleRate,
                            int totalSamples,
                            const std::vector<NoteEvent>& events,
                            const std::function<int()>& nextBlockSize,
                            const std::function<void (int blockStart)>& beforeBlock = {})
{
    processor.setPlayConfigDetails (0, 2, sampleRate, maxBlockSize);
    processor.prepareToPlay (sampleRate, maxBlockSize);

    RenderResult result;
    result.left.assign (static_cast<size_t> (totalSamples), 0.0f);
    result.right.assign (static_cast<size_t> (totalSamples), 0.0f);

    std::vector<float> scratchL (maxBlockSize), scratchR (maxBlockSize);
    juce::MidiBuffer midi;
    midi.ensureSize (4096);

    int pos = 0;
    while (pos < totalSamples)
    {
        const int n = std::min (std::clamp (nextBlockSize(), 1, maxBlockSize), totalSamples - pos);

        if (beforeBlock)
            beforeBlock (pos);

        midi.clear();
        for (const auto& e : events)
        {
            if (e.sample >= pos && e.sample < pos + n)
            {
                const auto msg = e.velocity > 0.0f
                                     ? juce::MidiMessage::noteOn (1, e.note, e.velocity)
                                     : juce::MidiMessage::noteOff (1, e.note);
                midi.addEvent (msg, e.sample - pos);
            }
        }

        std::array<float*, 2> channels { scratchL.data(), scratchR.data() };
        juce::AudioBuffer<float> buffer (channels.data(), 2, n);

        {
            ScopedAllocationCheck check;
            processor.processBlock (buffer, midi);
            result.allocations += check.count();
        }

        std::copy_n (scratchL.data(), n, result.left.begin() + pos);
        std::copy_n (scratchR.data(), n, result.right.begin() + pos);
        pos += n;
    }

    processor.releaseResources();
    return result;
}

inline std::function<int()> fixedBlocks (int size)
{
    return [size] { return size; };
}

inline bool allFinite (const std::vector<float>& v)
{
    return std::all_of (v.begin(), v.end(), [] (float x) { return std::isfinite (x); });
}

inline float peak (const std::vector<float>& v, size_t from = 0, size_t to = SIZE_MAX)
{
    float p = 0.0f;
    for (size_t i = from; i < std::min (to, v.size()); ++i)
        p = std::max (p, std::abs (v[i]));
    return p;
}

inline float rms (const std::vector<float>& v, size_t from = 0, size_t to = SIZE_MAX)
{
    to = std::min (to, v.size());
    if (to <= from)
        return 0.0f;
    double sum = 0.0;
    for (size_t i = from; i < to; ++i)
        sum += static_cast<double> (v[i]) * v[i];
    return static_cast<float> (std::sqrt (sum / static_cast<double> (to - from)));
}

inline void setParam (juce::AudioProcessorValueTreeState& state, const char* id, float plainValue)
{
    auto* p = state.getParameter (id);
    p->setValueNotifyingHost (p->convertTo0to1 (plainValue));
}

} // namespace lp::test
