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
    float t2=0;
    int s_=false;
    int txtwidth;
    int txtheight;
    int txtcolumn;
    int txtrow;
    int i=1;
    int heart = 3;
    bool onbrick=false;
    bool walk=false;
    bool jump=false;
    bool faceleft=false;
public:

    Character(sf::Texture &texture);
    void animate(sf::Time &elapsed);
    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key);
    void runOrWalk();
    void standStill();
    bool attack();
};
