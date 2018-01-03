#ifndef CLYDE_HPP
#define CLYDE_HPP
#include "Ghost.hpp"

class Clyde : public Ghost
{
  public:
    Clyde(sf::Color color, Transform transform);
    Clyde(Transform transform);
};

#endif // !CLYDE_HPP
