#pragma once

#include <memory>

#include "Texture2D.h"

class Sprite
{
private:
	GLuint VAO, VBO;
	Texture2D* texture;

public:
	Sprite(Texture2D* texture);
	//~Sprite();
	void draw(float x, float y);
	Texture2D* getTexture();
	void setTexture(Texture2D* texture);
	int getWidth();
	int getHeight();
};