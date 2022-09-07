#pragma once
#include "spike.h"
#include <SFML/Graphics.hpp>

class MovingSpike : public Spike
{
public:
    MovingSpike(sf::Texture &texture);
    void animate(sf::Time &elapsed);
    void setSpeed(int &speed);
    void setRange(int &range);
private:
   int Speed_=-20;
   int Range_=50;



};
