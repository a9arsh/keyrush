#pragma once

#include <SFML/Graphics.hpp>

class Monster : public sf::Sprite
{
public:
    int speed = 300;

public:
    Monster(sf::Texture &texture);

    void animate(sf::Time &elapsed);
};
