#include "../include/ScoreText.hpp"

ScoreText::ScoreText(sf::Color color, Transform transform) : Text(transform)
{
    score = 0;
    idString = "ScoreText";
    text.setString("Score: " + std::to_string(score));
}

ScoreText::ScoreText(Transform transform) : ScoreText(sf::Color::White, transform)
{
}

void ScoreText::parseMessage(std::string message)
{
    if (message == "AddPoint")
    {
        text.setString("Score: " + std::to_string(++score));
    }
}