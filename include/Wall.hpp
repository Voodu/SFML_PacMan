#ifndef WALL_HPP
#define WALL_HPP

#include "StaticObject.hpp"

class Wall : public StaticObject
{
  public:
    Wall(Transform transform);
};

#endif // !WALL_HPP