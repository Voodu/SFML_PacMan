#include "../include/Wall.hpp"

Wall::Wall(Transform transform) : StaticObject("sprites/Wall.png", transform)
{
    tag = "Wall";
}