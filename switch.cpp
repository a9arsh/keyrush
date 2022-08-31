#include "switch.h"

Switch::Switch(sf::Texture &texture)
{
    this->setTexture(texture);
    x_=texture.getSize().x;
    y_=texture.getSize().y;
}

void Switch::switch_on()
{
    if(on == true)
    {

        this->setTextureRect(sf::IntRect(x_,0,-x_,y_));

    }
    else
    {   this->setTextureRect(sf::IntRect(0,0,x_,y_));
    }
}
