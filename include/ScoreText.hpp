#ifndef SCORETEXT_HPP
#define SCORETEXT_HPP

#include "Text.hpp"

class ScoreText : public Text
{
  public:
    int score;
    ScoreText(Transform transformText, int score = 0);
    void parseMessage(std::string message) override;
};

#endif // !SCORETEXT_HPP