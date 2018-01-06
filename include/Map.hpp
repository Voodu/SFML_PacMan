#ifndef MAP_HPP
#define MAP_HPP
#include "GameObject.hpp"
#include "Ghost.hpp"
#include <fstream>
#include <vector>
#include <stack>
#include <string>

class Map : public GameObject
{
    const int tileSize = 20;
    std::vector<std::vector<char>> charMap;
    std::stack<Ghost *> ghosts;
    void readFile();
    void createEntity(size_t row, size_t column);

  public:
    Map();
    void init() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !MAP_HPP