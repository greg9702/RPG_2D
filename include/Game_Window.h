//
// Created by greg9702 on 12/8/18.
//

#ifndef WINDOW_H
#define WINDOW_H

#include "Map.h"
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <chrono>
#include "Game.h"

class Game_Window {
public:
    Game_Window();
    ~Game_Window();
    char drawMap(Map* map_, Player* player_);
    sf::RenderWindow Windowx;
};

#endif //RPG_WINDOW_H
