#include "../include/MovableObject.hpp"

MovableObject::MovableObject()
{
    tag = "MovableObject";
    dir = sf::Vector2f(0, 0);
    nextDir = dir;
}

void MovableObject::changeDir(unsigned int keyCode, size_t up, size_t down, size_t left, size_t right)
{
    int speed = 4;
    if (keyCode == up)
        nextDir = sf::Vector2f(0 * speed, -1 * speed);
    else if (keyCode == down)
        nextDir = sf::Vector2f(0 * speed, 1 * speed);
    else if (keyCode == left)
        nextDir = sf::Vector2f(-1 * speed, 0 * speed);
    else if (keyCode == right)
        nextDir = sf::Vector2f(1 * speed, 0 * speed);
}

void MovableObject::move()
{
    Transform temp;
    if (!scene->isColliding(temp = transform.moveBy(nextDir.x, nextDir.y), ignoredMoveCollisions))
    {
        dir = nextDir;
        transform = temp;
    }
    else if (!scene->isColliding(temp = transform.moveBy(dir.x, dir.y), ignoredMoveCollisions))
    {
        transform = temp;
    }

    outOfBoundsTeleport();
}

void MovableObject::outOfBoundsTeleport()
{
    if (transform.getX() > mapPointer->transform.getRightX())
    {
        transform.setX(mapPointer->transform.getX() - transform.getWidth());
    }
    else if (transform.getRightX() < mapPointer->transform.getX())
    {
        transform.setX(mapPointer->transform.getRightX());
    }
}

void MovableObject::init()
{
    mapPointer = scene->findObjectByIdString("Map");
}