#ifndef PINKY_HPP
#define PINKY_HPP
#include "Ghost.hpp"

class Pinky : public Ghost
{
  public:
    Pinky(sf::Color color, Transform transform);
    Pinky(Transform transform);
    int getNextTurn() override;
};

#endif // !PINKY_HPP
