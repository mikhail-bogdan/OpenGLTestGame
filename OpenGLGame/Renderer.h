#pragma once

#include <memory>

#include "Graphics.h"
#include "GameObject.h"
#include "Material.h"

class Material;

class Renderer : public Component {
protected:
	Material* material;

public:
	Renderer(GameObject* gameObject);
	~Renderer();
	Material* getMaterial();
	void setMaterial(Material* material);
	virtual void render(const Matrix4x4 &projection) = 0;
};