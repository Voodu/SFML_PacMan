#ifndef PACMAN_HPP
#define PACMAN_HPP
#include "MovableObject.hpp"
#include "Animation.hpp"

class PacMan : public MovableObject
{
    Animation animation;
    void setAnimation();

  public:
    int boosted; //TODO private
    PacMan(Transform transform);
    void init() override;
    void start() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;

    static GameObject *factory(Transform tr)
    {
        return new PacMan(tr);
    }
};

#endif // !PACMAN_HPP
