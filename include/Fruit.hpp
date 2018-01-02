#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "GameObject.hpp"

class Fruit : public GameObject
{
  public:
    sf::Color color;
    sf::RectangleShape shape;
    Fruit(sf::Color color, float size);
    Fruit(sf::Color color, Transform transform);
    Fruit(Transform transform);
    void init() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !FRUIT_HPP