#pragma once

#include <lp_core/Params.h>

// Disc 1 parameters. IDs are stable: never rename or reuse them.
namespace disc1::ids
{
inline constexpr const char* cutoff = "cutoff";
inline constexpr const char* resonance = "resonance";
inline constexpr const char* attack = "attack";
inline constexpr const char* release = "release";
inline constexpr const char* glide = "glide";
inline constexpr const char* level = "level";
} // namespace disc1::ids

namespace disc1
{
inline juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
    using lp::params::makeFloat;
    using lp::params::skewedRange;
    using lp::params::Unit;

    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    layout.add (makeFloat (ids::cutoff, "Cutoff", skewedRange (20.0f, 20000.0f, 1000.0f), 2500.0f, Unit::hz));
    layout.add (makeFloat (ids::resonance, "Resonance", { 0.0f, 1.0f }, 0.2f, Unit::percent));
    layout.add (makeFloat (ids::attack, "Attack", skewedRange (0.001f, 2.0f, 0.05f), 0.003f, Unit::seconds));
    layout.add (makeFloat (ids::release, "Release", skewedRange (0.005f, 4.0f, 0.3f), 0.15f, Unit::seconds));
    layout.add (makeFloat (ids::glide, "Glide", skewedRange (0.0f, 1.0f, 0.1f), 0.06f, Unit::seconds));
    layout.add (makeFloat (ids::level, "Level", { -48.0f, 6.0f }, -12.0f, Unit::db));
    return layout;
}

} // namespace disc1
