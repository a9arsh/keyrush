#include "monster.h"

Monster::Monster(sf::Texture &texture, sf::FloatRect bounds_, int speed_, sf::Vector2f position)
{
    this->setTexture(texture);
    this->setScale(0.5, 0.5);
    this->setPosition(position);
    speed =speed_;
    bounds=bounds_;
    Initialposition=position;
}

void Monster::animate(sf::Time &elapsed)
{   sf::FloatRect mbounds = this->getGlobalBounds();
    if(mbounds.left <= bounds.left)
    {
        this->speed = std::abs(this->speed);
    }
    else if(mbounds.left+ mbounds.width >= bounds.left+bounds.width )
    {
        this->speed = -std::abs(this->speed);
    }
    this->move(speed * elapsed.asSeconds(), 0);
}
