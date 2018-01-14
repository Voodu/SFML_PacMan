#include "../include/PacMan.hpp"

PacMan::PacMan(Transform transform) : MovableObject(transform), animation("sprites/pacman.png")
{
    physical = true;
    layer = 1;
    tag = idString = "PacMan";
    ignoredMoveCollisions.insert(tag);
    ignoredMoveCollisions.insert("Dot");
    ignoredMoveCollisions.insert("Fruit");
    ignoredMoveCollisions.insert("Boost");
    ignoredMoveCollisions.insert("Ghost");
}

void PacMan::init()
{
    MovableObject::init();
    scene->freezeUntil([](auto event) { return event.type == sf::Event::KeyPressed &&
                                               event.key.code == sf::Keyboard::Key::Return; });
}

void PacMan::start()
{
    MovableObject::start();
}

void PacMan::update()
{
    for (auto event : scene->events)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            changeDir(event.key.code);
        }
    }

    move();
    setAnimation();
}

void PacMan::setAnimation()
{
    sf::Vector2f t = getDir();
    size_t ix = animation.getSetIndex();
    if (t.x > 0 && ix != 0)
    {
        animation.changeSet(0);
    }
    else if (t.y < 0 && ix != 1)
    {
        animation.changeSet(1);
    }
    else if (t.x < 0 && ix != 2)
    {
        animation.changeSet(2);
    }
    else if (t.y > 0 && ix != 3)
    {
        animation.changeSet(3);
    }
}

void PacMan::render()
{
    animation.render(scene, transform);
}

void PacMan::onCollision(GameObject *other)
{
    if (other->tag == "Ghost" && static_cast<Ghost *>(other)->invincible > 0)
    {
        scene->passMessage("LifesText", "LoseLife");
        scene->removeGameObject(this);
        scene->passMessage(idString + "Spawn", "Respawn");
        scene->passMessages("Ghost", "PacManCaught");
        return;
    }

    if (other->tag == "Dot")
    {
        scene->passMessage("ScoreText", "AddPoint");
        return;
    }

    if (other->tag == "Boost")
    {
        scene->passMessages("Ghost", "PacManBoosted");
        return;
    }
}

void PacMan::parseMessage(std::string message)
{
    if (message == "BoostVanished")
    {
    }
}