#ifndef GHOST_CPP
#define GHOST_CPP
#include "MovableObject.hpp"

typedef std::unordered_set<std::string> string_set;

class Ghost : public MovableObject
{
  public:
    sf::Color color;
    sf::RectangleShape shape;
    Ghost(sf::Color color, float size);
    Ghost(sf::Color color, Transform transform);
    void init(Scene &scene) override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};


#endif // !GHOST_CPP
