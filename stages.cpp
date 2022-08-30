#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <switch.h>
#include <door.h>
#include <monster.h>
#include <coin.h>
#include <spike.h>
#include <movingspike.h>

void stage(int stage, int difficulty ,Switch* lever, sf::Sprite& brick,std::vector<sf::Sprite>& bricks,MovingSpike& spike,std::vector<MovingSpike>& spikes,
            Door* door,std::vector<Monster>& monsters, sf::Texture& txtmonst){
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

    //spikes


    spikes.clear();
    spike.setScale(0.05,0.05);
    spike.InitialPosition=sf::Vector2f(150,600);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(135,600);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(165,600);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);

    // Doors

    door->setPosition(700, 575 - door->getGlobalBounds().height);

    // Monster
    sf::Texture monster_t;
    monster_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/monster.png");
    Monster monster1(txtmonst,sf::FloatRect(0,180,800,420),50,150,sf::Vector2f(0, 525));
     Monster monster2(txtmonst,sf::FloatRect(150,0,600,0),0,100,sf::Vector2f(300, 130));
    monsters.clear();
    monsters.emplace_back(monster1);
    monsters.emplace_back(monster2);
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

    //spikes
    ;

    spikes.clear();
    spike.InitialPosition=sf::Vector2f(450,420);
    spike.setPosition(spike.InitialPosition);
    spike.setScale(0.05,0.05);

    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(575,420);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(150,290);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(275,290);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(150,600);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(135,600);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(165,600);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    // Doors

    door->setPosition(350, 550 - 3*130 - door->getGlobalBounds().height);

    // Monster
    sf::Texture monster_t;
    monster_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/monster.png");
    Monster monster1(txtmonst,sf::FloatRect(0,0,800,600),0,200,sf::Vector2f(0, 525));

    monsters.clear();
    monsters.emplace_back(monster1);
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

    //spikes
    ;

    spikes.clear();
    spike.InitialPosition=sf::Vector2f(450,420);
    spike.setPosition(spike.InitialPosition);
    spike.setScale(0.05,0.05);

    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(575,420);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(150,290);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(275,290);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(150,600);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(135,600);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(165,600);
    spike.setPosition(spike.InitialPosition);
    spikes.emplace_back(spike);
    // Doors

    door->setPosition(350, 550 - 3*130 - door->getGlobalBounds().height);

    // Monster
    sf::Texture monster_t;
    monster_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/monster.png");
    Monster monster1(txtmonst,sf::FloatRect(0,0,800,600),0,200,sf::Vector2f(0, 525));

    monsters.clear();
    monsters.emplace_back(monster1);
}}

