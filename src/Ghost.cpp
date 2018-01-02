#include "../include/Ghost.hpp"

Ghost::Ghost(sf::Color color, Transform transform) : MovableObject(),  color(color)
{
    physical = true;
    this->transform = transform;
    tag = "Ghost";
    shape = sf::RectangleShape(sf::Vector2f(transform.rect.width, transform.rect.height));
    shape.setFillColor(color);
}

Ghost::Ghost(sf::Color color, float size) : Ghost(color, Transform(0, 0, size, size))
{
}

void Ghost::init(Scene &scene)
{
    this->scene = &scene;
}

void Ghost::update()
{
    for (auto event : scene->events)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            //changeDir(event.key.code);
        }
    }

    //move();
}

void Ghost::render()
{
    shape.setPosition(transform.rect.left, transform.rect.top);
    scene->draw(shape);
}

void Ghost::onCollision(GameObject *other)
{
}

void Ghost::parseMessage(std::string message)
{
}