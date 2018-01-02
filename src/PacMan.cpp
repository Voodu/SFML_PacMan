#include "../include/PacMan.hpp"

PacMan::PacMan(sf::Color color, Transform transform) : MovableObject(),  color(color)
{
    physical = true;
    this->transform = transform;
    tag = "PacMan";
    shape = sf::RectangleShape(sf::Vector2f(transform.rect.width, transform.rect.height));
    shape.setFillColor(color);
}

PacMan::PacMan(sf::Color color, float size) : PacMan(color, Transform(0, 0, size, size))
{
}

void PacMan::init(Scene &scene)
{
    this->scene = &scene;
}

void PacMan::update()
{
    for (auto event : scene->events)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            changeDir(event.key.code);
        }
    }

    move();
}

void PacMan::render()
{
    shape.setPosition(transform.rect.left, transform.rect.top);
    scene->draw(shape);
}

void PacMan::onCollision(GameObject *other)
{
}

void PacMan::parseMessage(std::string message)
{
}