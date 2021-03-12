#pragma once

#include <string>
#include <OpenAL/al.h>

#include "wav_util.h"

class AudioClip
{
private:
	ALuint bufferID;
public:
	AudioClip();
	AudioClip(std::string path);

	friend class AudioSource;
};