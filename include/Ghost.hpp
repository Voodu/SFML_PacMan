#ifndef GHOST_CPP
#define GHOST_CPP
#include "MovableObject.hpp"

class Ghost : public MovableObject
{
  public:
    sf::Color color;
    sf::RectangleShape shape;
    Ghost(sf::Color color, Transform transform);
    virtual int getNextTurn() = 0;
    void init() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;

};

#endif // !GHOST_CPP
