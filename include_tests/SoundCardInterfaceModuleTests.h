#ifndef SOUND_CARD_INTERFACE_MODULE_TESTS
#define SOUND_CARD_INTERFACE_MODULE_TESTS

#include "doctest.h"
#include "SoundCardInterfaceModule.h"

TEST_CASE("Sound Card Interface Module Test")
{

    double dSampleRate = 44100;
    double dChunkSize = 512;
    unsigned uNumChannels = 2;
    std::vector<uint8_t> vu8SourceIdentifier = {0, 0};
    unsigned uBufferSize = 10;

    SoundCardInterfaceModule soundCardInterfaceModule(dSampleRate, dChunkSize, uNumChannels, vu8SourceIdentifier, uBufferSize);
    soundCardInterfaceModule.SetTestMode(true);

    SUBCASE("Constructor test")
    {
        CHECK(soundCardInterfaceModule.GetModuleType() == "SoundCardInterfaceModule");
    }
}

#endif
