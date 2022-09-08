#pragma once
#include <SFML/Graphics.hpp>

class bullet :public sf::Sprite
{
public:
    bullet(sf::Texture &texture, int verticalspeed_, int horizontalspeed_, const sf::Vector2f position);
    void moveBullet(sf::Time &elapsed);
private:
int vspeed;
int hspeed;

};


