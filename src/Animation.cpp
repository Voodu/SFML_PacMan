#include "../include/Animation.hpp"

Animation::Animation(std::string txtFilepath) : currentSpriteIx(0), delay(10), counter(0)
{
    if (!texture.loadFromFile(txtFilepath))
    {
        throw "Cannot load" + txtFilepath;
    }
    sf::Sprite temp;
    sf::FloatRect size;
    temp.setTexture(texture);
    for (size_t i = 0; i < 8; ++i)
    {
        temp.setTextureRect(sf::IntRect((i % 2) * clipSize, (i / 2) * clipSize, clipSize, clipSize));
        size = temp.getLocalBounds();
        temp.setScale(sf::Vector2f(20 / size.width, 20 / size.height));
        clips.push_back(temp);
    }
}

void Animation::setPosition(float x, float y)
{
    clips[currentSpriteIx].setPosition(x, y);
}

size_t Animation::getSetIndex()
{
    return currentSpriteIx / 2;
}

void Animation::render(Scene *scene, Transform transform)
{
    if (counter++ >= delay)
    {
        counter = 0;
        currentSpriteIx += currentSpriteIx % 2 == 0 ? 1 : -1;
    }
    setPosition(transform.getX(), transform.getY());
    scene->draw(clips[currentSpriteIx]);
}

void Animation::changeSet(size_t setIx)
{
    currentSpriteIx = setIx * 2;
    std::cout << "Changing set\n";
    if (currentSpriteIx >= clips.size())
    {
        throw "Out of range";
    }
}
