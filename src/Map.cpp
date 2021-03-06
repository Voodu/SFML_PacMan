#include "../include/Map.hpp"

Map::Map(int score) : score(score)
{
    idString = "Map";
    tag = "Map";
    transform = Transform(0, 0);
    ghostSpawns.push(new Spawn(Transform(0, 0), Blinky::factory, "BlinkySpawn"));
    ghostSpawns.push(new Spawn(Transform(0, 0), Pinky::factory, "PinkySpawn"));
    ghostSpawns.push(new Spawn(Transform(0, 0), Inky::factory, "InkySpawn"));
    ghostSpawns.push(new Spawn(Transform(0, 0), Clyde::factory, "ClydeSpawn"));
    readFile();
    transform.setHeight(charMap.size() * tileSize);
    transform.setWidth(charMap.size() > 0 ? charMap.front().size() * tileSize : 0);
}

void Map::init()
{
    for (size_t row = 0; row < charMap.size(); ++row)
    {
        for (size_t column = 0; column < charMap[row].size(); ++column)
        {
            createEntity(row, column);
        }
    }
}

void Map::start()
{
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
    if (message == "DotEaten")
    {
        if(--dotsNumber <= 0)
        {
            scene->passMessage("ScoreText", "GameWin");
        }
    }
}

void Map::createEntity(size_t row, size_t column)
{
    const float dotScale = 0.25; //TODO move it higher
    Transform temp(transform.getX(), transform.getY(), tileSize, tileSize);
    int xOffset = column * temp.getWidth();
    int yOffset = row * temp.getHeight();
    switch (charMap[row][column])
    {
    case 'x':
        this->scene->addGameObject(new Wall(temp.moveTo(xOffset, yOffset)));
        break;
    case 'P': //intentional lack of break!
        this->scene->addGameObject(new Spawn(temp.moveTo(xOffset, yOffset), PacMan::factory, "PacManSpawn"));
    case '.':
        this->scene->addGameObject(new Dot(Transform(xOffset + (temp.getWidth() - temp.getWidth() * dotScale) / 2, yOffset + (temp.getHeight() - temp.getHeight() * dotScale) / 2, temp.getWidth() * dotScale, temp.getHeight() * dotScale)));
        ++dotsNumber;
        break;
    case '0':
        this->scene->addGameObject(new Boost(temp.moveTo(xOffset, yOffset)));
        break;
    case 'F':
        this->scene->addGameObject(new Fruit(temp.moveTo(xOffset, yOffset)));
        break;
    case 'D':
        this->scene->addGameObject(new Door(temp.moveTo(xOffset, yOffset)));
        break;
    case 'S':
        this->scene->addGameObject(new Wall(temp.moveTo(xOffset, yOffset)));
        this->scene->addGameObject(new ScoreText(temp.moveTo(xOffset, yOffset), score));
        break;
    case 'L':
        this->scene->addGameObject(new Wall(temp.moveTo(xOffset, yOffset)));
        this->scene->addGameObject(new LifesText(temp.moveTo(xOffset, yOffset)));
        break;
    case 'G':
        if (!ghostSpawns.empty())
        {
            ghostSpawns.top()->transform = temp.moveTo(xOffset, yOffset);
            this->scene->addGameObject(ghostSpawns.top());
            ghostSpawns.pop();
        }
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
        mapFile >> line;
        charMap.push_back(std::vector<char>());
        for (auto character : line)
        {
            charMap.back().push_back(character);
        }
    }
}