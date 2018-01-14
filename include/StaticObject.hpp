#ifndef STATICOBJECT_HPP
#define STATICOBJECT_HPP
#include "GameObject.hpp"

class StaticObject : public GameObject
{
    const int clipSize = 64;
  public:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Color color; //to remove
    sf::RectangleShape shape; //to remove
    StaticObject(sf::Color color, Transform transform);
    StaticObject(std::string txtFileName, Transform transform);
    StaticObject(Transform transform);
    void init() override;
    void start() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !STATICOBJECT_HPP