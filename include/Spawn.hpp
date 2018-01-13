#ifndef SPAWN_HPP
#define SPAWN_HPP

#include "GameObject.hpp"
#include <functional>

class Spawn : public GameObject
{
  public:
    Spawn(Transform transform, std::function<GameObject *(Transform)> ctor, std::string idString);
    void init() override;
    void start() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;

    void respawn();

    std::function<GameObject *(Transform)> factory;
};

#endif // !SPAWN_HPP