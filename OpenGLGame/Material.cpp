#include "Material.h"

void Material::use()
{
    shader->use();
}

Shader* Material::getShader() const
{
    return this->shader;
}

void Material::setShader(Shader* shader)
{
    this->shader = shader;
}

const glm::vec3 Material::getColor()
{
    return this->color;
}

void Material::setColor(int r, int g, int b)
{
    this->color[0] = r;
    this->color[1] = g;
    this->color[2] = b;
}
