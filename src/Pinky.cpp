#include "../include/Pinky.hpp"

Pinky::Pinky(Transform transform) : Ghost(transform, "sprites/ghost.png")
{
    idString = "Pinky";
}

void Pinky::start()
{
    Ghost::start();
    pacMan = static_cast<MovableObject *>(scene->findObjectByIdString("PacMan"));
}

int Pinky::getNextTurn()
{
    sf::Vector2f pacDir = !pacMan->isMoving() ? pacMan->getNextDir() : pacMan->getDir();

    if (pacDir.x > 0)
    {
        return sf::Keyboard::Key::Right;
    }
    if (pacDir.x < 0)
    {
        return sf::Keyboard::Key::Left;
    }
    if (pacDir.y > 0)
    {
        return sf::Keyboard::Key::Down;
    }
    if (pacDir.y < 0)
    {
        return sf::Keyboard::Key::Up;
    }

    return -1;
}

GameObject *Pinky::factory(Transform tr)
{
    return new Pinky(tr);
}