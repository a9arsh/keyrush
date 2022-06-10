#pragma once

#include <SFML/Graphics.hpp>

class Switch : public sf::Sprite
{
public:
    bool on = false;

public:
    Switch(sf::Texture &texture);

    void switch_on();
};
