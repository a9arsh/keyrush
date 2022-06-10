#include "character.h"

Character::Character(sf::Texture &texture)
{
    this->setTexture(texture);
}

void Character::animate(sf::Time &elapsed)
{
    sf::FloatRect hero_bounds = this->getGlobalBounds();
    // Check if object is not on the ground.
    if(hero_bounds.top < 575 - hero_bounds.height - floor * 75)
    {
        t += elapsed.asSeconds();
        if(t >= 0.1)
        {
            fall_velocity += gravity;
            this->move(0, fall_velocity * elapsed.asSeconds());
            t = 0;
        }
        this->move(0, this->fall_velocity * elapsed.asSeconds());
    }
    else
    {
        t = 0.1;
        fall_velocity = 0;
    }
}

void Character::moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key)
    {
        sf::FloatRect bounds = getGlobalBounds();
        if(key == sf::Keyboard::Up && !(bounds.top <= 0.0))
        {
            move(0, -speedy_ * elapsed.asSeconds());
        }
        else if(key == sf::Keyboard::Right && !(bounds.left >= 800 - bounds.width))
        {
            move(speedx_ * elapsed.asSeconds(), 0);
        }
        else if(key == sf::Keyboard::Down && !(bounds.top >= 575 - bounds.height))
        {
            move(0, speedy_ * elapsed.asSeconds());
        }
        else if(key == sf::Keyboard::Left && !(bounds.left <= 0.0))
        {
            move(-speedx_ * elapsed.asSeconds(), 0);
        }
    }
