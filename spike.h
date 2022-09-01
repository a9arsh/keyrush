#pragma once
#include <SFML/Graphics.hpp>

class Spike: public sf::Sprite
{
public:
    Spike(sf::Texture &texture);
    sf::Vector2f InitialPosition;
    void changePosition(sf::Vector2f pos);
};
