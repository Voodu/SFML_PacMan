#include "../include/Ghost.hpp"

Ghost::Ghost(Transform transform, std::string spritesPath) : MovableObject(transform), animation(spritesPath), invincible(1)
{
    layer = 2;
    physical = true;
    tag = "Ghost";
    ignoredMoveCollisions.insert(tag);
    ignoredMoveCollisions.insert("Door");
    ignoredMoveCollisions.insert("Dot");
    ignoredMoveCollisions.insert("Boost");
    ignoredMoveCollisions.insert("Fruit");
    ignoredMoveCollisions.insert("PacMan");
}

void Ghost::init()
{
    MovableObject::init();
}

void Ghost::start()
{
    MovableObject::start();
}

void Ghost::update()
{
    if (!moves || nextDir == sf::Vector2f(0, 0))
    {
        changeDir(getNextTurn());
    }

    move();
    setAnimation();
}

void Ghost::setAnimation()
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

void Ghost::render()
{
    animation.render(scene, transform);
}

void Ghost::onCollision(GameObject *other)
{
    if (other->tag == "PacMan" && invincible < 1)
    {
        scene->removeGameObject(this);
        scene->passMessage(idString + "Spawn", "Respawn");
    }
}

void Ghost::parseMessage(std::string message)
{
    if (message == "PacManCaught")
    {
        scene->removeGameObject(this);
        scene->passMessage(idString + "Spawn", "Respawn");
    }
    else if (message == "PacManBoosted")
    {
        animation.changeTexture("sprites/dead.png");
        setSpeed(1);
        --invincible;
    }
    else if (message == "BoostVanishing" && invincible < 1)
    {
        animation.blink();
    }
    else if (message == "BoostVanished" && ++invincible > 0)
    {
        animation.changeTexture("sprites/" + idString + ".png");
        setSpeed(2);
        invincible = 1;
    }
    else
    {
        ++invincible;
    }
}