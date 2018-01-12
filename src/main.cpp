#include "../include/Engine.hpp"
#include "../include/MenuScene.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(560, 620), "PacMan");
    Engine engine(window, new MenuScene());
    engine.run();

    return 0;
}
