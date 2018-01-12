#include "../include/Menu.hpp"
#include "../include/GameScene.hpp"

Menu::Menu(Transform transform, int score) : GameObject(transform), score(score)
{
    idString = "Menu";
}

void Menu::init()
{
    if (score > 0)
    {
        addTextLine("Game Over", 40);
        addTextLine("Your score: " + std::to_string(score), 30);
        addTextLine("", 30);
        addTextLine("Press Enter to play again", 30);
    }
    else
    {
        addTextLine("Pac Man", 50);
        addTextLine("Press Enter to play", 30);
    }
    addTextLine("", 30);
    addTextLine("Press Esc anytime to exit", 20);
}

void Menu::start()
{
}

void Menu::update()
{
    for (auto event : scene->events)
    {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Return)
        {
            scene->changeScene(new GameScene());
        }
    }
}

void Menu::render()
{
}

void Menu::onCollision(GameObject *other)
{
}

void Menu::parseMessage(std::string message)
{
}

void Menu::addTextLine(std::string line, size_t size)
{
    auto t = new Text(transform);
    t->text.setString(line);
    t->text.setCharacterSize(size);
    center(t->text);
    lines.push_back(t);
    scene->addGameObject(lines.back());
}

void Menu::center(sf::Text &text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
    if (lines.size() == 0)
    {
        text.setPosition(sf::Vector2f(560 / 2.0f, 620 / 2.0f));
    }
    else
    {
        sf::FloatRect lastRect = lines.back()->text.getGlobalBounds();
        text.setPosition(sf::Vector2f(560 / 2.0f, lastRect.top + 2 * text.getCharacterSize()));
    }
}