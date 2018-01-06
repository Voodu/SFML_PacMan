#include "../include/Inky.hpp"

Inky::Inky(sf::Color color, Transform transform) : Ghost(color, transform)
{
    idString = "Inky";
}

Inky::Inky(Transform transform) : Inky(sf::Color::Cyan, transform)
{
}

int Inky::getNextTurn()
{
    return -1;
}