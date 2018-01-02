#include "../include/Fruit.hpp"

Fruit::Fruit(sf::Color color, Transform transform) : color(color)
{
    physical = false;
    this->transform = transform;
    tag = "Fruit";
    shape = sf::RectangleShape(sf::Vector2f(transform.rect.width, transform.rect.height));
    shape.setPosition(transform.rect.left, transform.rect.top);
    shape.setFillColor(color);
}

Fruit::Fruit(sf::Color color, float size) : Fruit(color, Transform(0, 0, size, size))
{
}

Fruit::Fruit(Transform transform) : Fruit(sf::Color::Red, transform)
{
}

void Fruit::init(Scene &scene)
{
    this->scene = &scene;
}

void Fruit::update()
{
}

void Fruit::render()
{
    scene->draw(shape);
}

void Fruit::onCollision(GameObject *other)
{
}

void Fruit::parseMessage(std::string message)
{
}
