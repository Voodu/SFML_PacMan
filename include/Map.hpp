#ifndef MAP_HPP
#define MAP_HPP
#include "GameObject.hpp"
#include <fstream>

class Map : public GameObject
{
  public:
    void init(Scene &scene) override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !MAP_HPP