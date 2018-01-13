#ifndef MAP_HPP
#define MAP_HPP
#include "GameObject.hpp"
#include "Dot.hpp"
#include "Wall.hpp"
#include "Transform.hpp"
#include "PacMan.hpp"
#include "Fruit.hpp"
#include "Boost.hpp"
#include "Door.hpp"
#include "Blinky.hpp"
#include "Pinky.hpp"
#include "Inky.hpp"
#include "Clyde.hpp"
#include "ScoreText.hpp"
#include "LifesText.hpp"
#include "Spawn.hpp"
#include "Ghost.hpp"
#include <fstream>
#include <vector>
#include <stack>
#include <string>

class Map : public GameObject
{
    int score;
    const int tileSize = 20;
    size_t dotsNumber = 0;
    std::vector<std::vector<char>> charMap;
    std::stack<Spawn *> ghostSpawns;
    void readFile();
    void createEntity(size_t row, size_t column);

  public:
    Map(int score = 0);
    void init() override;
    void start() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !MAP_HPP