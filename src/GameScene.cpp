#include "../include/GameScene.hpp"
#include "../include/Map.hpp"

GameScene::GameScene() : Scene()
{
    triggeringTags.insert("PacMan");
}

std::vector<GameObject *> GameScene::loadGameObjects()
{
    std::vector<GameObject *> ix;
    ix.push_back(new Map());
    return ix;
}