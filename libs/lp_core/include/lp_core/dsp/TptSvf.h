#pragma once

#include "Math.h"

namespace lp::dsp
{
// Topology-preserving-transform state-variable filter (Zavalishin / Simper).
// Lowpass output only for now. Stable for any cutoff below Nyquist and any
// resonance in [0, 1]; cutoff is clamped to 0.45 * sampleRate.
class TptSvf
{
public:
    void prepare (double newSampleRate) noexcept
    {
        sampleRate = newSampleRate;
        reset();
        setParameters (1000.0f, 0.0f);
    }

    void reset() noexcept { ic1 = ic2 = 0.0; }

    // resonance 0..1 maps to damping k = 2 (Q 0.5) .. 0.06 (Q ~16.7)
    void setParameters (float cutoffHz, float resonance) noexcept
    {
        const double fc = clamp (static_cast<double> (cutoffHz), 10.0, 0.45 * sampleRate);
        const double res = clamp (static_cast<double> (resonance), 0.0, 1.0);
        const double g = std::tan (pi * fc / sampleRate);
        k = 2.0 - 1.94 * res;
        a1 = 1.0 / (1.0 + g * (g + k));
        a2 = g * a1;
        a3 = g * a2;
    }

    float processLowpass (float x) noexcept
    {
        const double v0 = x;
        const double v3 = v0 - ic2;
        const double v1 = a1 * ic1 + a2 * v3;
        const double v2 = ic2 + a2 * ic1 + a3 * v3;
        ic1 = flushDenormal (2.0 * v1 - ic1);
        ic2 = flushDenormal (2.0 * v2 - ic2);
        return static_cast<float> (v2);
    }

private:
    double sampleRate = 44100.0;
    double k = 2.0, a1 = 0.0, a2 = 0.0, a3 = 0.0;
    double ic1 = 0.0, ic2 = 0.0;
};

} // namespace lp::dsp
