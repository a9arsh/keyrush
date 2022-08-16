#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include <character.h>
#include <switch.h>
#include <door.h>
#include <monster.h>
#include <coin.h>
#include <spike.h>
#include <movingspike.h>
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);

    // Background
    sf::Texture background_texture;
    sf::Sprite background(background_texture);
    background.setScale(2.0, 2.0);
    background.setPosition(0, 0);

    // Character
    sf::Texture character_texture;
    Character character(character_texture);
    character.setScale(0.6, 0.6);
    character.setPosition(800 - character.getGlobalBounds().width, 575 - character.getGlobalBounds().height);

    // Switch
    sf::Texture switch_t;
    Switch switch_s(switch_t);
    switch_s.setPosition(25 + switch_s.getGlobalBounds().width, 575 - switch_s.getGlobalBounds().height);

    // Bricks
    sf::Texture brick_texture;
    brick_texture.setRepeated(true);
    std::vector<sf::Sprite> bricks;
    sf::Sprite brick;
    brick.setTexture(brick_texture);
    brick.setScale(0.7, 0.7);

    brick.setPosition(450, 550 - 130);
    bricks.emplace_back(brick);

    brick.setPosition(150, 550 - 2*130);
    bricks.emplace_back(brick);

    brick.setPosition(350, 550 - 3*130);
    bricks.emplace_back(brick);

    //spikes
    sf::Texture spikes;
    spikes.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/spike.png");
    MovingSpike spike(spikes);
    spike.InitialPosition=sf::Vector2f(450,420);
    spike.setPosition(spike.InitialPosition);
    spike.setScale(0.05,0.05);
    std::vector<MovingSpike> spiks;
    spiks.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(575,420);
    spike.setPosition(spike.InitialPosition);
    spiks.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(150,290);
    spike.setPosition(spike.InitialPosition);
    spiks.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(275,290);
    spike.setPosition(spike.InitialPosition);
    spiks.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(150,600);
    spike.setPosition(spike.InitialPosition);
    spiks.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(135,600);
    spike.setPosition(spike.InitialPosition);
    spiks.emplace_back(spike);
    spike.InitialPosition=sf::Vector2f(165,600);
    spike.setPosition(spike.InitialPosition);
    spiks.emplace_back(spike);
    // Doors
    sf::Texture doors_texture;
    doors_texture.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/doors.png");
    Door door(doors_texture);
    door.setPosition(350, 550 - 3*130 - door.getGlobalBounds().height);

    // Monster
    sf::Texture monster_t;
    Monster monster(monster_t);

    // Coins
    srand(time(nullptr));
    sf::Texture coin_t;
    std::vector<Coin> coins;
    for(int i = 0; i < 20; i++)
    {
        Coin coin(coin_t);
        coin.setPosition(rand()%(800-(int)coin.getGlobalBounds().width), rand()%(575-(int)coin.getGlobalBounds().height));
        coins.emplace_back(coin);
    }

    // Hearts
    sf::Texture hearts_t;
    sf::Sprite hearts(hearts_t);
    hearts.setPosition(800 - hearts.getGlobalBounds().width,0);

    // Texts
    sf::Font font;
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
    over_t.loadFromFile("C:/Users/user/OneDrive/Dokumenty/Key_Rush/gameover.png");
    sf::Sprite gameover_s(over_t);
    gameover_s.setPosition(0, 0);
    bool gameover = false;

    // Gameover
    sf::Texture win_t;
    sf::Sprite win_s(win_t);
    win_s.setPosition(0, 0);

    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // -----Delta Time----
        sf::Time elapsed = clock.restart();

        if(character.heart <= 0)
        {
            gameover = true;
        }

        if(gameover == false)
        {
            // Collision & Animate character
            for(auto &brick : bricks)
            {
                sf::FloatRect cbounds = character.getGlobalBounds();
                sf::FloatRect bbounds = brick.getGlobalBounds();
                if(cbounds.intersects(bbounds))
                {
                    // On brick
                    if(cbounds.top < bbounds.top - cbounds.height + 10
                            && cbounds.left > bbounds.left - cbounds.width
                            && cbounds.left < bbounds.left + bbounds.width)
                    {
                        character.fall_velocity = 0;
                        character.setPosition(character.getPosition().x, bbounds.top - cbounds.height);
                    }
                }
                else
                {
                    character.animate(elapsed);
                }
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
            }
            //Move spikes
            for(auto &spik : spiks)
            {
                spik.animate(elapsed);
            }//spike.animate(elapsed);
            // Move monster
            monster.animate(elapsed);
            // Collision
            if(monster.getGlobalBounds().intersects(character.getGlobalBounds()))
            {
                character.heart -= 1;
                hearts.setTextureRect(sf::IntRect(0, 0, (192/3) * character.heart, 64));
                monster.setPosition(0, 575 - monster.getGlobalBounds().height);
            }

            // Door Collision
            if(door.getGlobalBounds().intersects(character.getGlobalBounds()) && door.open == true)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    gameover = true;
                }
            }

            // Switch Collision
            if(switch_s.getGlobalBounds().intersects(character.getGlobalBounds()))
            {
                switch_s.on = true;
                switch_s.switch_on();
                door.open = true;
                door.doorOpen();
            }

            // Coins Collision
            for(int i = 0; i < (int)coins.size(); i++)
            {
                if(coins[i].getGlobalBounds().intersects(character.getGlobalBounds()))
                {
                    score+=1;
                    coins.erase(coins.begin() + i);
                    score_text.setString("Score: " + std::to_string(score));
                }
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) return 0;

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

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
        }//window.draw(spike);
        for(auto &coin : coins)
        {
            window.draw(coin);
        }
        window.draw(door);
        window.draw(monster);
        window.draw(character);

        window.draw(score_text);
        window.draw(hearts);

        if(gameover == true && character.heart <= 0) window.draw(gameover_s);
        else if(gameover == true && character.heart > 0) window.draw(win_s);

        window.display();
    }

    return 0;
}
