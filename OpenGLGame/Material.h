#pragma once

#include <memory>

#include "Shader.h"

class Shader;

class Material {
private:
	glm::vec3 color;
	Shader* shader;
public:
	void use();
	Shader* getShader() const;
	void setShader(Shader* shader);
	const glm::vec3 getColor();
	void setColor(int r, int g, int b);
};