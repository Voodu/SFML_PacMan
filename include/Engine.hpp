#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "Scene.hpp"

class Scene;

class Engine //mentally singleton...
{
  public:
    Engine(sf::RenderWindow &window, Scene *startScene, size_t fps = 60);
    void run();
    ~Engine();

  private:
    Scene *activeScene;
    sf::RenderWindow *window;
    void changeScene();
};

#endif // !ENGINE_HPP