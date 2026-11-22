#pragma once

#include "Math.h"

namespace lp::dsp
{
// Constant-time portamento in the pitch (semitone) domain. A glide always takes
// the configured time, whatever the interval (TB-303 style "slide" feel).
// FL Studio does not pass its piano-roll slide notes to plugins, so glide is
// driven internally by legato playing.
class Glide
{
public:
    void prepare (double newSampleRate) noexcept
    {
        sampleRate = newSampleRate;
        remaining = 0;
    }

    void setTime (float seconds) noexcept { glideSeconds = std::max (0.0f, seconds); }

    void jumpTo (double semitone) noexcept
    {
        current = target = semitone;
        remaining = 0;
    }

    void glideTo (double semitone) noexcept
    {
        target = semitone;
        const int length = static_cast<int> (glideSeconds * sampleRate);
        if (length < 1)
        {
            jumpTo (semitone);
            return;
        }
        remaining = length;
        step = (target - current) / length;
    }

    double next() noexcept
    {
        if (remaining > 0)
        {
            current += step;
            if (--remaining == 0)
                current = target;
        }
        return current;
    }

    bool isGliding() const noexcept { return remaining > 0; }
    double getCurrent() const noexcept { return current; }

private:
    double sampleRate = 44100.0;
    double current = 60.0, target = 60.0, step = 0.0;
    float glideSeconds = 0.0f;
    int remaining = 0;
};

} // namespace lp::dsp
