#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "Object.h"
#include "Character.h"

class Enemy : public Object, public Character {
private:

public:
    Enemy(const int &x_, const int &y_, const int& type_, const int &lvl_, const int& hp_, const int& atk_, const int& arm_, const int& exp_, const int& gold_);
    ~Enemy() override ;
    int retPosx() const override;
    int retPosy() const override;
    int retType() const override;
    std::vector<int> dropLoot();         // return gold and exp
    void takeDamage(const int& attack_);
};

#endif