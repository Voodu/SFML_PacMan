#ifndef DOOR_HPP
#define DOOR_HPP
#include "GameObject.hpp"

class Door : public GameObject
{
  public:
    sf::Color color;
    sf::RectangleShape shape;
    Door(sf::Color color, float size);
    Door(sf::Color color, Transform transform);
    Door(Transform transform);
    void init(Scene &scene) override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !DOOR_HPP