#include "../include/Boost.hpp"

Boost::Boost(sf::Color color, Transform transform) : StaticObject(color, transform)
{
    tag = "Boost";
    framesLeft = 500;
    collected = false;
}

Boost::Boost(Transform transform) : Boost(sf::Color::White, transform)
{
}

void Boost::update()
{
    if (!collected)
    {
        return;
    }
    if (--framesLeft == 100)
    {
        scene->passMessages("Ghost", "BoostVanishing");
        return;
    }
    if (framesLeft <= 0)
    {
        scene->passMessages("Ghost", "BoostVanished");
        scene->passMessage("PacMan", "BoostVanished");
        scene->removeGameObject(this);
        return;
    }
}

void Boost::onCollision(GameObject *other)
{
    collected = true;
    hide();
}

void Boost::hide()
{
    transform = Transform();
    shape = sf::RectangleShape(sf::Vector2f(0, 0));
}