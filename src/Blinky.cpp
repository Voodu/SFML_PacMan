#include "../include/Blinky.hpp"

Blinky::Blinky(sf::Color color, Transform transform) : Ghost(color, transform)
{
    idString = "Blinky";
}

Blinky::Blinky(Transform transform) : Blinky(sf::Color::Red, transform)
{
}