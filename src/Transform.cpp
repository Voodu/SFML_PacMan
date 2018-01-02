#include "../include/Transform.hpp"

Transform Transform::moveTo(float x, float y)
{
    Transform t(x, y, rect.width, rect.height);
    return t;
}

Transform Transform::moveBy(float x, float y)
{
    Transform t(rect.left + x, rect.top + y, rect.width, rect.height);
    return t;
}

bool Transform::collides(Transform other)
{
    return rect.intersects(other.rect);
}