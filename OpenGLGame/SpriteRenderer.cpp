#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(GameObject* gameObject) : Renderer(gameObject)
{
}

void SpriteRenderer::render(const Matrix4x4& projection)
{
    Graphics* graphics = Graphics::getGraphics();
    this->getMaterial()->use();
    this->getMaterial()->getShader()->setMat4("projection", projection);
    //this->getMaterial()->getShader()->setVec3("textColor", 1, 1, 1);

    const Transform* transform = getGameObject()->getTransform();
    Vector3 position = transform->GetPosition();
    sprite->draw(position.x, position.y);
}

Sprite* SpriteRenderer::getSprite()
{
    return this->sprite;
}

void SpriteRenderer::setSprite(Sprite* sprite)
{
    this->sprite = sprite;
}