#ifndef GHOST_CPP
#define GHOST_CPP
#include "MovableObject.hpp"
#include "PacMan.hpp"
#include "Animation.hpp"

class Ghost : public MovableObject
{
    Animation animation;
    void setAnimation();

  public:
    Ghost(Transform transform, std::string spritesPath);
    virtual int getNextTurn() = 0;
    void init() override;
    void start() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !GHOST_CPP
