#ifndef LIFESTEXT_HPP
#define LIFESTEXT_HPP

#include "Text.hpp"

class LifesText : public Text
{
  public:
    int lifes;
    LifesText(sf::Color color, Transform transformText);
    LifesText(Transform transformText);
    void parseMessage(std::string message) override;
};

#endif // !LIFESTEXT_HPP