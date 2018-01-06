#include "../include/Engine.hpp"
#include "../include/GameScene.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(560, 620), "PacMan");
    Engine engine(window, new GameScene());
    engine.run();

    return 0;
}
