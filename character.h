#pragma once

#include <SFML/Graphics.hpp>

class Character : public sf::Sprite
{
public:
    int speedx_ = 200;
    int speedy_ = 200;
    float gravity = 10;
    float fall_velocity = 0;
    float t = 0;
    int floor = 0;

    int heart = 3;
public:
    Character(sf::Texture &texture);
    void animate(sf::Time &elapsed);
    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key);
};
