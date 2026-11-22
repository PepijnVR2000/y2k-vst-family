#pragma once

// Development-only editor: one plain horizontal slider per host parameter,
// plus the plugin name, version and build hash at the bottom.
//
// Deliberately NOT a design (see docs/design/GUIDELINES.md for the real UI).
// It exists so the user can turn parameters in FL Studio and test state
// save/restore, glide time and the filter before the real panel exists.
// Enabled with the CMake option LP_DEV_EDITOR; off, plugins fall back to
// PlaceholderEditor.

#include <juce_audio_processors/juce_audio_processors.h>

#include <memory>
#include <vector>

namespace lp
{
class DevParamEditor final : public juce::AudioProcessorEditor
{
public:
    DevParamEditor (juce::AudioProcessor& processor, const juce::String& pluginName);
    ~DevParamEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    struct Row
    {
        juce::Label name;
        juce::Slider slider;
        std::unique_ptr<juce::SliderParameterAttachment> attachment;
    };

    std::vector<std::unique_ptr<Row>> rows;
    juce::Label buildLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DevParamEditor)
};

} // namespace lp
