#include "../include/Dot.hpp"

Dot::Dot(sf::Color color, Transform transform) : StaticObject(color, transform)
{
    tag = "Dot";
}

Dot::Dot(Transform transform) : Dot(sf::Color::Yellow, transform)
{
}

void Dot::onCollision(GameObject *other)
{
    if (other->tag == "PacMan")
    {
        scene->passMessage("Score", "addPoint");
        scene->removeGameObject(this);
    }
}
