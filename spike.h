#pragma once
#include <SFML/Graphics.hpp>

class Spike: public sf::Sprite
{protected:
   sf::Vector2f InitialPosition;
public:
    Spike(sf::Texture &texture);

    void changePosition(const sf::Vector2f &pos);
};
