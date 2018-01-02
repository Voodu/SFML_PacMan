#ifndef WALL_HPP
#define WALL_HPP
#include "GameObject.hpp"

class Wall : public GameObject
{
  public:
    sf::Color color;
    sf::RectangleShape shape;
    Wall(sf::Color color, float size);
    Wall(sf::Color color, Transform transform);
    Wall(Transform transform);
    void init(Scene &scene) override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !WALL_HPP