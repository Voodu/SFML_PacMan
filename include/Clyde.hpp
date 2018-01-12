#ifndef CLYDE_HPP
#define CLYDE_HPP
#include "Ghost.hpp"

class Clyde : public Ghost
{
  public:
    Clyde(Transform transform);
    int getNextTurn() override;
};

#endif // !CLYDE_HPP
