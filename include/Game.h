//
// Created by greg9702 on 12/8/18.
//
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>
#include "Game_Window.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Fight.h"

enum Game_stage {
    MAP_VIEW,
    FIGHT_VIEW,
    END_SCREEN
};

class Game {
private:
    bool game_over;
    char button;


    Game_stage game_stage;
public:
    Game();
    ~Game();
    void start();                   // infinity loop
    void draw();                    // contains all window display methods
    char input();                   // gets input
    void update(char& button);                  // update objects
    void action(const char& button_);
    Game_Window * game_window;
    Player* player;                 // TODO change to smart pointers
    Map* map;
    std::vector<Enemy*> enemies;
    Enemy* enemy;
    Fight* fight;
    std::vector<Object*> objects;   // interface for all objects on map
    Object* retObjPointer(std::vector<Object*> &objects, const int& x_, const int& y_); // using static cast we can cast it to any type
    std::string getCurrentTimestamp();
};
#endif