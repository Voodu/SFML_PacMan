#ifndef SPAWN_HPP
#define SPAWN_HPP

#include "GameObject.hpp"

class Spawn : public GameObject
{
  public:
    Spawn(Transform transform, std::string tag);
    void init() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !SPAWN_HPP