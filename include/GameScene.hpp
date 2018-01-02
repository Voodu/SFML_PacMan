#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include "Scene.hpp"
#include "PacMan.hpp"
#include "Dot.hpp"

class GameScene : public Scene
{
  public:
    std::vector<GameObject *> loadGameObjects() override;
};

#endif // !GAMESCENE_HPP