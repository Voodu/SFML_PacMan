#include "../include/GameScene.hpp"
#include "../include/Map.hpp"

std::vector<GameObject *> GameScene::loadGameObjects()
{
    std::vector<GameObject *> ix;
    ix.push_back(new Map());
    return ix;
}