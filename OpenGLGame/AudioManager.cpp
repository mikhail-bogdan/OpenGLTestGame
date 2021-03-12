#include "AudioManager.h"

AudioManager* AudioManager::manager = nullptr;

AudioManager::AudioManager()
{
    device = alcOpenDevice(alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER));
    context = alcCreateContext(device, NULL);
    alcMakeContextCurrent(context);
}

void AudioManager::Init()
{
    AudioManager::manager = new AudioManager();
}

void AudioManager::Update()
{

}

void AudioManager::DeInit()
{
    delete AudioManager::manager;
}

AudioManager* AudioManager::getAudioManager()
{
    return AudioManager::manager;
}
