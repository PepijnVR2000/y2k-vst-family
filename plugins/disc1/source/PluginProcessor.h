#pragma once

#include "Disc1Params.h"
#include "Disc1Voice.h"

#include <juce_audio_processors/juce_audio_processors.h>

namespace disc1
{
class Disc1Processor final : public juce::AudioProcessor
{
public:
    Disc1Processor();
    ~Disc1Processor() override = default;

    // Bump when the saved state layout changes in a way that needs migration.
    static constexpr int stateVersion = 1;

    void prepareToPlay (double sampleRate, int maximumExpectedSamplesPerBlock) override;
    void releaseResources() override {}
    bool isBusesLayoutSupported (const BusesLayout&) const override;

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    using AudioProcessor::processBlock;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    const juce::String getName() const override { return LP_PLUGIN_NAME; }
    bool acceptsMidi() const override { return true; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect() const override { return false; }
    double getTailLengthSeconds() const override;

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram (int) override {}
    const juce::String getProgramName (int) override { return {}; }
    void changeProgramName (int, const juce::String&) override {}

    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    juce::AudioProcessorValueTreeState& getState() noexcept { return state; }

private:
    VoiceParams readParameters() const noexcept;
    void handleMidi (const juce::uint8* data, int numBytes) noexcept;
    void renderSegment (juce::AudioBuffer<float>&, int start, int end) noexcept;

    juce::AudioProcessorValueTreeState state;

    lp::params::ParamRef cutoff, resonance, attack, release, glide, level;

    Disc1Voice voice;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Disc1Processor)
};

} // namespace disc1
