#include "../include/Fruit.hpp"

Fruit::Fruit(sf::Color color, Transform transform) : StaticObject(color, transform)
{
    tag = "Fruit";
}

Fruit::Fruit(Transform transform) : Fruit(sf::Color::Red, transform)
{
}

void Fruit::onCollision(GameObject *other)
{
    if (other->tag == "PacMan")
    {
        scene->removeGameObject(this);
    }
}