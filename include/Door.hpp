#ifndef DOOR_HPP
#define DOOR_HPP
#include "StaticObject.hpp"

class Door : public StaticObject
{
  public:
    Door(Transform transform);
};

#endif // !DOOR_HPP