#include <lp_core/DevParamEditor.h>
#include <lp_core/Version.h>

namespace lp
{
namespace
{
constexpr int margin = 16;
constexpr int rowHeight = 32;
constexpr int nameWidth = 110;
constexpr int footerHeight = 24;
constexpr int editorWidth = 520;
} // namespace

DevParamEditor::DevParamEditor (juce::AudioProcessor& p, const juce::String& pluginName)
    : juce::AudioProcessorEditor (p)
{
    setOpaque (true);

    for (auto* base : p.getParameters())
    {
        auto* param = dynamic_cast<juce::RangedAudioParameter*> (base);
        if (param == nullptr)
            continue;

        auto row = std::make_unique<Row>();

        row->name.setText (param->getName (64), juce::dontSendNotification);
        row->name.setJustificationType (juce::Justification::centredLeft);
        addAndMakeVisible (row->name);

        row->slider.setSliderStyle (juce::Slider::LinearHorizontal);
        row->slider.setTextBoxStyle (juce::Slider::TextBoxRight, false, 90, rowHeight - 8);
        addAndMakeVisible (row->slider);

        // Binds slider <-> parameter (gestures, host automation, value text).
        row->attachment = std::make_unique<juce::SliderParameterAttachment> (*param, row->slider);

        rows.push_back (std::move (row));
    }

    buildLabel.setText (pluginName + "  -  v" + versionString() + "  -  build " + buildHash()
                            + "  -  dev controls",
                        juce::dontSendNotification);
    buildLabel.setJustificationType (juce::Justification::centred);
    buildLabel.setColour (juce::Label::textColourId, juce::Colour (0xff8a8a8a));
    addAndMakeVisible (buildLabel);

    setResizable (false, false);
    setSize (editorWidth, margin * 2 + static_cast<int> (rows.size()) * rowHeight + footerHeight);
}

DevParamEditor::~DevParamEditor()
{
    // Attachments must go before their sliders.
    for (auto& row : rows)
        row->attachment.reset();
}

void DevParamEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour (0xff141518));
}

void DevParamEditor::resized()
{
    auto area = getLocalBounds().reduced (margin);
    buildLabel.setBounds (area.removeFromBottom (footerHeight));

    for (auto& row : rows)
    {
        auto line = area.removeFromTop (rowHeight);
        row->name.setBounds (line.removeFromLeft (nameWidth));
        row->slider.setBounds (line);
    }
}

} // namespace lp
