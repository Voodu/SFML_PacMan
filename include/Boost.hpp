#ifndef BOOST_HPP
#define BOOST_HPP

#include "StaticObject.hpp"

class Boost : public StaticObject
{
    size_t framesLeft;
    bool collected;
    void hide();
  public:
    Boost(Transform transform);
    void onCollision(GameObject *other) override;
    void update() override;
};

#endif // !BOOST_HPP