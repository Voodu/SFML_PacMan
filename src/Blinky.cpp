#include "../include/Blinky.hpp"

Blinky::Blinky(Transform transform) : Ghost(transform, "sprites/ghost1.png")
{
    idString = "Blinky";
    srand(time(NULL));
    directions.push_back(sf::Keyboard::Key::Up);
    directions.push_back(sf::Keyboard::Key::Down);
    directions.push_back(sf::Keyboard::Key::Left);
    directions.push_back(sf::Keyboard::Key::Right);
}

int Blinky::getNextTurn()
{
    return directions[rand()%directions.size()];
}

GameObject* Blinky::factory(Transform tr)
{
    return new Blinky(tr);
}