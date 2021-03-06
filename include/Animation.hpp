#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scene.hpp"
#include "Transform.hpp"

class Animation
{
    const size_t clipSize = 64;
    sf::Texture texture;
    size_t currentSpriteIx;
    size_t delay;
    size_t counter;
    bool blinking;
    std::vector<sf::Sprite> clips;
    void setPosition(float x, float y);

  public:
    Animation(std::string txtFilepath);
    void blink();
    void changeSet(size_t setIx);
    void changeTexture(std::string filepath);
    size_t getSetIndex();
    void render(Scene *scene, Transform transform);
};

#endif // !ANIMATION_HPP