#include "AudioSource.h"

AudioSource::AudioSource(GameObject* gameObject) : Component(gameObject)
{
	alGenSources(1, &this->sourceID);
}

AudioSource::AudioSource(GameObject* gameObject, AudioClip* clip) : Component(gameObject)
{
	alGenSources(1, &this->sourceID);
	this->clip = clip;
	alSourcei(this->sourceID, AL_BUFFER, this->clip->bufferID);
}

void AudioSource::Rewind()
{
	alSourceRewind(this->sourceID);
}

void AudioSource::Play()
{
	alSourcePlay(this->sourceID);
}

void AudioSource::Pause()
{
	alSourcePause(this->sourceID);
}

void AudioSource::Stop()
{
	alSourceStop(this->sourceID);
}

AudioSourceState AudioSource::getCurrentState()
{
	int state;
	alGetSourcei(this->sourceID, AL_SOURCE_STATE, &state);
	return (AudioSourceState)state;
}


float AudioSource::getPitch()
{
	float pitch = 0.0f;
	alGetSourcef(this->sourceID, AL_PITCH, &pitch);
	return pitch;
}

void AudioSource::setPitch(float pitch)
{
	alSourcef(this->sourceID, AL_PITCH, pitch);
}

float AudioSource::getGain()
{
	float gain = 0.0f;
	alGetSourcef(this->sourceID, AL_GAIN, &gain);
	return gain;
}

void AudioSource::setGain(float gain)
{
	alSourcef(this->sourceID, AL_GAIN, gain);
}
