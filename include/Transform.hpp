#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Transform
{

  public:
    Transform() : rect(){};
    Transform(float x, float y) : rect(x, y, 0, 0) {}
    Transform(float x, float y, float width, float height) : rect(x, y, width, height) {}
    sf::Rect<float> rect;

    Transform moveTo(float x, float y);
    Transform moveBy(float x, float y);
    bool collides(Transform other);
};

#endif // !TRANSFORM_HPP