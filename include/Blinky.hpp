#ifndef BLINKY_HPP
#define BLINKY_HPP
#include "Ghost.hpp"
#include <queue>

class Blinky : public Ghost
{
    std::queue<int> directions;
  public:
    Blinky(sf::Color color, Transform transform);
    Blinky(Transform transform);
    int getNextTurn() override;
};

#endif // !BLINKY_HPP
