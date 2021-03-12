#include "TextRenderer.h"

FT_Library TextRenderer::ft_library;
bool TextRenderer::isInitialized = false;

TextRenderer::TextRenderer(GameObject* gameObject) : Renderer(gameObject)
{
	if (!TextRenderer::isInitialized) init();

	FT_New_Face(ft_library, "fonts/arial.ttf", 0, &face);
}

void TextRenderer::render()
{
}

void TextRenderer::init()
{
	FT_Init_FreeType(&ft_library);

}
