#ifndef DOT_HPP
#define DOT_HPP

#include "GameObject.hpp"

class Dot : public GameObject
{
  public:
    sf::Color color;
    sf::RectangleShape shape;
    Dot(sf::Color color, float size);
    Dot(sf::Color color, Transform transform);
    Dot(Transform transform);
    void init() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !DOT_HPP