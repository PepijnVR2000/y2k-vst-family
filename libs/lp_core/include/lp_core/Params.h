#pragma once

// Parameter helpers shared by the family.
//
// Rules (see also HANDOFF.md):
// - Parameter IDs are stable strings and are never reused or renamed once a
//   build has left the developer's machine: hosts store automation by ID.
// - Every parameter carries a version hint (juce::ParameterID{id, version}).
//   New parameters added later get a higher version number.
// - Audio thread reads parameters through ParamRef (one relaxed atomic load).

#include <juce_audio_processors/juce_audio_processors.h>

#include <atomic>
#include <memory>

namespace lp::params
{
// Range whose middle position (0.5 normalised) is `centre`.
inline juce::NormalisableRange<float> skewedRange (float min, float max, float centre)
{
    juce::NormalisableRange<float> r { min, max };
    r.setSkewForCentre (centre);
    return r;
}

// Text formatting -------------------------------------------------------------
inline juce::String formatHz (float hz, int)
{
    return hz < 1000.0f ? juce::String (juce::roundToInt (hz)) + " Hz"
                        : juce::String (hz / 1000.0f, 2) + " kHz";
}

inline juce::String formatSeconds (float s, int)
{
    return s < 1.0f ? juce::String (juce::roundToInt (s * 1000.0f)) + " ms"
                    : juce::String (s, 2) + " s";
}

inline juce::String formatDb (float db, int) { return juce::String (db, 1) + " dB"; }

inline juce::String formatPercent (float v, int) { return juce::String (juce::roundToInt (v * 100.0f)) + " %"; }

// Parsing accepts the formatted text back (and plain numbers in base units).
inline float parseHz (const juce::String& t)
{
    const auto v = t.getFloatValue();
    return t.containsIgnoreCase ("k") ? v * 1000.0f : v;
}

inline float parseSeconds (const juce::String& t)
{
    const auto v = t.getFloatValue();
    return t.containsIgnoreCase ("ms") ? v / 1000.0f : v;
}

inline float parsePercent (const juce::String& t) { return t.getFloatValue() / 100.0f; }

enum class Unit { plain, hz, seconds, db, percent };

inline std::unique_ptr<juce::AudioParameterFloat> makeFloat (const juce::String& id,
                                                             const juce::String& name,
                                                             juce::NormalisableRange<float> range,
                                                             float defaultValue,
                                                             Unit unit = Unit::plain,
                                                             int versionHint = 1)
{
    auto attributes = juce::AudioParameterFloatAttributes {};

    switch (unit)
    {
        case Unit::hz:
            attributes = attributes.withStringFromValueFunction (formatHz)
                                   .withValueFromStringFunction (parseHz)
                                   .withLabel ("Hz");
            break;
        case Unit::seconds:
            attributes = attributes.withStringFromValueFunction (formatSeconds)
                                   .withValueFromStringFunction (parseSeconds)
                                   .withLabel ("s");
            break;
        case Unit::db:
            attributes = attributes.withStringFromValueFunction (formatDb).withLabel ("dB");
            break;
        case Unit::percent:
            attributes = attributes.withStringFromValueFunction (formatPercent)
                                   .withValueFromStringFunction (parsePercent)
                                   .withLabel ("%");
            break;
        case Unit::plain:
            break;
    }

    return std::make_unique<juce::AudioParameterFloat> (juce::ParameterID { id, versionHint },
                                                        name, range, defaultValue, attributes);
}

// Cached, lock-free view of one APVTS parameter for the audio thread.
class ParamRef
{
public:
    ParamRef() = default;

    ParamRef (juce::AudioProcessorValueTreeState& state, const juce::String& id)
        : value (state.getRawParameterValue (id))
    {
        jassert (value != nullptr); // unknown parameter id
    }

    float get() const noexcept { return value->load (std::memory_order_relaxed); }

private:
    std::atomic<float>* value = nullptr;
};

} // namespace lp::params
