#include "../include/ScoreText.hpp"
#include "../include/MenuScene.hpp"
#include "../include/GameScene.hpp"

ScoreText::ScoreText(Transform transform, int score) : Text(transform), score(score)
{
    idString = "ScoreText";
    text.setString("Score: " + std::to_string(score));
}

void ScoreText::parseMessage(std::string message)
{
    if (message == "AddPoint")
    {
        text.setString("Score: " + std::to_string(++score));
        scene->passMessage("Map", "DotEaten");
        return;
    }
    if (message == "GameOver")
    {
        scene->changeScene(new MenuScene(score));
        return;
    }
    if (message == "GameWin")
    {
        scene->changeScene(new GameScene(score));
        return;
    }
}