#ifndef WALL_HPP
#define WALL_HPP

#include "StaticObject.hpp"

class Wall : public StaticObject
{
  public:
    Wall(sf::Color color, Transform transform);
    Wall(Transform transform);
};

#endif // !WALL_HPP