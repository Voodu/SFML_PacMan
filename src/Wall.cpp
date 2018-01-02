#include "../include/Wall.hpp"

Wall::Wall(sf::Color color, Transform transform) : color(color)
{
    physical = true;
    this->transform = transform;
    tag = "Wall";
    shape = sf::RectangleShape(sf::Vector2f(transform.rect.width, transform.rect.height));
    shape.setPosition(transform.rect.left, transform.rect.top);
    shape.setFillColor(color);
}

Wall::Wall(sf::Color color, float size) : Wall(color, Transform(0, 0, size, size))
{
}

Wall::Wall(Transform transform) : Wall(sf::Color::Blue, transform)
{
}

void Wall::init()
{
}

void Wall::update()
{
}

void Wall::render()
{
    scene->draw(shape);
}

void Wall::onCollision(GameObject *other)
{
}

void Wall::parseMessage(std::string message)
{
}