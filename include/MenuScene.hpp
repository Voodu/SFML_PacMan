#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include "Scene.hpp"
#include "Menu.hpp"

class MenuScene : public Scene
{
    int score;

  public:
    MenuScene(int score = 0);
    std::vector<GameObject *> loadGameObjects() override;
};

#endif // !MENUSCENE_HPP