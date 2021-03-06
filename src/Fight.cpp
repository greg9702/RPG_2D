//
// Created by greg9702 on 12/8/18.
//

#include "Fight.h"

Fight::Fight(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy) {
    std::cout << "FIGHT CONSTRUCTOR CALLED" << std::endl;
    player_ = player;
    enemy_ = enemy;
    fight_control = FIGHT_IN_PROG;
}

Fight::~Fight() {
    std::cout << "FIGHT DESTRUCTOR CALLED" << std::endl;
}

int Fight::retFight_status() {
    return this->fight_control;
}

void Fight::action_attack() {
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
        this->fight_control = FIGHT_WON;
    }
}

void Fight::setStatRunAway() {
    this->fight_control = RUN_AWAY;
}
