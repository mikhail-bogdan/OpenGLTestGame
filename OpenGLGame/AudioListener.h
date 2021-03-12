#pragma once

#include <OpenAL/al.h>

#include "GameObject.h"

class AudioListener : public Component
{

public:
	AudioListener(GameObject* gameObject);

	float getGain();
	void setGain(float gain);

private:
	void setPosition(float x, float y, float z); // доделать
	void setVelocity(float x, float y, float z); // доделать
	void setOrientation(float atX, float atY, float atZ, float upX, float upY, float upZ); // доделать

};