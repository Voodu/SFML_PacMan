#ifndef BLINKY_HPP
#define BLINKY_HPP
#include "Ghost.hpp"
#include <ctime>
#include <cstdlib>

class Blinky : public Ghost
{
    std::vector<int> directions;
  public:
    Blinky(Transform transform);
    int getNextTurn() override;
    static GameObject* factory(Transform tr);
};

#endif // !BLINKY_HPP
