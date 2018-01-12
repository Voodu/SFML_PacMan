#include "../include/MenuScene.hpp"

MenuScene::MenuScene(int score) : score(score)
{
}

std::vector<GameObject *> MenuScene::loadGameObjects()
{
    std::vector<GameObject *> ix;
    auto textStack = new Menu(Transform(), score);
    ix.push_back(textStack);
    return ix;
}