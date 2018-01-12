#ifndef TEXTSTACK_HPP
#define TEXTSTACK_HPP

#include "GameObject.hpp"
#include "Text.hpp"

class Menu : public GameObject
{
    std::vector<Text *> lines;
    void center(sf::Text &text);
    int score;

  public:
    Menu(Transform transform, int score = 0);
    void addTextLine(std::string line, size_t = 20);
    void init() override;
    void start() override;
    void update() override;
    void render() override;
    void onCollision(GameObject *other) override;
    void parseMessage(std::string message) override;
};

#endif // !TEXTSTACK_HPP