//
// Created by greg9702 on 12/8/18.
//

#include "Fight.h"

Fight::Fight(Player* player_, Enemy* enemy_) : fight_last(1){
    startFight(player_,enemy_);
}

Fight::~Fight() {
    std::cout << "Fight destroyed" << std::endl;
}

bool Fight::retFight_status() {
    return this->fight_last;
}

void Fight::startFight(Player* player_, Enemy* enemy_) {
    std::cout << "PH" << player_->retHp() << std::endl;
    std::cout << "EH" << enemy_->retHp() << std::endl;
}

void Fight::setFight(const bool &number) {
    this->fight_last = number;
}
