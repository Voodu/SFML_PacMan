#ifndef MOVABLEOBJECT_HPP
#define MOVABLEOBJECT_HPP
#include "GameObject.hpp"

class MovableObject : public GameObject
{
  public:
    sf::Vector2f getDir();
    sf::Vector2f getNextDir();
    bool isMoving() { return moves; }

  protected:
    MovableObject();
    MovableObject(Transform transform);
    sf::Vector2f dir;
    sf::Vector2f nextDir;
    string_set ignoredMoveCollisions;
    GameObject *mapPointer;
    bool moves;
    int speed;

    void changeDir(unsigned int keyCode, size_t up = sf::Keyboard::Key::Up, size_t down = sf::Keyboard::Key::Down, size_t left = sf::Keyboard::Key::Left, size_t right = sf::Keyboard::Key::Right);
    void changeDir(sf::Vector2f dir);
    void move();
    void outOfBoundsTeleport();

    void init() override;
    void update() override = 0;
    void render() override = 0;
    void onCollision(GameObject *other) override = 0;
    void parseMessage(std::string message) override = 0;
};

#endif // !MOVABLEOBJECT_HPP