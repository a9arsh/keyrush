#include "monster.h"

Monster::Monster(sf::Texture &texture)
{
    this->setTexture(texture);
    this->setScale(0.5, 0.5);
    this->setPosition(0, 575 - this->getGlobalBounds().height);
}

void Monster::animate(sf::Time &elapsed)
{
    sf::FloatRect mbounds = this->getGlobalBounds();
    if(mbounds.left <= 0.0)
    {
        this->speed = std::abs(this->speed);
    }
    else if(mbounds.left >= 800 - mbounds.width)
    {
        this->speed = -std::abs(this->speed);
    }
    this->move(speed * elapsed.asSeconds(), 0);
}
