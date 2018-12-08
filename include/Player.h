#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "Object.h"
#include "Character.h"
#include <algorithm>

class Player : public Object, public Character {
private:

public:
    Player(const int& x_, const int& y_, const char& type_, const int &lvl_, const int& hp_, const int& atk_, const int& arm_, const int& exp_, const int& gold_);
    ~Player() override ;
    int retPosx() override;
    int retPosy() override;
    char retType() override;
    int retAtk() override;
    void movePlayer(const char& button);
    std::string showStats();
    void getLoot(const std::vector<int>& loot_);
    void updatePlayer();
    void takeDamage(const int& atack_);
};


#endif