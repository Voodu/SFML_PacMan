#include "../include/Spawn.hpp"

Spawn::Spawn(Transform transform, std::function<GameObject *(Transform)> ctor, std::string idString) : GameObject(transform)
{
    this->factory = ctor;
    this->idString = idString;
}

void Spawn::init()
{
    respawn();
}

void Spawn::start()
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
    if (message == "Respawn")
    {
        respawn();
    }
}

void Spawn::respawn()
{
    scene->addGameObject(factory(transform));
}
