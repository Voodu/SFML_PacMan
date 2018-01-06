#ifndef BLINKY_HPP
#define BLINKY_HPP
#include "Ghost.hpp"
#include <ctime>
#include <cstdlib>

class Blinky : public Ghost
{
    std::vector<int> directions;
  public:
    Blinky(sf::Color color, Transform transform);
    Blinky(Transform transform);
    int getNextTurn() override;
};

#endif // !BLINKY_HPP
