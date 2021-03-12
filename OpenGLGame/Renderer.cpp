#include "Renderer.h"

Renderer::Renderer(GameObject* gameObject) : Component(gameObject)
{

	Graphics* graphics = Graphics::getGraphics();
	graphics->addRenderer(this);
}

Renderer::~Renderer()
{
	Graphics* graphics = Graphics::getGraphics();
	graphics->removeRenderer(this);
}

Material* Renderer::getMaterial()
{
	return this->material;
}

void Renderer::setMaterial(Material* material)
{
	this->material = material;
}
