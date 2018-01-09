#ifndef STATICOBJECT_HPP
#define STATICOBJECT_HPP
#include "GameObject.hpp"

class StaticObject : public GameObject
{
  public:
    sf::Color color;
    sf::RectangleShape shape;
    StaticObject(sf::Color color, Transform transform);
    StaticObject(Transform transform);
    void init() override;
    void start() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !STATICOBJECT_HPP