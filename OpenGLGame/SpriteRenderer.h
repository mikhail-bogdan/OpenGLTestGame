#pragma once

#include <memory>

#include "Graphics.h"
#include "Renderer.h"
#include "Sprite.h"

class SpriteRenderer : public Renderer {
protected:
	Sprite* sprite;
public:
	SpriteRenderer(GameObject* gameObject);

	void render(const Matrix4x4 &projection);

	Sprite* getSprite();
	void setSprite(Sprite* Sprite);
};