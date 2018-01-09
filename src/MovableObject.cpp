#include "../include/MovableObject.hpp"

MovableObject::MovableObject(Transform transform) : GameObject(transform)
{
    dir = sf::Vector2f(0, 0);
    nextDir = dir;
    speed = 4;
}

MovableObject::MovableObject() : MovableObject(Transform())
{
}

sf::Vector2f MovableObject::getDir()
{
    return dir;
}

sf::Vector2f MovableObject::getNextDir()
{
    return nextDir;
}

void MovableObject::changeDir(unsigned int keyCode, size_t up, size_t down, size_t left, size_t right)
{
    if (keyCode == up)
        nextDir = sf::Vector2f(0 * speed, -1 * speed);
    else if (keyCode == down)
        nextDir = sf::Vector2f(0 * speed, 1 * speed);
    else if (keyCode == left)
        nextDir = sf::Vector2f(-1 * speed, 0 * speed);
    else if (keyCode == right)
        nextDir = sf::Vector2f(1 * speed, 0 * speed);
}

void MovableObject::changeDir(sf::Vector2f dir)
{
    nextDir = dir;
}

void MovableObject::move()
{
    outOfBoundsTeleport();
    moves = true;
    Transform temp;
    if (nextDir != sf::Vector2f(0, 0) && !scene->isColliding(temp = transform.moveBy(nextDir.x, nextDir.y), ignoredMoveCollisions))
    {
        dir = nextDir;
        transform = temp;
        nextDir = sf::Vector2f(0, 0);
    }
    else if (dir != sf::Vector2f(0, 0) && !scene->isColliding(temp = transform.moveBy(dir.x, dir.y), ignoredMoveCollisions))
    {
        transform = temp;
    }
    else
    {
        moves = false;
    }
}

void MovableObject::outOfBoundsTeleport()
{
    if (transform.getX() >= mapPointer->transform.getRightX()) //went through right wall
    {
        transform.setX(mapPointer->transform.getX() - transform.getWidth() + speed);
    }
    else if (transform.getRightX() <= mapPointer->transform.getX()) //went through left wall
    {
        transform.setX(mapPointer->transform.getRightX() - speed);
    }
}

void MovableObject::init()
{
}

void MovableObject::start()
{
    // std::cout << "MovableStart1\n";
    mapPointer = scene->findObjectByIdString("Map");    
    // std::cout << "MovableStart2\n";
}