#pragma once

#include <list>

#include "ObjectDefines.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"


class Component;
class Transform;


class GameObject
{
public:
	GameObject();
	void addComponent(Component* component);
	void removeComponent(Component* commpoent);
	Transform* getTransform() const;
private:
	Transform* transform;
	std::list<Component*> components;
};


class Component
{
private:
	GameObject* gameObject;

public:
	Component(GameObject* gameObject);
	GameObject* getGameObject();
};


class Transform : public Component
{
	REGISTER_DERIVED_CLASS(Transform, Component)

	Transform(GameObject* gameObject);
	Transform(GameObject* gameObject, Vector3 position, Quaternion rotation, Vector3 scale);

	Vector3 GetPosition() const;
	void SetPosition(const Vector3& position);

	Quaternion GetRotation() const;
	void SetRotation(const Quaternion& rotation);

	Vector3 GetScale() const;
	void SetScale(const Vector3& scale);

	Transform* GetParent();

private:
	Vector3 position;
	Quaternion rotation;
	Vector3 scale;

	Matrix4x4 transformMatrix;

	Transform* parent;

	std::list<Transform> children;
};