#include "../include/Door.hpp"

Door::Door(Transform transform) : StaticObject("sprites/Door.png", transform)
{
    tag = "Door";
}