#ifndef MAP_HPP
#define MAP_HPP
#include "GameObject.hpp"
#include <fstream>
#include <vector>

class Map : public GameObject
{
    std::vector< std::vector<char> > charMap;
  public:
    void init(Scene &scene) override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
    void readFile();
};

#endif // !MAP_HPP