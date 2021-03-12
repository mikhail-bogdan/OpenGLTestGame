#pragma once

#include <string>

#include "Graphics.h"

#define PACK_PIXEL(r, g, b, a) (uint)a | (uint)b << 8 | (uint)g << 16 | (uint)r << 24
#define GET_R(x) x & 0xff00000
#define GET_G(x) x & 0x00ff0000
#define GET_B(x) x & 0x0000ff00
#define GET_A(x) x & 0x000000ff


typedef unsigned char byte;
typedef unsigned int uint;

enum TextureFormat
{
	RGB = GL_RGB,
	RGBA = GL_RGBA,
};

class Texture2D
{
public:
	Texture2D(int width, int height);
	Texture2D(std::string path);
	//~Texture2D();
	int getWidth();
	int getHeight();
	void resize(int width, int height);
	
	int getPixel(int x, int y);
	void setPixel(int x, int y, byte grayscale);
	void setPixel(int x, int y, byte grayscale, byte alpha);
	void setPixel(int x, int y, byte r, byte g, byte b);
	void setPixel(int x, int y, byte r, byte g, byte b, byte a);

	void bind();
	void unbind();
	~Texture2D();

private:
	void refreshTexture();


	bool isDirty = false;
	int width, height;
	TextureFormat format;
	uint** data;
	GLuint textureID;
};