//
// Created by greg9702 on 12/4/18.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H

#include <iostream>

class Character {
protected:
    int hp;
    int level;
    int exp;
    int atack;
    int armor;
    int gold;
public:
    Character(const int &hp_, const int& lvl_, const int& atk_, const int& arm_, const int& exp_, const int& gold_);
    ~Character();
    int retHp();
    virtual int retAtk();
};
#endif //RPG_CHARACTER_H
