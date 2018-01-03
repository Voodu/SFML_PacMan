#include "../include/Clyde.hpp"

Clyde::Clyde(sf::Color color, Transform transform) : Ghost(color, transform)
{
    idString = "Clyde";
}

Clyde::Clyde(Transform transform) : Clyde(sf::Color(255,127,80), transform)
{
}

void Clyde::findRoute()
{
    
}