#include "bullet.h"

bullet::bullet(sf::Texture &texture, int verticalspeed_, int horizontalspeed_, const sf::Vector2f position)
{   this->setPosition(position);
    this->setTexture(texture);
    this->setScale(0.01,0.01);
    vspeed=verticalspeed_;
    hspeed=horizontalspeed_;
}
void::bullet::moveBullet(sf::Time &elapsed){
    this->move(hspeed*elapsed.asSeconds(),vspeed*elapsed.asSeconds());
}
