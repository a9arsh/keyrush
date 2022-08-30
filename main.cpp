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
//void stage(int stage, int difficulty ,Switch* lever, sf::Sprite& brick,std::vector<sf::Sprite>& bricks,MovingSpike& spike,std::vector<MovingSpike>& spikes,
//           Door* door,std::vector<Monster>& monsters, sf::Texture& txtmonst);
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
    character_texture.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/character.png");
    Character character(character_texture);
    character.setScale(0.6, 0.6);
    character.setPosition(800 - character.getGlobalBounds().width, 575 - character.getGlobalBounds().height);

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
    MovingSpike spike(spikes);
    std::vector<MovingSpike> spiks;

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
    heal.setString("Before the stage begins,\n you can buy hearts \n u can have max: 3 \n to buy a hearth for 10 points press H");
    heal.setFillColor(sf::Color::White);
    heal.setCharacterSize(30);
    heal.setPosition(200, 400);

    //Game start
    sf::Text welcome;
    welcome.setFont(font);
    welcome.setString("Choose a difficulty: \nHarder game modes have more enemies \nand are more challanging ");
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


    bool game_on=false;
    bool h=false;
    int difficulty=0;
    int lvl=1;


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


                //Move spikes
                for(auto &spik : spiks)
                {
                    spik.animate(elapsed);
                }

                // Move monster
                for(auto &monstr : monstra)
                 {
                    monstr.animate(elapsed);
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
                // spikes collision
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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) return 0;

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {window.close();
            }
        }

        // clear the window with black color
            window.clear(sf::Color::Black);
        if(!game_on){

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
                        stage(lvl,difficulty,&switch_s,brick, bricks, spike, spiks,&door,monstra,monster_t);
                }}}
         if(game_on){

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
        for(auto &coin : coins)
        {
            window.draw(coin);
        }
        window.draw(door);
        for(auto &monstr : monstra)
        {
            window.draw(monstr);
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
                game_on=false;
                character.heart+=3;
                window.clear(sf::Color::Black);
                stage(lvl,difficulty,&switch_s,brick, bricks, spike, spiks,&door,monstra,monster_t);
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
                for(auto &monstr : monstra)
                {
                 monstr.setPosition(monstr.Initialposition);
                }}}
            else if(gameover == true && character.heart > 0){
                if (h==false){
                    window.clear(sf::Color::Black);
                    window.draw(win_s);
                    window.draw(next_stage);
                    window.draw(score_text);
                    window.draw(hearts);}

                if (h==true){
                    window.clear(sf::Color::Black);
                    window.draw(heal);
                    window.draw(score_text);
                    window.draw(hearts);
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)&&score>=10){
                        score-=10;
                        character.heart++;
                        hearts.setTextureRect(sf::IntRect(0, 0, (192/3) * character.heart, 64));
                        std::cout<<character.heart;
                    }}
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                    h=true;
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
                        lvl++;
                        stage(lvl,difficulty,&switch_s,brick, bricks, spike, spiks,&door,monstra,monster_t);
                        window.clear(sf::Color::Black);
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
                        for(auto &monstr : monstra)
                        {
                            monstr.setPosition(monstr.Initialposition);
                        }}


        }
        window.display();
        }

    return 0;
}
