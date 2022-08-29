#include "monster.h"

Monster::Monster(sf::Texture &texture, sf::FloatRect bounds_, int verticalspeed_,int horizontalspeed_, sf::Vector2f position)
{
    this->setTexture(texture);
    this->setScale(0.5, 0.5);
    this->setPosition(position);
    vspeed =verticalspeed_;
    hspeed=horizontalspeed_;
    bounds=bounds_;
    Initialposition=position;
}

void Monster::animate(sf::Time &elapsed)
{   sf::FloatRect mbounds = this->getGlobalBounds();
    if(mbounds.left <= bounds.left)
    {
        this->hspeed = std::abs(this->hspeed);
    }
    else if(mbounds.left+ mbounds.width >= bounds.left+bounds.width )
    {
        this->hspeed = -std::abs(this->hspeed);
    }
    if(mbounds.top <= bounds.top)
    {
        this->vspeed = std::abs(this->vspeed);
    }
    else if(mbounds.top+ mbounds.height >= bounds.top+bounds.height )
    {
        this->vspeed = -std::abs(this->vspeed);
    }


    this->move(hspeed * elapsed.asSeconds(),vspeed * elapsed.asSeconds());
}
