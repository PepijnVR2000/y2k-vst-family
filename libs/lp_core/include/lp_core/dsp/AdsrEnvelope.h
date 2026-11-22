#pragma once

#include "Math.h"

namespace lp::dsp
{
// ADSR: linear attack, exponential decay and release (one-pole towards the
// segment target). Times are "time to reach ~99%" for the exponential segments.
// Purely per-sample, so results are identical for any block split.
class AdsrEnvelope
{
public:
    enum class Stage { idle, attack, decay, sustain, release };

    void prepare (double newSampleRate) noexcept
    {
        sampleRate = newSampleRate;
        reset();
        setParameters (attackSec, decaySec, sustainLevel, releaseSec);
    }

    void reset() noexcept
    {
        stage = Stage::idle;
        level = 0.0f;
    }

    void setParameters (float attackSeconds, float decaySeconds, float sustain, float releaseSeconds) noexcept
    {
        attackSec = std::max (0.0f, attackSeconds);
        decaySec = std::max (0.0f, decaySeconds);
        sustainLevel = clamp (sustain, 0.0f, 1.0f);
        releaseSec = std::max (0.0f, releaseSeconds);

        const auto sr = static_cast<float> (sampleRate);
        attackInc = attackSec * sr < 1.0f ? 1.0f : 1.0f / (attackSec * sr);
        decayCoef = expCoef (decaySec);
        releaseCoef = expCoef (releaseSec);
    }

    void noteOn() noexcept { stage = Stage::attack; } // starts from the current level (no click)
    void noteOff() noexcept
    {
        if (stage != Stage::idle)
            stage = Stage::release;
    }

    float next() noexcept
    {
        switch (stage)
        {
            case Stage::idle:
                break;
            case Stage::attack:
                level += attackInc;
                if (level >= 1.0f)
                {
                    level = 1.0f;
                    stage = Stage::decay;
                }
                break;
            case Stage::decay:
                level = sustainLevel + (level - sustainLevel) * decayCoef;
                if (level - sustainLevel < 1.0e-4f)
                {
                    level = sustainLevel;
                    stage = Stage::sustain;
                }
                break;
            case Stage::sustain:
                level = sustainLevel;
                break;
            case Stage::release:
                level *= releaseCoef;
                if (level < 1.0e-5f)
                {
                    level = 0.0f;
                    stage = Stage::idle;
                }
                break;
        }
        return level;
    }

    bool isActive() const noexcept { return stage != Stage::idle; }
    Stage getStage() const noexcept { return stage; }
    float getLevel() const noexcept { return level; }

private:
    float expCoef (float seconds) const noexcept
    {
        const float samples = seconds * static_cast<float> (sampleRate);
        // ln(0.01) ~= -4.6: reach 1% of the distance after `samples`
        return samples < 1.0f ? 0.0f : std::exp (-4.6f / samples);
    }

    double sampleRate = 44100.0;
    float attackSec = 0.005f, decaySec = 0.2f, sustainLevel = 1.0f, releaseSec = 0.2f;
    float attackInc = 1.0f, decayCoef = 0.0f, releaseCoef = 0.0f;
    float level = 0.0f;
    Stage stage = Stage::idle;
};

} // namespace lp::dsp
