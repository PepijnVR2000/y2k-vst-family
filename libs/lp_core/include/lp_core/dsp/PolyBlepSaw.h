#pragma once

#include "Math.h"

namespace lp::dsp
{
// Band-limited sawtooth using a 2-sample polyBLEP residual at the wrap.
// Output range is about [-1, 1]. Phase is kept in double for long notes.
class PolyBlepSaw
{
public:
    void prepare (double newSampleRate) noexcept
    {
        sampleRate = newSampleRate;
        reset();
    }

    void reset (double startPhase = 0.0) noexcept { phase = startPhase; }

    void setFrequency (double hz) noexcept
    {
        // Keep below Nyquist; above that the BLEP correction is meaningless.
        inc = clamp (hz / sampleRate, 0.0, 0.45);
    }

    float next() noexcept
    {
        double value = 2.0 * phase - 1.0;
        value -= blep (phase, inc);

        phase += inc;
        if (phase >= 1.0)
            phase -= 1.0;

        return static_cast<float> (value);
    }

    double getPhase() const noexcept { return phase; }

private:
    static double blep (double t, double dt) noexcept
    {
        if (dt <= 0.0)
            return 0.0;
        if (t < dt) // just after the wrap
        {
            t /= dt;
            return t + t - t * t - 1.0;
        }
        if (t > 1.0 - dt) // just before the wrap
        {
            t = (t - 1.0) / dt;
            return t * t + t + t + 1.0;
        }
        return 0.0;
    }

    double sampleRate = 44100.0, phase = 0.0, inc = 0.0;
};

} // namespace lp::dsp
