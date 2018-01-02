#include "../include/GameScene.hpp"

std::vector<GameObject *> GameScene::loadGameObjects()
{
    std::vector<GameObject *> ix;
    ix.push_back(new PacMan(sf::Color::Green, 20));
    Transform obstacle(30, 60, 40, 20);
    ix.push_back(new Dot(sf::Color::White, obstacle));
    ix.push_back(new Dot(sf::Color::White, obstacle.moveBy(0, 40)));
    return ix;
}