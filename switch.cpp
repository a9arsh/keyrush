#include "switch.h"

Switch::Switch(sf::Texture &texture)
{
    this->setTexture(texture);
}

void Switch::switch_on()
{
    if(on == true)
    {
        this->setScale(-1, 1);
    }
    else
    {
        this->setScale(1, 1);
    }
}
