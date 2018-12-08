//
// Created by greg9702 on 12/8/18.
//
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>
#include "Game_Window.h"

class Game {
private:
    bool game_over;
    char button;
    char game_stage; // map view. fight view, eq view etc // TODO SET ENUM
public:
    Game();
    ~Game();
    void start();                   // infinity loop
    void draw();                    // contains all window display methods
    char input();                   // gets input
    void update(char& button);                  // update objects
    void action(const char& button_);
    std::vector<Object*> objects;   // interface for all objects on map
    Player* player;                 // TODO change to smart pointers
    Map* map;
    Enemy* enemy1;                  // TODO more enemies - need to create some kind of array or vector
    Enemy* enemy2;
    Game_Window * game_window;
    Object* retObjPointer(std::vector<Object*> &objects, const int& x_, const int& y_); // using static cast we can cast it to any type
    std::string getCurrentTimestamp();
};
#endif