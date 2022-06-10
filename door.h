#pragma once

#include <SFML/Graphics.hpp>

class Door : public sf::Sprite
{
public:
    bool open = false;

public:
    Door(sf::Texture &texture);

    void doorOpen();
};
