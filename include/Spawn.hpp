#ifndef SPAWN_HPP
#define SPAWN_HPP

#include "GameObject.hpp"

class Spawn : public GameObject
{
  public:
    Spawn(Transform transform, GameObject *(*ctor)(Transform), std::string tag);
    void init() override;
    void start() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;

    void respawn();

    GameObject *(*factory)(Transform);
};

#endif // !SPAWN_HPP