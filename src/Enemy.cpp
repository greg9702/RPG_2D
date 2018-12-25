#include "Enemy.h"


Enemy::Enemy(const int &x_, const int &y_, const char& type_, const int &lvl_, const int& hp_, const int& atk_, const int& arm_, const int& exp_, const int& gold_)
        : Object(x_, y_, type_), Character(lvl_, hp_, atk_, arm_, exp_, gold_) {
    std::cout << "ENEMY CONSTRUCTOR CALLED" << std::endl;
}

Enemy::~Enemy() { std::cout << "ENEMY DESTRUCTOR CALLED! " << std::endl; }

int Enemy::retPosx() {
    return this->posx;
}

int Enemy::retPosy() {
    return this->posy;
}

char Enemy::retType() {
    return 'e';
}

void Enemy::takeDamage(const int& atack_) {
    this->hp = this->hp - atack_ + this->armor;
    //std::cout << "Player atacked for " << atack_ - this->m_armor << std::endl;
}

std::vector<int> Enemy::dropLoot() {
    std::vector<int> loot;
    loot.push_back(this->exp);
    loot.push_back(this->gold);
    return loot;
}


