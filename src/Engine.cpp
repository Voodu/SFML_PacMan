#include "../include/Engine.hpp"

Engine::Engine(sf::RenderWindow &window, Scene *startScene, size_t fps)
{
    this->window = &window;
    this->window->setFramerateLimit(fps);
    activeScene = startScene;
    activeScene->window = &window;
    activeScene->init();
}

void Engine::run()
{
    while (window->isOpen())
    {
        activeScene->act();
        if (activeScene->nextScene != nullptr)
        {
            changeScene();
        }
    }
}

void Engine::changeScene()
{
    Scene *temp = activeScene->nextScene;
    delete activeScene;
    activeScene = temp;
    activeScene->window = window;
    activeScene->init();
}

Engine::~Engine()
{
    delete activeScene;
}