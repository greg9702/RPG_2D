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
    int game_stage;
public:
    Game();
    ~Game();
    void start();                   // infinity loop
    void draw();                    // contains all window display methods
    char input();                   // gets input
    void update(char& button);                  // update objects
    void action(const char& button_);
    std::unique_ptr <Game_Window> game_window;
    std::shared_ptr<Player> player;
    std::unique_ptr<Map> map;                   // TODO change to unique
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::shared_ptr<Enemy> enemy;               //enemy to fight
    std::unique_ptr<Fight> fight;
    std::vector<std::shared_ptr<Object>> objects;   // interface for all objects on map
    std::shared_ptr<Object> retObjPointer(std::vector<std::shared_ptr<Object>> &objects, const int& x_, const int& y_); // using static cast we can cast it to any type
    std::string getCurrentTimestamp();
};
#endif
