#include "../include/Blinky.hpp"

Blinky::Blinky(sf::Color color, Transform transform) : Ghost(color, transform)
{
    idString = "Blinky";
    directions.push(sf::Keyboard::Key::Up);
    directions.push(sf::Keyboard::Key::Right);
    directions.push(sf::Keyboard::Key::Down);
    directions.push(sf::Keyboard::Key::Left);
    directions.push(sf::Keyboard::Key::Down);
    directions.push(sf::Keyboard::Key::Right);
    directions.push(sf::Keyboard::Key::Down);
    directions.push(sf::Keyboard::Key::Right);
    directions.push(sf::Keyboard::Key::Up);
    directions.push(sf::Keyboard::Key::Right);
    directions.push(sf::Keyboard::Key::Down);
    directions.push(sf::Keyboard::Key::Right);
}

Blinky::Blinky(Transform transform) : Blinky(sf::Color::Red, transform)
{
}

int Blinky::getNextTurn()
{
    if (!directions.empty())
    {
        int t = directions.front();
        directions.pop();
        return t;
    }
    return -1;
}