#include "../include/Door.hpp"

Door::Door(sf::Color color, Transform transform) : StaticObject(color, transform)
{
    tag = "Door";
}

Door::Door(Transform transform) : Door(sf::Color::Magenta, transform)
{
}