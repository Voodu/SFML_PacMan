#include "../include/Spawn.hpp"

Spawn::Spawn(Transform transform, std::string tag)
{
    this->transform = transform;
    this->tag = tag;
}

void Spawn::init()
{
}

void Spawn::update()
{
}

void Spawn::render()
{
}

void Spawn::onCollision(GameObject *other)
{
}

void Spawn::parseMessage(std::string message)
{
}
