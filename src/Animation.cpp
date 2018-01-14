#include "../include/Animation.hpp"

Animation::Animation(std::string txtFilepath) : currentSpriteIx(0), delay(10), counter(0), blinking(false)
{
    changeTexture(txtFilepath);
}

void Animation::blink()
{
    blinking = !blinking;
}

void Animation::changeTexture(std::string filepath)
{
    clips.clear();
    if (!texture.loadFromFile(filepath))
    {
        throw "Cannot load" + filepath;
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
    blinking = false;
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
        if (blinking)
        {
            if (clips[currentSpriteIx].getColor() == sf::Color::White)
                clips[currentSpriteIx].setColor(sf::Color::Black);
            else
                clips[currentSpriteIx].setColor(sf::Color::White);
        }
    }
    setPosition(transform.getX(), transform.getY());
    scene->draw(clips[currentSpriteIx]);
}

void Animation::changeSet(size_t setIx)
{
    currentSpriteIx = setIx * 2;
    if (currentSpriteIx >= clips.size())
    {
        throw "Out of range";
    }
}
