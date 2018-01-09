#include "../include/Text.hpp"

Text::Text(sf::Color color, Transform transform) : GameObject(transform)
{
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        throw "Cannot load font";
    }
    tag = "Text";
    layer = 999;
    text.setFont(font);
    text.setCharacterSize(15); // in pixels, not points!
    text.setColor(color);
    text.setPosition(transform.getX(), transform.getY());
}

Text::Text(Transform transform) : Text(sf::Color::White, transform)
{
}

void Text::start()
{
}

void Text::init()
{
}

void Text::update()
{
}

void Text::render()
{
    scene->draw(text);
}

void Text::onCollision(GameObject *other)
{
}

void Text::parseMessage(std::string message)
{
}