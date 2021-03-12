#pragma once

#include <OpenAL/al.h>

#include "GameObject.h"
#include "AudioClip.h"

enum class AudioSourceState
{
	Initial = AL_INITIAL,
	Playing = AL_PLAYING,
	Paused = AL_PAUSED,
	Stopped = AL_STOPPED,

};

class AudioSource : public Component
{
private:
	ALuint sourceID;
	AudioClip* clip = nullptr;
public:
	AudioSource(GameObject* gameObject);
	AudioSource(GameObject* gameObject, AudioClip* clip);

	void Rewind();
	void Play();
	void Pause();
	void Stop();
	AudioSourceState getCurrentState();

	float getPitch();
	void setPitch(float pitch);
	float getGain();
	void setGain(float gain);



};