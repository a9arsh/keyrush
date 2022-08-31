#pragma once

#include <SFML/Graphics.hpp>

class Switch : public sf::Sprite
{
public:
    bool on = false;
    int x_;
    int y_;
public:
    Switch(sf::Texture &texture);

    void switch_on();
};
