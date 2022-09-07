#include "spike.h"

Spike::Spike(sf::Texture &texture)
{
this->setTexture(texture);
}
void::Spike::changePosition(const sf::Vector2f &pos){
    this->InitialPosition=pos;
    this->setPosition(this->InitialPosition);
}
