//
// Created by greg9702 on 12/8/18.
//

#include "Fight.h"

Fight::Fight(Player* player, Enemy* enemy) {
    std::cout << "FIGHT CONSTRUCTOR CALLED" << std::endl;
    player_ = player;
    enemy_ = enemy;
    fight_control = FIGHT_IN_PROG;
}

Fight::~Fight() {
    std::cout << "FIGHT DESTRUCTOR CALLED" << std::endl;
}

int Fight::retFight_status() {
    return fight_control;
}

void Fight::action_atack() {
    player_->takeDamage(enemy_->retAtk());
    enemy_->takeDamage(player_->retAtk());
    Fight::Fight_update();
}

void Fight::Fight_update() {
    if (player_->retHp() <= 0) {
        fight_control = FIGHT_LOST;
    }
    if (enemy_->retHp() <= 0) {
        player_->getLoot(enemy_->dropLoot());
        fight_control = FIGHT_WON;
    }
}

void Fight::setFight(const int &status) {
    fight_control = RUN_AWAY;
}

