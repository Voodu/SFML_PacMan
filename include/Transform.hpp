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

    float getX() { return rect.left; }
    float getY() { return rect.top; }
    float getWidth() { return rect.width; }
    float getHeight() { return rect.height; }
    float getRightX() { return rect.left + rect.width; }
    float getBottomY() { return rect.top + rect.height; }
    void setX(float x) { rect.left = x; }
    void setY(float y) { rect.top = y; }
    void setWidth(float width) { rect.width = width; }
    void setHeight(float height) { rect.height = height; }
    Transform moveTo(float x, float y);
    Transform moveBy(float x, float y);
    bool collides(Transform other);
};

#endif // !TRANSFORM_HPP