#include "../include/Boost.hpp"

Boost::Boost(sf::Color color, Transform transform) : color(color)
{
    physical = false;
    this->transform = transform;
    tag = "Boost";
    shape = sf::RectangleShape(sf::Vector2f(transform.rect.width, transform.rect.height));
    shape.setPosition(transform.rect.left, transform.rect.top);
    shape.setFillColor(color);
}

Boost::Boost(sf::Color color, float size) : Boost(color, Transform(0, 0, size, size))
{
}

Boost::Boost(Transform transform) : Boost(sf::Color::White, transform)
{
}

void Boost::init(Scene &scene)
{
    this->scene = &scene;
}

void Boost::update()
{
}

void Boost::render()
{
    scene->draw(shape);
}

void Boost::onCollision(GameObject *other)
{
}

void Boost::parseMessage(std::string message)
{
}
