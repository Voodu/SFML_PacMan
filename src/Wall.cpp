#include "../include/Wall.hpp"

Wall::Wall(sf::Color color, Transform transform) : StaticObject(color, transform)
{
    tag = "Wall";
}

Wall::Wall(Transform transform) : Wall(sf::Color::Blue, transform)
{
}