#include "movingspike.h"


MovingSpike::MovingSpike(sf::Texture &texture):Spike(texture)
{}
void MovingSpike::animate(sf::Time &elapsed)
{
    sf::FloatRect mbounds = this->getGlobalBounds();
    if(mbounds.top <= InitialPosition.y-Range_)
    {
        this->Speed_ = std::abs(this->Speed_);
    }
    else if(mbounds.top+ mbounds.height >=Range_ + InitialPosition.y )
    {
        this->Speed_ = -std::abs(this->Speed_);
    }
    this->move(0,Speed_ * elapsed.asSeconds());
}
