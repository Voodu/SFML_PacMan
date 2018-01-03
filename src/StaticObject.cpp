#include "../include/StaticObject.hpp"

StaticObject::StaticObject(sf::Color color, Transform transform) : color(color)
{
    physical = true;
    this->transform = transform;
    tag = "StaticObject";
    shape = sf::RectangleShape(sf::Vector2f(transform.rect.width, transform.rect.height));
    shape.setPosition(transform.rect.left, transform.rect.top);
    shape.setFillColor(color);
}

StaticObject::StaticObject(Transform transform) : StaticObject(sf::Color::Black, transform)
{
}

void StaticObject::init()
{
}

void StaticObject::update()
{
}

void StaticObject::render()
{
    scene->draw(shape);
}

void StaticObject::onCollision(GameObject *other)
{
}

void StaticObject::parseMessage(std::string message)
{
}