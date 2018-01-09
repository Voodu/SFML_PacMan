#include "../include/LifesText.hpp"

LifesText::LifesText(sf::Color color, Transform transform) : Text(transform)
{
    lifes = 3;
    idString = "LifesText";
    text.setString("Lifes: " + std::to_string(lifes));
}

LifesText::LifesText(Transform transform) : LifesText(sf::Color::White, transform)
{
}

void LifesText::parseMessage(std::string message)
{
    if (message == "LoseLife")
    {
        text.setString("Lifes: " + std::to_string(--lifes));
    }
}