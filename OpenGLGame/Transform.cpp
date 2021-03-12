#include "GameObject.h"

Transform::Transform(GameObject* gameObject) : Component(gameObject)
{
    this->position = Vector3::zero;
    this->rotation = Quaternion::identity;
    this->scale = Vector3::one;
}


Transform::Transform(GameObject* gameObject, Vector3 position, Quaternion rotation, Vector3 scale) : Component(gameObject)
{
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
}

Transform::~Transform()
{
}

Vector3 Transform::GetPosition() const
{
    return this->position;
}

void Transform::SetPosition(const Vector3& position)
{
    this->position = position;
}

Quaternion Transform::GetRotation() const
{
    return this->rotation;
}

void Transform::SetRotation(const Quaternion& rotation)
{
    this->rotation = rotation;
}

Vector3 Transform::GetScale() const
{
    return this->scale;
}

void Transform::SetScale(const Vector3& scale)
{
    this->scale = scale;
}


Transform* Transform::GetParent()
{
    return this->parent;
}
