#include <lp_core/PlaceholderEditor.h>
#include <lp_core/Version.h>

namespace lp
{
PlaceholderEditor::PlaceholderEditor (juce::AudioProcessor& p, const juce::String& pluginName)
    : juce::AudioProcessorEditor (p),
      buildLine (pluginName + "  -  v" + versionString() + "  -  build " + buildHash())
{
    setOpaque (true);
    setResizable (false, false);
    setSize (480, 270);
}

void PlaceholderEditor::resized()
{
    auto area = getLocalBounds().reduced (16).toFloat();
    const auto bottom = area.removeFromBottom (20.0f);

    titleGlyphs.clear();
    titleGlyphs.addFittedText (titleFont, title, area.getX(), area.getCentreY() - 14.0f,
                               area.getWidth(), 28.0f, juce::Justification::centred, 1);

    buildGlyphs.clear();
    buildGlyphs.addFittedText (smallFont, buildLine, bottom.getX(), bottom.getY(),
                               bottom.getWidth(), bottom.getHeight(), juce::Justification::centred, 1);
}

void PlaceholderEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour (0xff141518));

    g.setColour (juce::Colour (0xffd8d8d8));
    titleGlyphs.draw (g);

    g.setColour (juce::Colour (0xff8a8a8a));
    buildGlyphs.draw (g);
}

} // namespace lp
