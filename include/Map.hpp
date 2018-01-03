#ifndef MAP_HPP
#define MAP_HPP
#include "GameObject.hpp"
#include <fstream>
#include <vector>

class Map : public GameObject
{
    std::vector<std::vector<char>> charMap;
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