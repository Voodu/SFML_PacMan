#include "../include/Pinky.hpp"

Pinky::Pinky(sf::Color color, Transform transform) : Ghost(color, transform)
{
    idString = "Pinky";
}

Pinky::Pinky(Transform transform) : Pinky(sf::Color(255,192,203), transform)
{
}

int Pinky::getNextTurn()
{
    return -1;
}