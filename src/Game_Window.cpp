//
// Created by greg9702 on 12/8/18.
//
#include "Game_Window.h"

char Game_Window::drawMap(Map* map_, Player* player_) {
    sf::Text text;
    //player_->showStats()
    text.setString("ELO");
    sf::Sprite player_stats;
    text.setColor(sf::Color::Red);

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
        //std::cout << xposition << ", " << yposition << std::endl;

        yposition += 40;
        xposition = 0;
    }
    player_stats.setPosition(0, 0);
    Windowx.draw(player_stats);
    Windowx.display();
}

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
