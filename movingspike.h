#pragma once
#include "spike.h"
#include <SFML/Graphics.hpp>

class MovingSpike : public Spike
{
public:
    MovingSpike(sf::Texture &texture);
public:
   int Speed_=-20;
   int Range_=50;

void animate(sf::Time &elapsed);

};
