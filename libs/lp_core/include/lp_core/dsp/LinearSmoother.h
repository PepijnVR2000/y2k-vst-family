#pragma once

#include "Math.h"

#include <algorithm>
#include <cmath>

namespace lp::dsp
{
// Per-sample linear ramp towards a target. The ramp length is fixed in samples,
// so the output depends only on the sample index at which setTarget() is called,
// never on how the host splits blocks.
class LinearSmoother
{
public:
    void prepare (double sampleRate, double rampSeconds) noexcept
    {
        rampLength = std::max (1, static_cast<int> (std::lround (sampleRate * rampSeconds)));
        remaining = 0;
        current = target;
    }

    // Jump without ramping (e.g. on prepare / reset).
    void reset (float value) noexcept
    {
        current = target = value;
        remaining = 0;
    }

    void setTarget (float newTarget) noexcept
    {
        if (exactlyEqual (newTarget, target))
            return;
        target = newTarget;
        remaining = rampLength;
        step = (target - current) / static_cast<float> (rampLength);
    }

    float next() noexcept
    {
        if (remaining > 0)
        {
            current += step;
            if (--remaining == 0)
                current = target;
        }
        return current;
    }

    bool isSmoothing() const noexcept { return remaining > 0; }
    float getCurrent() const noexcept { return current; }
    float getTarget() const noexcept { return target; }

private:
    float current = 0.0f, target = 0.0f, step = 0.0f;
    int rampLength = 1, remaining = 0;
};

} // namespace lp::dsp
