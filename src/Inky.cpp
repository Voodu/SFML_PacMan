#include "../include/Inky.hpp"

Inky::Inky(Transform transform) : Ghost(transform, "sprites/ghost3.png")
{
    idString = "Inky";
}

int Inky::getNextTurn()
{
    return -1;
}

GameObject* Inky::factory(Transform tr)
{
    return new Inky(tr);
}