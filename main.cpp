#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include<stages.cpp>
#include <character.h>
#include <switch.h>
#include <door.h>
#include <monster.h>
#include <coin.h>
#include <spike.h>
#include <movingspike.h>
#include <bullet.h>
#include <cmath>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "KeyRush");
    window.setFramerateLimit(60);

    // Background
    sf::Texture background_texture;
    background_texture.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/background.png");
    sf::Sprite background(background_texture);
    background.setScale(2.0, 2.0);
    background.setPosition(0, 0);

    // Character
    sf::Texture character_texture;
    character_texture.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/character1.png");
    Character character(character_texture);


    // Switch
    sf::Texture switch_t;
    switch_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/switch.png");
    Switch switch_s(switch_t);

    // Bricks
    sf::Texture brick_texture;
    brick_texture.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/brick.png");
    brick_texture.setRepeated(true);
    std::vector<sf::Sprite> bricks;
    sf::Sprite brick;
    brick.setTexture(brick_texture);
    brick.setScale(0.7, 0.7);

    //spikes
    sf::Texture spikes;
    spikes.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/spike.png");
    MovingSpike mspike(spikes);
    Spike spike(spikes);

    std::vector<MovingSpike> mspiks;
    std::vector<Spike> spiks;



    // Doors
    sf::Texture doors_texture;
    doors_texture.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/doors.png");
    Door door(doors_texture);

    // Monster
    std::vector<Monster> monstra;
    sf::Texture monster_t;
    monster_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/monster.png");
    // Coins
    srand(time(nullptr));
    sf::Texture coin_t;
    coin_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/coin.png");
    std::vector<Coin> coins;
    for(int i = 0; i < 20; i++)
    {
        Coin coin(coin_t);
        coin.setPosition(rand()%(800-(int)coin.getGlobalBounds().width), rand()%(575-(int)coin.getGlobalBounds().height));
        coins.emplace_back(coin);
    }
    //Bullets
    std::vector<bullet>missiles;
    std::vector<bullet>chmissiles;
    sf::Texture bulletTexture;
    bulletTexture.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/yellowball.jpg");

    // Hearts
    sf::Texture hearts_t;
    hearts_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/hearts.png");
    sf::Sprite hearts(hearts_t);
    hearts.setPosition(800 - hearts.getGlobalBounds().width,0);

    // Texts
    sf::Font font;
    font.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/arial.ttf");
    int score = 0;
    sf::Text score_text;
    score_text.setFont(font);
    score_text.setString("Points: " + std::to_string(score));
    score_text.setStyle(sf::Text::Bold);
    score_text.setFillColor(sf::Color::Yellow);
    score_text.setCharacterSize(25);
    score_text.setPosition(5, 0);


    // Gameover
    sf::Texture over_t;
    sf::Text restart_game;
    restart_game.setFont(font);
    restart_game.setString("To restart the game press: R");
    restart_game.setFillColor(sf::Color::White);
    restart_game.setCharacterSize(30);
    restart_game.setPosition(200, 400);
    over_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/gameover.png");
    sf::Sprite gameover_s(over_t);
    gameover_s.setPosition(0, 0);
    bool gameover = false;

    // Gameover
    sf::Texture win_t;
    win_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/youwin.png");
    sf::Sprite win_s(win_t);
    win_s.setPosition(0, 0);

    //screen texts between stages
    sf::Text next_stage;
    next_stage.setFont(font);
    next_stage.setString("To start next stage press: Enter");
    next_stage.setFillColor(sf::Color::White);
    next_stage.setCharacterSize(30);
    next_stage.setPosition(200, 400);
    sf::Text heal;
    heal.setFont(font);
    heal.setString("Before the next stage begins,\nyou can buy hearts for collected points"
                   "\nto buy a hearth for 10 points press H\nThen press Enter to enter next stage");
    heal.setFillColor(sf::Color::White);
    heal.setCharacterSize(30);
    heal.setPosition(200, 200);
    //Program start
    sf::Text start;
    start.setFont(font);
    start.setString("Start");
    start.setFillColor(sf::Color::White);
    start.setCharacterSize(30);
    start.setPosition(375, 400);
    sf::Text title;
    title.setFont(font);
    title.setStyle(sf::Text::Bold|sf::Text::Italic);
    title.setString("KEY RUSH");
    title.setFillColor(sf::Color::Yellow);
    title.setCharacterSize(100);
    title.setPosition(150,100);
    //Instructions for the player
    sf::Text instruction;
    instruction.setFont(font);
    instruction.setString("Welcome to KeyRush!! \nIn our game your goal is to go through 3 levels without losing 3 hearts.\n"
                          "In order to finish a level you have to go through a door.\n"
                          "To do so press SPACE while standing before an open door"
                          "\nFirst tho you have to open them with a lever by stepping on it.\n"
                          "Use ARROWS to move the character.\nYou can also switch between running and walking with CTRL.\n"
                          "Avoid touching the monsters and obstacles.\n"
                          "On each lvl you can collect coins.\nCoins can be used to restore your hearts between the stages. \n"
                          "On higher difficulties some monsters will also shoot missiles at you.\n"
                          "These missiles have 33% chance to hurt you,\n"
                          "but its better for you not to test your luck on them :D\n"
                          "Good Luck and Have Fun!!!!!");
    instruction.setFillColor(sf::Color::Yellow);
    instruction.setCharacterSize(20);
    instruction.setPosition(50, 50);
    instruction.setLineSpacing(1.5);
    //Game start
    sf::Text welcome;
    welcome.setFont(font);
    welcome.setString("Choose a difficulty: \nHarder game modes have more enemies \nand are more challanging. \nIf you chose a difficulty press Enter. ");
    welcome.setFillColor(sf::Color::White);
    welcome.setCharacterSize(30);
    welcome.setPosition(150, 100);
    sf::Text diffEasy;
    diffEasy.setFont(font);
    diffEasy.setString("Easy");
    diffEasy.setFillColor(sf::Color::White);
    diffEasy.setCharacterSize(30);
    diffEasy.setPosition(150, 400);
    sf::Text diffMedium;
    diffMedium.setFont(font);
    diffMedium.setString("Medium");
    diffMedium.setFillColor(sf::Color::White);
    diffMedium.setCharacterSize(30);
    diffMedium.setPosition(350, 400);
    sf::Text diffHard;
    diffHard.setFont(font);
    diffHard.setString("Hard ");
    diffHard.setFillColor(sf::Color::White);
    diffHard.setCharacterSize(30);
    diffHard.setPosition(550, 400);

    bool start_of_the_game=true;
    bool instructions=false;
    bool game_on=false;
    int difficulty=0;
    int lvl=1;
    int itmis=0; //iterator for the missiles collision


    float time=0;
    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // -----Delta Time----
        sf::Time elapsed = clock.restart();

         time+=elapsed.asSeconds();
         score_text.setString("Score: " + std::to_string(score));
         hearts.setTextureRect(sf::IntRect(0, 0, (192/3) * character.heart, 64));
        if(character.heart <= 0)
        {
            gameover = true;
        }

        if(gameover == false&& game_on==true)
        {
            // Collision & Animate character
            for(auto &brick : bricks)
            {
                sf::FloatRect cbounds = character.getGlobalBounds();
                sf::FloatRect bbounds = brick.getGlobalBounds();
                if(cbounds.intersects(bbounds) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    // On brick
                    if(cbounds.top > bbounds.top - cbounds.height
                            &&cbounds.top < bbounds.top+ bbounds.height - cbounds.height
                            && cbounds.left < bbounds.left + bbounds.width-10
                            && cbounds.left +cbounds.width>bbounds.left+10)
                    {
                        character.fall_velocity=0;
                        character.onbrick = true;
                        break;

                    }
                }
                else
                {   character.onbrick=false;}}



                    character.animate(elapsed);
                // Move character
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    character.moveInDirection(elapsed, sf::Keyboard::Up);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    character.moveInDirection(elapsed, sf::Keyboard::Down);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    character.moveInDirection(elapsed, sf::Keyboard::Left);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    character.moveInDirection(elapsed, sf::Keyboard::Right);
                }
               /* if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                   if ( character.attack()){
                       double ydistance=sf::Mouse::getPosition(window).y-character.getPosition().y;
                       double xdistance=sf::Mouse::getPosition(window).x-character.getPosition().x;
                       double c=sqrt(pow(xdistance,2)+pow(ydistance,2));
                       ydistance/=c;
                       xdistance/=c;
                       bullet bullet(bulletTexture,ydistance*200,xdistance*200,character.getPosition());
                       chmissiles.emplace_back(bullet);
                       std::cout<<"pow"<<std::endl;
                   }
                }*/


                //Move spikes
                for(auto &spik : mspiks)
                {
                    spik.animate(elapsed);
                }

                // Move monster and monster attack
                for(auto &monstr : monstra)
                 {
                    monstr.animate(elapsed);
                 }
              for(auto &monstr : monstra)
                 {
                   if( monstr.attack(elapsed)){

                       double ydistance=character.getPosition().y-monstr.getPosition().y;
                       double xdistance=character.getPosition().x-monstr.getPosition().x;
                       double c=sqrt(pow(xdistance,2)+pow(ydistance,2));
                       ydistance/=c;
                       xdistance/=c;
                       bullet bullet(bulletTexture,ydistance*200,xdistance*200,monstr.getPosition());
                       missiles.emplace_back(bullet);
                   }
                 }
                //Move bullets
                 for(auto &missile : missiles)
                 {
                    missile.moveBullet(elapsed);
                 }
                 for(auto &missile : chmissiles)
                 {
                    missile.moveBullet(elapsed);
                 }
                // Collision
                for(auto &monstr : monstra)
                {
                    if(monstr.getGlobalBounds().intersects(character.getGlobalBounds()))
                {
                        if(time>0.3){
                            character.heart -= 1;
                            time=0;
                }}}
                // Door Collision
                if(door.getGlobalBounds().intersects(character.getGlobalBounds()) && door.open == true)
                {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                        {
                            gameover = true;
                }}

                // Switch Collision
                if(switch_s.getGlobalBounds().intersects(character.getGlobalBounds()))
                {
                    switch_s.on = true;
                    switch_s.switch_on();
                    door.open = true;
                    door.doorOpen();
                }
                //bulletcollision
                /**/ for(auto &missile :missiles )
                 {
                    sf::FloatRect mbounds = missile.getGlobalBounds();;
                    sf::FloatRect cbounds = character.getGlobalBounds();
                    for(auto &brick : bricks){
                        sf::FloatRect bbounds = brick.getGlobalBounds();
                        if (mbounds.intersects(bbounds)){
                             missiles.erase(missiles.begin()+itmis);

                        }
                    }
                    if (mbounds.intersects(cbounds)){
                        missiles.erase(missiles.begin()+itmis);
                        if(rand()%100>33)character.heart-=1;
                    }
                    if(!mbounds.intersects(sf::FloatRect(0,0,800,600))){
                        missiles.erase(missiles.begin()+itmis);
                    }itmis++;
                 }itmis=0;
                /* for(auto &missile :chmissiles )
                 {
                    sf::FloatRect mbounds = missile.getGlobalBounds();;

                    for(auto &brick : bricks){
                        sf::FloatRect bbounds = brick.getGlobalBounds();
                        if (mbounds.intersects(bbounds)){
                             chmissiles.erase(chmissiles.begin()+itmis);
                        }
                    }
                     for(auto &monstr : monstra){
                    sf::FloatRect bounds = monstr.getGlobalBounds();
                    if (mbounds.intersects(bounds)){
                        chmissiles.erase(chmissiles.begin()+itmis);
                        int damage=monstr.takeDamage();
                        std::cout<<damage<<std::endl;
                    }
                    if(!mbounds.intersects(sf::FloatRect(0,0,800,600))){
                        chmissiles.erase(chmissiles.begin()+itmis);
                    }itmis++;
                 }}itmis=0;
                    */
                // spikes collision
                for(int i = 0; i < (int)mspiks.size(); i++)
                {
                    if(mspiks[i].getGlobalBounds().intersects(character.getGlobalBounds())){
                        if(time>0.5){
                            character.heart -= 1;
                            time=0;
                }}}
                for(int i = 0; i < (int)spiks.size(); i++)
                {
                    if(spiks[i].getGlobalBounds().intersects(character.getGlobalBounds())){
                        if(time>0.5){
                            character.heart -= 1;
                            time=0;
                }}}
            // Coins Collision
            for(int i = 0; i < (int)coins.size(); i++)
            {
                if(coins[i].getGlobalBounds().intersects(character.getGlobalBounds()))
                {
                    score+=1;
                    coins.erase(coins.begin() + i);

                }
            }
        }

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {window.close();
            }
            if(event.type==sf::Event::KeyReleased){
                if(event.key.code==sf::Keyboard::LControl ||event.key.code==sf::Keyboard::RControl){
                    character.runOrWalk();//changes walking to running and otherway

                }
            }
            if(event.type==sf::Event::KeyReleased){
                if(event.key.code==sf::Keyboard::Left ||event.key.code==sf::Keyboard::Right){
                    character.standStill();

                }
            }
            if(event.type==sf::Event::KeyReleased){
                if(event.key.code==sf::Keyboard::Up){
                    character.jump=false;
                    character.standStill();

                }
            }
        }

        // clear the window with black color
            window.clear(sf::Color::Black);
        if(start_of_the_game&& !instructions){
         window.draw(start);
         window.draw(title);
         if(sf::Mouse::getPosition(window).y<450 && sf::Mouse::getPosition(window).y>350
                 &&sf::Mouse::getPosition(window).x>350 && sf::Mouse::getPosition(window).x<450){
                    start.setFillColor(sf::Color::Magenta);
              if(sf::Mouse::isButtonPressed(sf::Mouse::Left))instructions=true;
         }else start.setFillColor(sf::Color::White);
        }
        if(start_of_the_game&& instructions){
            window.draw(instruction);
            start.setPosition(700,550);
            window.draw(start);
            if(sf::Mouse::getPosition(window).y<600 && sf::Mouse::getPosition(window).y>500
                    &&sf::Mouse::getPosition(window).x>675 && sf::Mouse::getPosition(window).x<800){
                        start.setFillColor(sf::Color::Magenta);
                 if(sf::Mouse::isButtonPressed(sf::Mouse::Left))start_of_the_game=false;
            }else start.setFillColor(sf::Color::White);
           }

        if(!game_on&& !start_of_the_game){

                window.draw(welcome);
                window.draw(diffEasy);
                window.draw(diffMedium);
                window.draw(diffHard);
                if(sf::Mouse::getPosition(window).y<450 && sf::Mouse::getPosition(window).y>350){
                    if(sf::Mouse::getPosition(window).x>125 && sf::Mouse::getPosition(window).x<250){
                            diffEasy.setFillColor(sf::Color::Green);
                            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))difficulty=1;
                    }
                    else if(sf::Mouse::getPosition(window).x>325&&sf::Mouse::getPosition(window).x<450){
                            diffMedium.setFillColor(sf::Color::Yellow);
                            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))difficulty=2;
                    }
                    else if(sf::Mouse::getPosition(window).x>525&&sf::Mouse::getPosition(window).x<650){
                            diffHard.setFillColor(sf::Color::Red);
                            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))difficulty=3;
                    }
                    else { if(difficulty!=1) diffEasy.setFillColor(sf::Color::White);
                           if(difficulty!=2)diffMedium.setFillColor(sf::Color::White);
                           if(difficulty!=3)diffHard.setFillColor(sf::Color::White);}
                }else { if(difficulty!=1)diffEasy.setFillColor(sf::Color::White);
                        if(difficulty!=2)diffMedium.setFillColor(sf::Color::White);
                        if(difficulty!=3)diffHard.setFillColor(sf::Color::White);}
                if(difficulty){
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                        window.clear(sf::Color::Black);
                        game_on=true;
                        stage(lvl,difficulty,&switch_s,brick, bricks, mspike, mspiks,&door,monstra,monster_t,spike,spiks);
                }}}
         if(game_on&& !start_of_the_game){

        // draw everything here...
        window.draw(background);
        window.draw(switch_s);
        for(auto &brick : bricks)
        {
            window.draw(brick);
        }
        for(auto &spik : spiks)
        {
            window.draw(spik);
        }
        for(auto &missile : missiles)
        {
            window.draw(missile);
        }
        /*for(auto &missile : chmissiles)
        {
            window.draw(missile);
        }*/
        for(auto &spik : mspiks)
        {
            window.draw(spik);
        }
        for(auto &coin : coins)
        {
            window.draw(coin);
        }
        window.draw(door);
        for(auto &monstr : monstra)
        {
            window.draw(monstr);
            /*if(!monstr.isHealthy()){
              //delete monster
            }*/
        }
        window.draw(character);

        window.draw(score_text);
        window.draw(hearts);
                }
        if(gameover == true && character.heart <= 0) {
            window.clear(sf::Color::Black);
            window.draw(gameover_s);
            window.draw(restart_game);
            window.draw(score_text);
            window.draw(hearts);
            lvl=1;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){

                 if(lvl!=3){
                     character.speedx_=400;
                     character.speedy_=400;
                     character.setScale(0.5,0.5);
                }
                game_on=false;
                character.heart+=3;
                window.clear(sf::Color::Black);
                stage(lvl,difficulty,&switch_s,brick, bricks, mspike, mspiks,&door,monstra,monster_t,spike,spiks);
                gameover = false;
                character.setPosition(800 - character.getGlobalBounds().width, 575 - character.getGlobalBounds().height);
                switch_s.on = false;
                door.open=false;
                switch_s.switch_on();
                door.doorOpen();
                score=0;
                score_text.setString("Score: " + std::to_string(score));
                coins.clear();
                for(int i = 0; i < 20; i++)
                {
                    Coin coin(coin_t);
                    coin.setPosition(rand()%(800-(int)coin.getGlobalBounds().width), rand()%(575-(int)coin.getGlobalBounds().height));
                    coins.emplace_back(coin);
                }

               }}
            else if(gameover == true && character.heart > 0&& lvl==3){
                    window.clear(sf::Color::Black);
                    window.draw(win_s);
                    window.draw(restart_game);
                    window.draw(score_text);
                    window.draw(hearts);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                        lvl=1;
                        if(lvl!=3){
                            character.speedx_=400;
                            character.speedy_=400;
                            character.setScale(0.5,0.5);
                        }

                        game_on=false;
                        character.heart+=3;
                        window.clear(sf::Color::Black);
                        stage(lvl,difficulty,&switch_s,brick, bricks, mspike, mspiks,&door,monstra,monster_t,spike,spiks);
                        gameover = false;
                        character.setPosition(800 - character.getGlobalBounds().width, 575 - character.getGlobalBounds().height);
                        switch_s.on = false;
                        door.open=false;
                        switch_s.switch_on();
                        door.doorOpen();
                        score=0;
                        score_text.setString("Score: " + std::to_string(score));
                        coins.clear();
                        for(int i = 0; i < 20; i++)
                        {
                            Coin coin(coin_t);
                            coin.setPosition(rand()%(800-(int)coin.getGlobalBounds().width), rand()%(575-(int)coin.getGlobalBounds().height));
                            coins.emplace_back(coin);
                        }
                        }}
             else if (gameover == true && character.heart > 0){
                    window.clear(sf::Color::Black);
                    window.draw(heal);
                    window.draw(score_text);
                    window.draw(hearts);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)&&score>=10&&character.heart<3){
                        score-=10;
                        character.heart++;
                        hearts.setTextureRect(sf::IntRect(0, 0, (192/3) * character.heart, 64));
                        std::cout<<character.heart;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                        lvl++;
                        if(lvl==3){
                            character.speedx_=200;
                            character.speedy_=300;
                            character.setScale(0.25,0.25);
                        }
                        if(lvl!=3){
                            character.speedx_=400;
                            character.speedy_=400;
                            character.setScale(0.5,0.5);
                        }

                        stage(lvl,difficulty,&switch_s,brick, bricks, mspike, mspiks,&door,monstra,monster_t,spike,spiks);
                        window.clear(sf::Color::Black);
                        gameover = false;
                        character.setPosition(800 - character.getGlobalBounds().width, 575 - character.getGlobalBounds().height);
                        switch_s.on = false;
                        door.open=false;
                        switch_s.switch_on();
                        door.doorOpen();
                        score_text.setString("Score: " + std::to_string(score));
                        coins.clear();
                        for(int i = 0; i < 20; i++)
                        {
                            Coin coin(coin_t);
                            coin.setPosition(rand()%(800-(int)coin.getGlobalBounds().width), rand()%(575-(int)coin.getGlobalBounds().height));
                            coins.emplace_back(coin);
                        }
                        }}



        window.display();
        }

    return 0;
}
