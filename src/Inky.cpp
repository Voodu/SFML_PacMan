#include "../include/Inky.hpp"

Inky::Inky(Transform transform) : Ghost(transform, "sprites/ghost.png")
{
    idString = "Inky";
}

int Inky::getNextTurn()
{
    return -1;
}