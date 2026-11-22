#include <catch2/catch_session.hpp>

#include <juce_events/juce_events.h>

int main (int argc, char* argv[])
{
    // APVTS uses a Timer, which needs JUCE's message infrastructure to exist.
    const juce::ScopedJuceInitialiser_GUI juceInit;
    return Catch::Session().run (argc, argv);
}
