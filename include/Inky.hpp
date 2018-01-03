#ifndef INKY_HPP
#define INKY_HPP
#include "Ghost.hpp"

class Inky : public Ghost
{
  public:
    Inky(sf::Color color, Transform transform);
    Inky(Transform transform);
    void findRoute() = 0;
};

#endif // !INKY_HPP
