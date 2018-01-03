#ifndef BLINKY_HPP
#define BLINKY_HPP
#include "Ghost.hpp"

typedef std::unordered_set<std::string> string_set;

class Blinky : public Ghost
{
  public:
    sf::Color color;
    sf::RectangleShape shape;
    Blinky(sf::Color color, Transform transform);
    Blinky(Transform transform);
    void init() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !BLINKY_HPP
