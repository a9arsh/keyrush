#pragma once

#include <bullet.h>
#include <SFML/Graphics.hpp>


class Monster : public sf::Sprite
{
private:
    int vspeed;
    int hspeed;
    sf::FloatRect bounds;
    float atktime;
    bool atk=false;
public:
    Monster(sf::Texture &texture,  sf::FloatRect mbounds, int verticalspeed_,int horizontalspeed_,sf::Vector2f position);
    void animate(sf::Time &elapsed);
    bool attack(sf::Time &elapsed);
    void enableAttack();
};
