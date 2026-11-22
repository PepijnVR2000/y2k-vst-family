#pragma once

// Monophonic voice for the Disc 1 shell:
//   polyBLEP saw -> TPT SVF lowpass -> ADSR amp envelope
// Last-note priority; legato playing glides (no envelope retrigger).
// Everything is per-sample and allocation-free, so output does not depend on
// how the host splits blocks. No JUCE dependency.

#include <lp_core/dsp/AdsrEnvelope.h>
#include <lp_core/dsp/Glide.h>
#include <lp_core/dsp/LinearSmoother.h>
#include <lp_core/dsp/MonoNoteStack.h>
#include <lp_core/dsp/PolyBlepSaw.h>
#include <lp_core/dsp/TptSvf.h>

namespace disc1
{
struct VoiceParams
{
    float cutoffHz = 2500.0f;
    float resonance = 0.2f;
    float attackSec = 0.003f;
    float releaseSec = 0.15f;
    float glideSec = 0.06f;
    float levelGain = 0.25f;
};

class Disc1Voice
{
public:
    void prepare (double sampleRate, const VoiceParams& p) noexcept
    {
        osc.prepare (sampleRate);
        filter.prepare (sampleRate);
        env.prepare (sampleRate);
        glide.prepare (sampleRate);
        notes.clear();

        cutoff.prepare (sampleRate, 0.02);
        resonance.prepare (sampleRate, 0.02);
        level.prepare (sampleRate, 0.02);
        cutoff.reset (p.cutoffHz);
        resonance.reset (p.resonance);
        level.reset (p.levelGain);

        lastPitch = -1.0;
        setParameters (p);
        filter.setParameters (cutoff.getCurrent(), resonance.getCurrent());
    }

    // Call once per block (or sub-block) from the audio thread.
    void setParameters (const VoiceParams& p) noexcept
    {
        cutoff.setTarget (p.cutoffHz);
        resonance.setTarget (p.resonance);
        level.setTarget (p.levelGain);
        env.setParameters (p.attackSec, 0.3f, 1.0f, p.releaseSec);
        glide.setTime (p.glideSec);
    }

    void noteOn (int note, float velocity) noexcept
    {
        const bool legato = ! notes.isEmpty() && env.isActive();
        notes.push (note, velocity);

        if (legato)
        {
            glide.glideTo (note);
            return;
        }

        glide.jumpTo (note);
        velocityGain = 0.3f + 0.7f * lp::dsp::clamp (velocity, 0.0f, 1.0f);
        env.noteOn();
    }

    void noteOff (int note) noexcept
    {
        const bool wasSounding = notes.top().number == note;
        notes.remove (note);

        if (notes.isEmpty())
            env.noteOff();
        else if (wasSounding)
            glide.glideTo (notes.top().number); // fall back to the previous held note
    }

    void allNotesOff() noexcept
    {
        notes.clear();
        env.noteOff();
    }

    void allSoundOff() noexcept
    {
        notes.clear();
        env.reset();
        filter.reset();
    }

    // Adds the voice into `out` (mono) for samples [0, numSamples).
    void render (float* out, int numSamples) noexcept
    {
        for (int i = 0; i < numSamples; ++i)
        {
            // Smoothers advance every sample, sounding or not, so their state
            // only depends on the sample index.
            const bool filterMoving = cutoff.isSmoothing() || resonance.isSmoothing();
            const float c = cutoff.next();
            const float r = resonance.next();
            const float g = level.next();

            if (filterMoving)
                filter.setParameters (c, r);

            if (! env.isActive())
                continue;

            const double pitch = glide.next();
            if (! lp::dsp::exactlyEqual (pitch, lastPitch))
            {
                osc.setFrequency (lp::dsp::midiNoteToHz (pitch));
                lastPitch = pitch;
            }

            const float s = filter.processLowpass (osc.next());
            out[i] += s * env.next() * velocityGain * g;
        }
    }

    bool isActive() const noexcept { return env.isActive(); }
    int currentNote() const noexcept { return notes.top().number; }
    double currentPitch() const noexcept { return glide.getCurrent(); }

private:
    lp::dsp::PolyBlepSaw osc;
    lp::dsp::TptSvf filter;
    lp::dsp::AdsrEnvelope env;
    lp::dsp::Glide glide;
    lp::dsp::MonoNoteStack notes;
    lp::dsp::LinearSmoother cutoff, resonance, level;

    float velocityGain = 1.0f;
    double lastPitch = -1.0;
};

} // namespace disc1
