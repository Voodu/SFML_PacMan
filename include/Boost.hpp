#ifndef BOOST_HPP
#define BOOST_HPP

#include "GameObject.hpp"

class Boost : public GameObject
{
  public:
    sf::Color color;
    sf::RectangleShape shape;
    Boost(sf::Color color, float size);
    Boost(sf::Color color, Transform transform);
    Boost(Transform transform);
    void init(Scene &scene) override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !BOOST_HPP