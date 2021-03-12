#pragma once

#include "SpriteRenderer.h"

#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H

class TextRenderer : public Renderer
{
public:
	TextRenderer(GameObject* gameObject);

	void render();
private:
	Texture2D* renderTexture;
	static FT_Library ft_library;
	FT_Face face;

	static void init();
	static bool isInitialized;
};