#ifndef WINDOW_H
#define WINDOW_H

#include "Map.h"
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <chrono>
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>

class Game_Window {                             // TODO clean this class
public:
    Game_Window();
    ~Game_Window();
    void drawWindow(std::unique_ptr<Map> &map_, std::shared_ptr<Player> player_);
    void drawWindow(std::shared_ptr<Player> player_, std::shared_ptr<Enemy> enemy_);
    void drawWindow();
    sf::RenderWindow Windowx;
    sf::Texture gTexture;
    sf::Sprite grassImage; // grass object image
    sf::Texture tTexture;
    sf::Sprite treeImage; // tree object image
    sf::Texture pTexture;
    sf::Sprite playerImage; // player object image
    sf::Texture eTexture;
    sf::Sprite enemyImage;  // enemy object image
    sf::Font font;
};

#endif
