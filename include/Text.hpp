#ifndef TEXT_HPP
#define TEXT_HPP

#include "GameObject.hpp"

class Text : public GameObject
{
  public:
    sf::Font font;
    sf::Text text;
    Text(sf::Color color, Transform transform);
    Text(Transform transform);
    void init() override;
    void start() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !TEXT_HPP