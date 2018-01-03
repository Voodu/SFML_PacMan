#include "../include/Dot.hpp"

Dot::Dot(sf::Color color, Transform transform) : color(color)
{
    physical = true;
    this->transform = transform;
    tag = "Dot";
    shape = sf::RectangleShape(sf::Vector2f(transform.rect.width, transform.rect.height));
    shape.setPosition(transform.rect.left, transform.rect.top);
    shape.setFillColor(color);
}

Dot::Dot(sf::Color color, float size) : Dot(color, Transform(0, 0, size, size))
{
}

Dot::Dot(Transform transform) : Dot(sf::Color::Yellow, transform)
{
}

void Dot::init()
{
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
    if (other->tag == "PacMan")
    {
        scene->removeGameObject(this);
    }
}

void Dot::parseMessage(std::string message)
{
}
