#pragma once

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

#include "wav_util.h"

class AudioManager
{
private:
	static AudioManager* manager;
	ALCdevice* device;
	ALCcontext* context;
public:
	AudioManager();
	static void Init();
	void Update();
	static void DeInit();
	AudioManager* getAudioManager();
};