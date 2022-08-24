#pragma once

#include <SFML/Graphics.hpp>

class Monster : public sf::Sprite
{
public:
    int speed;
    sf::FloatRect bounds;
    sf::Vector2f Initialposition;
public:
    Monster(sf::Texture &texture,  sf::FloatRect mbounds, int speed_,sf::Vector2f position);

    void animate(sf::Time &elapsed);
};
