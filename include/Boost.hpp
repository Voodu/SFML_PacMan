#ifndef BOOST_HPP
#define BOOST_HPP

#include "StaticObject.hpp"

class Boost : public StaticObject
{
  public:
    Boost(sf::Color color, Transform transform);
    Boost(Transform transform);
    void onCollision(GameObject *other) override;
};

#endif // !BOOST_HPP