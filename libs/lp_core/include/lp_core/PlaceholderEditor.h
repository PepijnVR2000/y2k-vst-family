#pragma once

// Plain placeholder editor used until the art direction is final.
// Deliberately NOT a design: dark background, one line of centred text, and
// the plugin name + version + build hash so the user can tell builds apart.
// No animation, no timers, nothing allocated in paint().

#include <juce_audio_processors/juce_audio_processors.h>

namespace lp
{
class PlaceholderEditor final : public juce::AudioProcessorEditor
{
public:
    PlaceholderEditor (juce::AudioProcessor& processor, const juce::String& pluginName);

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    const juce::String title { "UI pending art direction" };
    const juce::String buildLine;
    const juce::Font titleFont { juce::FontOptions (18.0f) };
    const juce::Font smallFont { juce::FontOptions (13.0f) };

    // Laid out in resized() so paint() only draws (no allocation in paint).
    juce::GlyphArrangement titleGlyphs, buildGlyphs;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlaceholderEditor)
};

} // namespace lp
