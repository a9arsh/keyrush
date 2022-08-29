#pragma once

#include <SFML/Graphics.hpp>

class Monster : public sf::Sprite
{
public:
    int vspeed;
    int hspeed;
    sf::FloatRect bounds;
    sf::Vector2f Initialposition;
public:
    Monster(sf::Texture &texture,  sf::FloatRect mbounds, int verticalspeed_,int horizontalspeed_,sf::Vector2f position);

    void animate(sf::Time &elapsed);
};
