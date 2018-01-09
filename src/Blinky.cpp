#include "../include/Blinky.hpp"

Blinky::Blinky(sf::Color color, Transform transform) : Ghost(color, transform)
{
    idString = "Blinky";
    srand(time(NULL));
    directions.push_back(sf::Keyboard::Key::Up);
    directions.push_back(sf::Keyboard::Key::Down);
    directions.push_back(sf::Keyboard::Key::Left);
    directions.push_back(sf::Keyboard::Key::Right);
}

Blinky::Blinky(Transform transform) : Blinky(sf::Color::Red, transform)
{
}

int Blinky::getNextTurn()
{
    return directions[rand()%directions.size()];
}

GameObject* Blinky::factory(Transform tr)
{
    return new Blinky(tr);
}