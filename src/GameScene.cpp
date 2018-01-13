#include "../include/GameScene.hpp"
#include "../include/Map.hpp"

GameScene::GameScene(int score) : Scene(), score(score)
{
    triggeringTags.insert("PacMan");
}

std::vector<GameObject *> GameScene::loadGameObjects()
{
    std::vector<GameObject *> ix;
    ix.push_back(new Map(score));
    return ix;
}