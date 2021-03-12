#include "GameObject.h"

Component::Component(GameObject* gameObject)
{
    this->gameObject = gameObject;
}

GameObject* Component::getGameObject()
{
    return this->gameObject;
}

GameObject::GameObject()
{
    transform = new Transform(this);

}

void GameObject::addComponent(Component* component)
{
    this->components.push_back(component);
}

void GameObject::removeComponent(Component* commponent)
{
    this->components.remove(commponent);
}

Transform* GameObject::getTransform() const
{
    return transform;
}
