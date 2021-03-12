#include "AudioClip.h"

AudioClip::AudioClip()
{
	alGenBuffers(1, &this->bufferID);
}

AudioClip::AudioClip(std::string path)
{
	alGenBuffers(1, &this->bufferID);
	Wave_Header header;
	Data_Chunk data;
	load_wav_file(path, &header, &data);
	alBufferData(this->bufferID, AL_FORMAT_STEREO8, data.samples, data.datasize, header.nSamplesPerSec);
}
