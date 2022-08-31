#include "character.h"

Character::Character(sf::Texture &texture)
{   txtwidth=texture.getSize().x/8;
    txtheight=texture.getSize().y/3;
    txtrow=2;
    txtcolumn=3;
    //txtrow and txtcolumn are always 1 less than the rows or columns of desired animation
    this->setTexture(texture);
    this->setScale(0.5, 0.5);
    this->setTextureRect(sf::IntRect(txtcolumn*txtwidth,txtrow*txtheight,txtwidth,txtheight));
    this->setPosition(800-this->getGlobalBounds().width, 575 - this->getGlobalBounds().height);
}

void Character::animate(sf::Time &elapsed)
{
    sf::FloatRect hero_bounds = this->getGlobalBounds();
    // Check if object is not on the ground.
    if(hero_bounds.top < 575 - hero_bounds.height - floor * 75 && onbrick==false)
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
    if(faceleft){
        s_=1;
        txtwidth=-abs(txtwidth);
    }
    if(!faceleft){
        s_=0;
        txtwidth=abs(txtwidth);

    }
    if(jump){
        txtrow=2;
        if(fall_velocity<speedy_)txtcolumn=4;
        else txtcolumn=5;
    }
     this->setTextureRect(sf::IntRect((txtcolumn+s_)*abs(txtwidth),txtrow*txtheight,txtwidth,txtheight));
}

void Character::moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key)
    {  t1+=elapsed.asSeconds();

       sf::FloatRect bounds = getGlobalBounds();
        if(key == sf::Keyboard::Up && !(bounds.top <= 0.0))
        {
            move(0, -speedy_ * elapsed.asSeconds());
            jump=true;
        }
        else if(key == sf::Keyboard::Right && !(bounds.left >= 800 - bounds.width))
        {
            move(speedx_ * elapsed.asSeconds(), 0);
            faceleft=false;
            if(!jump){
            if(t1>0.1){
                if(walk){
                    if (i<11)i++;else i=1;
                    t1=0;
                    if(i<=8){
                        txtrow=1;
                        if(txtcolumn<7)txtcolumn++;
                        else txtcolumn=0;
                   }
                    else{
                        txtrow=2;
                        if(txtcolumn<2)txtcolumn++;
                        else txtcolumn=0;

                    }
                }
                else{
                    t1=0;
                    txtrow=0;
                    if(txtcolumn<=6)txtcolumn++;
                    else txtcolumn=0;
                }
            }
            }
        }
        else if(key == sf::Keyboard::Down && !(bounds.top >= 575 - bounds.height))
        {
            move(0, speedy_ * elapsed.asSeconds());
        }
        else if(key == sf::Keyboard::Left && !(bounds.left <= 0.0))
        {
            move(-speedx_ * elapsed.asSeconds(), 0);
            faceleft=true;
            if(!jump){
            if(t1>0.1){
                if(walk){
                    if (i<11)i++;else i=1;
                    t1=0;
                    if(i<=8){
                        txtrow=1;
                        if(txtcolumn<7)txtcolumn++;
                        else txtcolumn=0;
                   }
                    else{
                        txtrow=2;
                        if(txtcolumn<2)txtcolumn++;
                        else txtcolumn=0;

                    }
                }
                else{
                    t1=0;
                    txtrow=0;
                    if(txtcolumn<=6)txtcolumn++;
                    else txtcolumn=0;
                }
            }


        }
        }
    }
void::Character::runOrWalk(){
    if(walk){
        walk=false;
        this->speedx_=400;}
    else if(!walk){
        walk=true;
        this->speedx_=100;}
}

void::Character::standStill(){
    txtrow=2;
    txtcolumn=3;
}
