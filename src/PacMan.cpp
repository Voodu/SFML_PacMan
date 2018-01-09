#include "../include/PacMan.hpp"
#include "../include/MenuScene.hpp"

PacMan::PacMan(sf::Color color, Transform transform) : MovableObject(transform),  color(color)
{
    physical = true;
    layer = 1;
    tag = "PacMan";
    idString = "PacMan";
    shape = sf::RectangleShape(sf::Vector2f(transform.rect.width, transform.rect.height));
    shape.setFillColor(color);
    ignoredMoveCollisions.insert(tag);
    ignoredMoveCollisions.insert("Dot");
    ignoredMoveCollisions.insert("Fruit");
    ignoredMoveCollisions.insert("Boost");
    ignoredMoveCollisions.insert("Ghost");
}

PacMan::PacMan(Transform transform) : PacMan(sf::Color::Green, transform)
{
}

void PacMan::init()
{
    MovableObject::init();
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
}

void PacMan::render()
{
    shape.setPosition(transform.rect.left, transform.rect.top);
    scene->draw(shape);
}

void PacMan::onCollision(GameObject *other)
{
    // if (other->tag == "Ghost")
    // {
    //     scene->passMessage("LifesText", "loseLife");
    //     scene->passMessage("Blinky", "respawn");
    //     scene->passMessage("Inky", "respawn");
    //     scene->passMessage("Pinky", "respawn");
    //     scene->passMessage("Clyde", "respawn");
    //     // respawn();
    //     return;
    // }

    // if (other->tag == "Dot")
    // {
    //     scene->passMessage("ScoreText", "addPoint");
    //     return;
    // }
}

void PacMan::parseMessage(std::string message)
{
}