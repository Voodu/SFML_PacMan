#include "../include/Clyde.hpp"

Clyde::Clyde(Transform transform) : Ghost(transform, "sprites/Clyde.png")
{
    idString = "Clyde";
}

int Clyde::getNextTurn()
{
    return -1;
}

GameObject* Clyde::factory(Transform tr)
{
    return new Clyde(tr);
}