#include "../include/Pinky.hpp"

Pinky::Pinky(sf::Color color, Transform transform) : Ghost(color, transform)
{
    idString = "Pinky";
}

Pinky::Pinky(Transform transform) : Pinky(sf::Color(255, 192, 203), transform)
{
}

void Pinky::init()
{
    Ghost::init();
    pacMan = static_cast<MovableObject *>(scene->findObjectByIdString("PacMan"));
}

int Pinky::getNextTurn()
{
    sf::Vector2f pacDir = !pacMan->isMoving() ? pacMan->getNextDir() : pacMan->getDir();

    if (pacDir.x > 0)
    {
        return sf::Keyboard::Key::Right;
    }
    else if (pacDir.x < 0)
    {
        return sf::Keyboard::Key::Left;
    }
    if (pacDir.y > 0)
    {
        return sf::Keyboard::Key::Down;
    }
    else if (pacDir.y < 0)
    {
        return sf::Keyboard::Key::Up;
    }

    return -1;
}