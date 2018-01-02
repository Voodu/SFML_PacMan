#include "../include/MovableObject.hpp"

MovableObject::MovableObject()
{
    tag = "MovableObject";
    dir = sf::Vector2f(0, 0);
    nextDir = dir;
}

void MovableObject::changeDir(unsigned int keyCode, size_t up, size_t down, size_t left, size_t right)
{
    if (keyCode == up)
        nextDir = sf::Vector2f(0, -1);
    else if(keyCode == down)
        nextDir = sf::Vector2f(0, 1);
    else if(keyCode == left)
        nextDir = sf::Vector2f(-1, 0);
    else if(keyCode == right)
        nextDir = sf::Vector2f(1, 0);
}

void MovableObject::move()
{
    Transform temp;
    if (!scene->isColliding(temp = transform.moveBy(nextDir.x, nextDir.y), string_set({tag})))
    {
        dir = nextDir;
        transform = temp;
    }
    else if (!scene->isColliding(temp = transform.moveBy(dir.x, dir.y), string_set({tag})))
    {
        transform = temp;
    }
}