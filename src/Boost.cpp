#include "../include/Boost.hpp"

Boost::Boost(Transform transform) : StaticObject("sprites/Boost.png", transform)
{
    tag = "Boost";
    framesLeft = 500;
    collected = false;
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
    }
    else if (framesLeft <= 0)
    {
        scene->passMessages("Ghost", "BoostVanished");
        scene->passMessage("PacMan", "BoostVanished");
        scene->removeGameObject(this);
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
    sprite.setScale(sf::Vector2f(0, 0));
}