#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <switch.h>
#include <door.h>
#include <monster.h>
#include <coin.h>
#include <spike.h>
#include <movingspike.h>

void stage(int& stage, int& difficulty ,Switch* lever, sf::Sprite& brick,std::vector<sf::Sprite>& bricks,MovingSpike& spike,std::vector<MovingSpike>& spikes,
            Door* door,std::vector<Monster>& monsters, sf::Texture& txtmonst,Spike& localspike,std::vector<Spike>& localspikes ){
if (stage==2){
    // Switch
    lever->setPosition(650, 100+lever->getGlobalBounds().height);

    // Bricks
    bricks.clear();
    brick.setPosition(100, 550 - 130);
    bricks.emplace_back(brick);

    brick.setPosition(150, 550 - 2*130);
    bricks.emplace_back(brick);


    brick.setPosition(600, 180);
    bricks.emplace_back(brick);
    brick.setPosition(450, 180);
    bricks.emplace_back(brick);
    brick.setPosition(300, 180);
    bricks.emplace_back(brick);
    brick.setPosition(150, 180);
    bricks.emplace_back(brick);

    //standing spikes
    localspike.changePosition(sf::Vector2f(0,0));
    localspike.setScale(-0.05,0.05);
    localspikes.emplace_back(localspike);


    //moving spikes


    spikes.clear();
    spike.setScale(0.05,0.05);
    spike.changePosition(sf::Vector2f(200,600));
    spikes.emplace_back(spike);
    spike.changePosition(sf::Vector2f(225,600));
    spikes.emplace_back(spike);
    spike.changePosition(sf::Vector2f(250,600));
    spikes.emplace_back(spike);
    if(difficulty>2){
    spike.changePosition(sf::Vector2f(400,600));
    spikes.emplace_back(spike);
    spike.changePosition(sf::Vector2f(425,600));
    spikes.emplace_back(spike);
    spike.changePosition(sf::Vector2f(450,600));
    spikes.emplace_back(spike);

    spike.changePosition(sf::Vector2f(600,600));
    spikes.emplace_back(spike);
    spike.changePosition(sf::Vector2f(625,600));
    spikes.emplace_back(spike);
    spike.changePosition(sf::Vector2f(650,600));
    spikes.emplace_back(spike);

    spike.setScale(0.05,-0.05);
    spike.changePosition(sf::Vector2f(300,450));
    spikes.emplace_back(spike);
    spike.changePosition(sf::Vector2f(325,450));
    spikes.emplace_back(spike);
    spike.changePosition(sf::Vector2f(350,450));
    spikes.emplace_back(spike);


    spike.changePosition(sf::Vector2f(500,450));
    spikes.emplace_back(spike);
    spike.changePosition(sf::Vector2f(525,450));
    spikes.emplace_back(spike);
    spike.changePosition(sf::Vector2f(550,450));
    spikes.emplace_back(spike);
    }



    // Doors

    door->setPosition(700, 575 - door->getGlobalBounds().height);

    // Monster
    sf::Texture monster_t;
    monster_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/monster.png");
    Monster monster1(txtmonst,sf::FloatRect(0,180,800,420),50,150,sf::Vector2f(0, 525));
     Monster monster2(txtmonst,sf::FloatRect(150,0,600,0),0,100,sf::Vector2f(300, 130));
      Monster monster3(txtmonst,sf::FloatRect(150,0,600,0),0,-150,sf::Vector2f(700, 130));
       Monster monster4(txtmonst,sf::FloatRect(150,0,600,0),100,100,sf::Vector2f(0, 525));
    monsters.clear();
    monsters.emplace_back(monster1);
    monsters.emplace_back(monster2);
    if(difficulty>1){

        monsters.emplace_back(monster3);
        if(difficulty>2){
            //monsters[0].hspeed=200;
         monsters.emplace_back(monster4);
        }
    }
}
if (stage==1){
    // Switch
    lever->setPosition(25 + lever->getGlobalBounds().width, 575 - lever->getGlobalBounds().height);

    // Bricks
    bricks.clear();
    brick.setPosition(450, 550 - 130);
    bricks.emplace_back(brick);

    brick.setPosition(150, 550 - 2*130);
    bricks.emplace_back(brick);

    brick.setPosition(350, 550 - 3*130);
    bricks.emplace_back(brick);

    //standing spikes
    localspike.changePosition(sf::Vector2f(25,25));
    localspike.setScale(0.05,-0.05);
    localspikes.emplace_back(localspike);
    //movingspikes
    ;

    spikes.clear();
    spike.setScale(0.05,0.05);
    spike.changePosition(sf::Vector2f(150,600));
    spikes.emplace_back(spike);
    spike.changePosition(sf::Vector2f(135,600));

    spikes.emplace_back(spike);
    spike.changePosition(sf::Vector2f(165,600));
    spikes.emplace_back(spike);


    // Door
    door->setPosition(350, 550 - 3*130 - door->getGlobalBounds().height);

    // Monster
    sf::Texture monster_t;
    monster_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/monster.png");
    Monster monster1(txtmonst,sf::FloatRect(0,0,800,600),0,200,sf::Vector2f(0, 525));
    Monster monster2(txtmonst,sf::FloatRect(0,0,800,600),50,50,sf::Vector2f(0, 525));
    Monster monster3(txtmonst,sf::FloatRect(0,0,800,600),100,0,sf::Vector2f(400, 525));
    monsters.clear();
    monsters.emplace_back(monster1);


    if(difficulty>1){
        spike.changePosition(sf::Vector2f(450,420));
        spikes.emplace_back(spike);
        spike.changePosition(sf::Vector2f(575,420));
        spikes.emplace_back(spike);
        spike.changePosition(sf::Vector2f(150,290));

        spikes.emplace_back(spike);
        spike.changePosition(sf::Vector2f(275,290));

        spikes.emplace_back(spike);
        monsters[0].enableAttack();

        if(difficulty>2){
           // monsters[0].hspeed=400;
         monsters.emplace_back(monster3);
         monsters.emplace_back(monster2);
        }
    }
}
if(stage==3){//to be changed
    // Switch
    lever->setPosition(25 + lever->getGlobalBounds().width, 575 - lever->getGlobalBounds().height);

    // Bricks
    bricks.clear();
    brick.setPosition(450, 550 - 130);
    bricks.emplace_back(brick);

    brick.setPosition(150, 550 - 2*130);
    bricks.emplace_back(brick);

    brick.setPosition(180, 550);
    bricks.emplace_back(brick);

    brick.setPosition(350, 550 - 3*130);
    bricks.emplace_back(brick);

    // moving spikes

    spikes.clear();

    // Doors

    door->setPosition(350, 550 - 3*130 - door->getGlobalBounds().height);

    // Monster
    sf::Texture monster_t;
    monster_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/monster.png");
    Monster monster1(txtmonst,sf::FloatRect(0,0,800,600),0,200,sf::Vector2f(0, 525));

    monsters.clear();
    monsters.emplace_back(monster1);
}}

