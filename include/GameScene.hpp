#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include "Scene.hpp"
#include "PacMan.hpp"
#include "Dot.hpp"

class GameScene : public Scene
{
    int score;
  public:
    GameScene(int score = 0);
    std::vector<GameObject *> loadGameObjects() override;
};

#endif // !GAMESCENE_HPP