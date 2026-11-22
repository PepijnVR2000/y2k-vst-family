#pragma once

// Small math helpers. No JUCE dependency, no allocation.

#include <algorithm>
#include <cmath>
#include <numbers>

namespace lp::dsp
{
inline constexpr double pi = std::numbers::pi;

inline double midiNoteToHz (double note) noexcept
{
    return 440.0 * std::exp2 ((note - 69.0) / 12.0);
}

inline float dbToGain (float db, float minusInfinityDb = -100.0f) noexcept
{
    return db <= minusInfinityDb ? 0.0f : std::pow (10.0f, db * 0.05f);
}

// Exact comparison without tripping -Wfloat-equal (intentional exact checks only).
template <typename T>
constexpr bool exactlyEqual (T a, T b) noexcept
{
    return ! (a < b) && ! (b < a);
}

template <typename T>
constexpr T clamp (T v, T lo, T hi) noexcept
{
    return std::min (std::max (v, lo), hi);
}

// Placeholder DSP utility: flush tiny values to zero to keep recursive filters
// out of the denormal range even when the CPU's FTZ/DAZ flags are not set.
inline float flushDenormal (float v) noexcept
{
    return std::abs (v) < 1.0e-15f ? 0.0f : v;
}

inline double flushDenormal (double v) noexcept
{
    return std::abs (v) < 1.0e-30 ? 0.0 : v;
}

} // namespace lp::dsp
