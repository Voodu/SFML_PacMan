#include "../include/Blinky.hpp"

Blinky::Blinky(sf::Color color, Transform transform) : Ghost(color, transform)
{
    idString = "Blinky";
}

Blinky::Blinky(Transform transform) : Blinky(sf::Color::White, transform)
{
}

void Blinky::init()
{
    Ghost::init();
}

void Blinky::update()
{
    
}

void Blinky::render()
{
    Ghost::render();
}

void Blinky::onCollision(GameObject *other)
{
    //Add code to add point on collecting dot
}

void Blinky::parseMessage(std::string message)
{
}