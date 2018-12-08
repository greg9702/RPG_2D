#include "Enemy.h"


Enemy::Enemy(const int &x_, const int &y_, const char& type_, const int &lvl_, const int& hp_, const int& atk_, const int& arm_, const int& exp_, const int& gold_)
        : Object(x_, y_, type_), Character(lvl_, hp_, atk_, arm_, exp_, gold_) {
}


Enemy::~Enemy() { std::cout << "Enemy destructor called! " << std::endl; }

int Enemy::retPosx() {
    return this->m_posx;
}

int Enemy::retPosy() {
    return this->m_posy;
}

char Enemy::retType() {
    return 'e';
}

void Enemy::takeDamage(const int& atack_) {
    this->m_hp = this->m_hp - atack_ + this->m_armor;
    std::cout << "Player atacked for " << atack_ - this->m_armor << std::endl;
}

std::vector<int> Enemy::dropLoot() {
    std::vector<int> loot;
    loot.push_back(this->m_exp);
    loot.push_back(this->m_gold);
    return loot;
}


