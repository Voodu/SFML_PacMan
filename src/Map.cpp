#include "../include/Map.hpp"
#include "../include/Dot.hpp"
#include "../include/Wall.hpp"
#include "../include/Transform.hpp"
#include "../include/PacMan.hpp"
#include "../include/Fruit.hpp"
#include "../include/Boost.hpp"
#include "../include/Door.hpp"
#include "../include/Spawn.hpp"

Map::Map()
{
    idString = "Map";
    tag = "Map";
    transform = Transform(0, 0);
    readFile();
    transform.setHeight(charMap.size() * 20); //TODO: FIX that 20!!!
    transform.setWidth(charMap.size() > 0 ? charMap.front().size() * 20 : 0);
}

void Map::init()
{
    for (size_t row = 0; row < charMap.size(); row++)
    {
        for (size_t column = 0; column < charMap[row].size(); column++)
        {
            createEntity(row, column);
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

void Map::createEntity(size_t row, size_t column)
{
    const float dotScale = 0.25; //TODO move it higher
    Transform temp(0, 0, 20, 20);
    switch (charMap[row][column])
    {
        //TODO add spawnpoints variables
    case 'x':
        this->scene->addGameObject(new Wall(temp.moveTo(column * temp.getWidth(), row * temp.getHeight())));
        break;
    case 'P': //intentional lack of break!
        this->scene->addGameObject(new PacMan(temp.moveTo(column * temp.getWidth(), row * temp.getHeight())));
    case '.':
        this->scene->addGameObject(new Dot(Transform(column * temp.getWidth() + (temp.getWidth() - temp.getWidth() * dotScale) / 2, row * temp.getHeight() + (temp.getHeight() - temp.getHeight() * dotScale) / 2, temp.getWidth() * dotScale, temp.getHeight() * dotScale)));
        break;
    case '0':
        this->scene->addGameObject(new Boost(temp.moveTo(column * temp.getWidth(), row * temp.getHeight())));
        break;
    case 'F':
        this->scene->addGameObject(new Fruit(temp.moveTo(column * temp.getWidth(), row * temp.getHeight())));
        break;
    case 'D':
        this->scene->addGameObject(new Door(temp.moveTo(column * temp.getWidth(), row * temp.getHeight())));
        break;
    default:
        break;
    }
}

void Map::readFile()
{
    std::ifstream mapFile("map.txt", std::ifstream::in);
    std::string line;
    while (mapFile.good())
    {
        getline(mapFile, line);
        charMap.push_back(std::vector<char>());
        for (auto character : line)
        {
            charMap.back().push_back(character);
        }
    }
}