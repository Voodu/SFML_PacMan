#ifndef PINKY_HPP
#define PINKY_HPP
#include "Ghost.hpp"

class Pinky : public Ghost
{
  public:
    MovableObject *pacMan;
    Pinky(Transform transform);
    int getNextTurn() override;
    void start() override;
    static GameObject *factory(Transform tr);
};

#endif // !PINKY_HPP
