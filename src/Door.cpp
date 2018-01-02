#include "../include/Door.hpp"

Door::Door(sf::Color color, Transform transform) : color(color)
{
    physical = true;
    this->transform = transform;
    tag = "Door";
    shape = sf::RectangleShape(sf::Vector2f(transform.rect.width, transform.rect.height));
    shape.setPosition(transform.rect.left, transform.rect.top);
    shape.setFillColor(color);
}

Door::Door(sf::Color color, float size) : Door(color, Transform(0, 0, size, size))
{
}

Door::Door(Transform transform) : Door(sf::Color::Magenta, transform)
{
}

void Door::init()
{
}

void Door::update()
{
}

void Door::render()
{
    scene->draw(shape);
}

void Door::onCollision(GameObject *other)
{
}

void Door::parseMessage(std::string message)
{
}