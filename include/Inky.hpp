#ifndef INKY_HPP
#define INKY_HPP
#include "Ghost.hpp"

class Inky : public Ghost
{
  public:
    Inky(Transform transform);
    int getNextTurn() override;
    static GameObject *factory(Transform tr);
};

#endif // !INKY_HPP
