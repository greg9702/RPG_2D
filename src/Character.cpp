//
// Created by greg9702 on 12/4/18.
//

#include "Character.h"

Character::Character(const int &lvl_, const int& hp_, const int& atk_, const int& arm_, const int& exp_, const int& gold_) : hp(hp_), level(lvl_), attack(atk_), armor(arm_), gold(gold_), exp(exp_){
    std::cout << "CHARACTER CONSTRUCTOR CALLED" << std::endl;
}

Character::~Character() {
    std::cout << "CHARACTER DESTRUCTOR CALLED " << std::endl;
}

int Character::retHp() const {
    return this->hp;
}

int Character::retAtk() const {
    return this->attack;
}
