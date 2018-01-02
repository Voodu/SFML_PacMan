#include "../include/Map.hpp"
#include "../include/Dot.hpp"
#include "../include/Wall.hpp"
#include "../include/Transform.hpp"
#include "../include/PacMan.hpp"

#include <iostream>
#include <string>
using namespace std;

void Map::init(Scene &scene)
{
    this->scene = &scene;
    Transform t(0, 0, 20, 20);
    readFile();
    for (size_t row = 0; row < charMap.size(); row++)
    {
        for (size_t column = 0; column < charMap[row].size(); column++)
        {
            switch (charMap[row][column])
            {
            case 'x':
                this->scene->addGameObject(new Wall(t.moveTo(column * t.getWidth(), row * t.getHeight())));
                break;
            case '.':
                this->scene->addGameObject(new Dot(t.moveTo(column * t.getWidth(), row * t.getHeight())));
                break;
            case 'P':
                this->scene->addGameObject(new PacMan(t.moveTo(column * t.getWidth(), row * t.getHeight())));
                break;
            default:
                break;
            }
        }
    }
}

void Map::readFile()
{
    ifstream mapFile("map.txt", ifstream::in);
    string line;
    while (mapFile.good())
    {
        getline(mapFile, line);
        charMap.push_back(vector<char>());
        for (auto character : line)
        {
            charMap.back().push_back(character);
        }
    }
}

void Map::update()
{
}

void Map::render()
{
}

void Map::onCollision(GameObject *other)
{
}

void Map::parseMessage(std::string message)
{
}