//
// Created by greg9702 on 12/8/18.
//

#ifndef FIGHT_H
#define FIGHT_H

#include "Player.h"
#include "Enemy.h"

enum Fight_status {
    FIGHT_IN_PROG,
    RUN_AWAY,
    FIGHT_WON,
    FIGHT_LOST
};

class Fight {
private:
    Player* player_;
    Enemy* enemy_;
    Fight_status fight_control;
public:
    Fight(Player* player, Enemy* enemy);
    ~Fight();
    int retFight_status();
    void action_atack();
    void Fight_update();
};

#endif //RPG_FIGHT_H
