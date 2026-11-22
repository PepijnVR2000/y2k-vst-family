#include "PluginProcessor.h"

#include <lp_core/DevParamEditor.h>
#include <lp_core/PlaceholderEditor.h>

namespace disc1
{
Disc1Processor::Disc1Processor()
    : AudioProcessor (BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
      state (*this, nullptr, "Disc1State", createParameterLayout()),
      cutoff (state, ids::cutoff),
      resonance (state, ids::resonance),
      attack (state, ids::attack),
      release (state, ids::release),
      glide (state, ids::glide),
      level (state, ids::level)
{
}

bool Disc1Processor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    if (layouts.getMainInputChannelSet() != juce::AudioChannelSet::disabled())
        return false;

    const auto out = layouts.getMainOutputChannelSet();
    return out == juce::AudioChannelSet::mono() || out == juce::AudioChannelSet::stereo();
}

VoiceParams Disc1Processor::readParameters() const noexcept
{
    VoiceParams p;
    p.cutoffHz = cutoff.get();
    p.resonance = resonance.get();
    p.attackSec = attack.get();
    p.releaseSec = release.get();
    p.glideSec = glide.get();
    p.levelGain = lp::dsp::dbToGain (level.get());
    return p;
}

void Disc1Processor::prepareToPlay (double sampleRate, int)
{
    // Called again on every sample-rate / block-size change: fully re-prepare.
    // Nothing here depends on the maximum block size, so there is nothing to
    // (re)allocate.
    voice.prepare (sampleRate, readParameters());
}

double Disc1Processor::getTailLengthSeconds() const
{
    return static_cast<double> (release.get());
}

void Disc1Processor::handleMidi (const juce::uint8* data, int numBytes) noexcept
{
    // Parse raw bytes: constructing juce::MidiMessage could allocate for sysex.
    if (numBytes < 1)
        return;

    const int status = data[0] & 0xf0;
    const int d1 = numBytes > 1 ? data[1] : 0;
    const int d2 = numBytes > 2 ? data[2] : 0;

    if (status == 0x90 && d2 > 0)
        voice.noteOn (d1, static_cast<float> (d2) / 127.0f);
    else if (status == 0x80 || (status == 0x90 && d2 == 0))
        voice.noteOff (d1);
    else if (status == 0xb0 && d1 == 120) // all sound off
        voice.allSoundOff();
    else if (status == 0xb0 && d1 == 123) // all notes off
        voice.allNotesOff();
}

void Disc1Processor::renderSegment (juce::AudioBuffer<float>& buffer, int start, int end) noexcept
{
    if (end > start)
        voice.render (buffer.getWritePointer (0, start), end - start);
}

void Disc1Processor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midi)
{
    juce::ScopedNoDenormals noDenormals;

    const int numSamples = buffer.getNumSamples();
    buffer.clear();

    if (numSamples == 0 || buffer.getNumChannels() == 0)
        return;

    // Parameters are read once per host block; smoothing inside the voice is
    // per sample, so any block split renders the same signal.
    voice.setParameters (readParameters());

    // Sample-accurate MIDI: render up to each event, then apply it.
    int position = 0;
    for (const auto metadata : midi)
    {
        const int eventPosition = juce::jlimit (position, numSamples, metadata.samplePosition);
        renderSegment (buffer, position, eventPosition);
        position = eventPosition;
        handleMidi (metadata.data, metadata.numBytes);
    }
    renderSegment (buffer, position, numSamples);

    for (int ch = 1; ch < buffer.getNumChannels(); ++ch)
        buffer.copyFrom (ch, 0, buffer, 0, 0, numSamples);
}

juce::AudioProcessorEditor* Disc1Processor::createEditor()
{
#if LP_DEV_EDITOR
    return new lp::DevParamEditor (*this, LP_PLUGIN_NAME);
#else
    return new lp::PlaceholderEditor (*this, LP_PLUGIN_NAME);
#endif
}

void Disc1Processor::getStateInformation (juce::MemoryBlock& destData)
{
    auto tree = state.copyState();
    tree.setProperty ("stateVersion", stateVersion, nullptr);
    if (auto xml = tree.createXml())
        copyXmlToBinary (*xml, destData);
}

void Disc1Processor::setStateInformation (const void* data, int sizeInBytes)
{
    auto xml = getXmlFromBinary (data, sizeInBytes);
    if (xml == nullptr || ! xml->hasTagName (state.state.getType()))
        return; // unknown or corrupt state: keep current values

    state.replaceState (juce::ValueTree::fromXml (*xml));
}

} // namespace disc1

// Entry point used by the JUCE plugin wrappers.
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new disc1::Disc1Processor();
}
