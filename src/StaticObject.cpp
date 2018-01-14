#include "../include/StaticObject.hpp"

StaticObject::StaticObject(sf::Color color, Transform transform) : GameObject(transform), color(color)
{
    physical = true;
    shape = sf::RectangleShape(sf::Vector2f(transform.rect.width, transform.rect.height));
    shape.setPosition(transform.rect.left, transform.rect.top);
    shape.setFillColor(color);
}

StaticObject::StaticObject(std::string txtFilename, Transform transform) : GameObject(transform)
{
    physical = true;
    if (!texture.loadFromFile(txtFilename))
    {
        throw "Cannot load" + txtFilename;
    }
    sf::FloatRect size;
    sprite.setTexture(texture);
    size = sprite.getLocalBounds();
    sprite.setScale(sf::Vector2f(20 / size.width, 20 / size.height));
    sprite.setPosition(transform.getX(), transform.getY());
}

StaticObject::StaticObject(Transform transform) : StaticObject(sf::Color::Black, transform)
{
}

void StaticObject::init()
{
}

void StaticObject::start()
{
}

void StaticObject::update()
{
}

void StaticObject::render()
{
    scene->draw(shape);
    scene->draw(sprite);
}

void StaticObject::onCollision(GameObject *other)
{
}

void StaticObject::parseMessage(std::string message)
{
}