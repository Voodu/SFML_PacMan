#ifndef MOVABLEOBJECT_HPP
#define MOVABLEOBJECT_HPP
#include "GameObject.hpp"

class MovableObject : public GameObject
{
  protected:
    MovableObject();
    sf::Vector2f dir;
    sf::Vector2f nextDir;
    string_set ignoredMoveCollisions; 
    GameObject* mapPointer;
    void init() override = 0;
    void update() override = 0;
    void render() override = 0;
    void onCollision(GameObject *other) override = 0;
    void parseMessage(std::string message) override = 0;
    void changeDir(unsigned int keyCode, size_t up = sf::Keyboard::Key::Up, size_t down = sf::Keyboard::Key::Down, size_t left = sf::Keyboard::Key::Left, size_t right = sf::Keyboard::Key::Right);
    void move();
    void outOfBoundsTeleport();
};

#endif // !MOVABLEOBJECT_HPP