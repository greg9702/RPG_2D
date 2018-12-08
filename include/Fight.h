//
// Created by greg9702 on 12/8/18.
//

#ifndef FIGHT_H
#define FIGHT_H

#include "Player.h"
#include "Enemy.h"

class Fight {
private:
    bool fight_last;
public:
    Fight(Player* player, Enemy* enemy);
    ~Fight();
    bool retFight_status();
    void startFight(Player* player_, Enemy* enemy_);
};

#endif //RPG_FIGHT_H
