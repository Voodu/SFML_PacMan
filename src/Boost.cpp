#include "../include/Boost.hpp"

Boost::Boost(sf::Color color, Transform transform) : StaticObject(color, transform)
{
    tag = "Boost";
}

Boost::Boost(Transform transform) : Boost(sf::Color::White, transform)
{
}

void Boost::onCollision(GameObject *other)
{
    if (other->tag == "PacMan")
    {
        scene->removeGameObject(this);
    }
}