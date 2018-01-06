#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "StaticObject.hpp"

class Fruit : public StaticObject
{
  public:
    Fruit(sf::Color color, Transform transform);
    Fruit(Transform transform);
    void onCollision(GameObject *other) override;
};

#endif // !FRUIT_HPP