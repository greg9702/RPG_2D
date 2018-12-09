//
// Created by greg9702 on 12/4/18.
//

#include "Character.h"

Character::Character(const int &lvl_, const int& hp_, const int& atk_, const int& arm_, const int& exp_, const int& gold_) : m_hp(hp_), m_level(lvl_), m_atack(atk_), m_armor(arm_), m_gold(gold_), m_exp(exp_){
    std::cout << "CHARACTER CONSTRUCTOR CALLED" << std::endl;
}

Character::~Character() {
    std::cout << "CHARACTER DESTRUCTOR CALLED " << std::endl;
}

int Character::retHp() {
    return m_hp;
}

int Character::retAtk() {
    return m_atack;
}
