#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include "Scene.hpp"
#include "PacMan.hpp"
#include "Dot.hpp"

class MenuScene : public Scene
{
  public:
    std::vector<GameObject *> loadGameObjects() override;
};

#endif // !MENUSCENE_HPP