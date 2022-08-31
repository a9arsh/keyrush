#pragma once

#include <SFML/Graphics.hpp>

class Character : public sf::Sprite
{
public:
    int speedx_ = 400;
    int speedy_ = 400;
    float gravity = 40;
    float fall_velocity = 0;
    float t = 0;
    float t1=0;
    int floor = 0;
    bool faceleft=false;
    int s_=false;
    int txtwidth;
    int txtheight;
    int txtcolumn;
    int txtrow;
    bool walk=false;
    bool jump=false;
    int i=1;
    int heart = 3;
    bool onbrick=false;

public:

    Character(sf::Texture &texture);
    void animate(sf::Time &elapsed);
    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key);
    void runOrWalk();
    void standStill();
};
