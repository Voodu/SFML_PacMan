#include "../include/Text.hpp"

Text::Text(sf::Color color, Transform transform) : GameObject(transform)
{
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        throw "Cannot load font";
    }
    tag = "Text";
    layer = 999;
    score = 0;
    text.setFont(font);
    text.setCharacterSize(20); // in pixels, not points!
    text.setColor(color);
    text.setPosition(transform.getX(), transform.getY());
}

Text::Text(Transform transform) : Text(sf::Color::White, transform)
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
    if (message == "addPoint")
    {
        text.setString("Score: " + std::to_string(++score));
    }
}