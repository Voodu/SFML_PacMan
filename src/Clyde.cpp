#include "../include/Clyde.hpp"

Clyde::Clyde(Transform transform) : Ghost(transform, "sprites/ghost.png")
{
    idString = "Clyde";
}

int Clyde::getNextTurn()
{
    return -1;
}