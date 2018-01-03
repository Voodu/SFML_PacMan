#ifndef BLINKY_HPP
#define BLINKY_HPP
#include "Ghost.hpp"

class Blinky : public Ghost
{
  public:
    Blinky(sf::Color color, Transform transform);
    Blinky(Transform transform);
    void findRoute() override;
};

#endif // !BLINKY_HPP
