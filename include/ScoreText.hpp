#ifndef SCORETEXT_HPP
#define SCORETEXT_HPP

#include "Text.hpp"

class ScoreText : public Text
{
  public:
    int score;
    ScoreText(sf::Color color, Transform transformText);
    ScoreText(Transform transformText);
    void parseMessage(std::string message) override;
};

#endif // !SCORETEXT_HPP