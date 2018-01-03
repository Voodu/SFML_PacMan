#ifndef DOT_HPP
#define DOT_HPP

#include "StaticObject.hpp"

class Dot : public StaticObject
{
  public:
    Dot(sf::Color color, Transform transform);
    Dot(Transform transform);
    void onCollision(GameObject *other) override;
};

#endif // !DOT_HPP