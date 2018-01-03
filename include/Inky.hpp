#ifndef INKY_HPP
#define INKY_HPP
#include "Ghost.hpp"

class Inky : public Ghost
{
  public:
    Inky(sf::Color color, Transform transform);
    Inky(Transform transform);
};

#endif // !INKY_HPP
