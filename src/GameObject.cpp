#include "../include/GameObject.hpp"

GameObject::GameObject()
{

}

GameObject::GameObject(Transform transform)
{
    this->transform = transform;
}

size_t GameObject::counter = 0;