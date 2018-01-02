#include "../include/Dot.hpp"

Dot::Dot(sf::Color color, Transform transform) : color(color)
{
    physical = true;
    this->transform = transform;
    tag = "dot";
    shape = sf::RectangleShape(sf::Vector2f(transform.rect.width, transform.rect.height));
    shape.setPosition(transform.rect.left, transform.rect.top);
    shape.setFillColor(color);
}

Dot::Dot(sf::Color color, float size) : Dot(color, Transform(0, 0, size, size))
{
}

void Dot::init(Scene &scene)
{
    this->scene = &scene;
}

void Dot::update()
{
}

void Dot::render()
{
    scene->draw(shape);
}

void Dot::onCollision(GameObject *other)
{
}

void Dot::parseMessage(std::string message)
{
}
