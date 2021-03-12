#include "AudioListener.h"

AudioListener::AudioListener(GameObject* gameObject) : Component(gameObject)
{
}

float AudioListener::getGain()
{
    float gain;
    alGetListenerf(AL_GAIN, &gain);
    return gain;
}

void AudioListener::setGain(float gain)
{
    alListenerf(AL_GAIN, gain);
}

void AudioListener::setPosition(float x, float y, float z) // доделать
{
}

void AudioListener::setVelocity(float x, float y, float z) // доделать
{
}

void AudioListener::setOrientation(float atX, float atY, float atZ, float upX, float upY, float upZ) // доделать
{
}
