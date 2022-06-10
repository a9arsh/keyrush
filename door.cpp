#include "door.h"

Door::Door(sf::Texture &texture)
{
    this->setTexture(texture);
    this->setTextureRect(sf::IntRect(0, 0, 100, 134));
}

void Door::doorOpen()
{
    if(open == true)
    {
        this->setTextureRect(sf::IntRect(100, 0, 100, 134));
    }
    else
    {
        this->setTextureRect(sf::IntRect(0, 0, 100, 134));
    }
}
