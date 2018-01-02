#ifndef PACMAN_HPP
#define PACMAN_HPP
#include "MovableObject.hpp"

typedef std::unordered_set<std::string> string_set;

class PacMan : public MovableObject
{
  public:
    sf::Color color;
    sf::RectangleShape shape;
    PacMan(sf::Color color, float size);
    PacMan(sf::Color color, Transform transform);
    PacMan(Transform transform);
    void init() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !PACMAN_HPP
