//
// Created by greg9702 on 12/8/18.
//
#include "Game_Window.h"

Game_Window::~Game_Window() {
    std::cout << "Map destructor called!" << std::endl;
}

Game_Window::Game_Window() {
    Windowx.create(sf::VideoMode(760,560), "RPG");
    Windowx.clear();
    Windowx.setKeyRepeatEnabled(false);
    Windowx.setPosition(sf::Vector2i(50, 50));
    Windowx.setFramerateLimit(60);                  // set FPS

    //Window.setSize(sf::Vector2u(640, 480));
    // run the program as long as the window is open
    //Window.setSize(sf::Vector2u(640, 480));

}

void Game_Window::drawMap(Map* map_, Player* player_) {
    Windowx.clear();

    sf::Font font;
    if (!font.loadFromFile("Sansation_Regular.ttf"))
        //find this file in the "pong" example in the SFML examples folder
    {
        std::cout << "Error loading font\n" ;
    }

    sf::Text text;
    text.setFont(font);
    text.setString(player_->showStats());
    text.setCharacterSize(20); // in pixels, not points!
    //text.setStyle(sf::Text::Bold );
    text.setPosition(40,400);

// inside the main loop, between window.clear() and window.display()

    sf::Texture gTexture;
    sf::Sprite grassImage;
    if(!gTexture.loadFromFile("grass.png"))
        std::cout << "Cant load g image " << std::endl;
    grassImage.setTexture(gTexture);

    sf::Texture tTexture;
    sf::Sprite treeImage;
    if(!tTexture.loadFromFile("tree.png"))
        std::cout << "Cant load t image " << std::endl;
    treeImage.setTexture(tTexture);

    sf::Texture pTexture;
    sf::Sprite playerImage;
    if(!pTexture.loadFromFile("player.png"))
        std::cout << "Cant load image " << std::endl;
    playerImage.setTexture(pTexture);

    sf::Texture eTexture;
    sf::Sprite enemyImage;
    if(!eTexture.loadFromFile("enemy.png"))
        std::cout << "Cant load e image " << std::endl;
    enemyImage.setTexture(eTexture);

    int xposition = 0;
    int yposition = 0;
    // check all the window's events that were triggered since the last iteration of the loop

    for (int i = 0; i < 20; i++ ) {
        for(int j = 0; j < 40; j++ ) {
            // if ()
            if (map_->map[i][j] == ' ') {
                grassImage.setPosition(xposition, yposition);
                Windowx.draw(grassImage);
            }else if (map_->map[i][j] == '*') {
                treeImage.setPosition(xposition, yposition);
                Windowx.draw(treeImage);
            }else if (map_->map[i][j] == 'p') {
                playerImage.setPosition(xposition, yposition);
                Windowx.draw(playerImage);
            }
            else if (map_->map[i][j] == 'e') {
                enemyImage.setPosition(xposition, yposition);
                Windowx.draw(enemyImage);
            }
            xposition += 40;
        }
        yposition += 40;
        xposition = 0;
    }
    Windowx.draw(text);
    Windowx.display();
}

void Game_Window::drawMap(Player *player_, Enemy *enemy_) {
    Windowx.clear();

    sf::Font font;
    if (!font.loadFromFile("Sansation_Regular.ttf"))
    {
        std::cout << "Error loading font\n" ;
    }

    sf::Text text;
    text.setFont(font);
    std::string stext;
    stext = "PLAYER HP: " + std::to_string(player_->retHp()) + "\nENEMY HP: " + std::to_string(enemy_->retHp());
    text.setString(stext);
    text.setCharacterSize(48); // in pixels, not points!
    //text.setStyle(sf::Text::Bold );
    text.setPosition(0,0);


    Windowx.draw(text);
    Windowx.display();
}
