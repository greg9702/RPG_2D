//
// Created by greg9702 on 12/8/18.
//

#ifndef FIGHT_H
#define FIGHT_H

#include "Player.h"
#include "Enemy.h"

enum Fight_status {
    FIGHT_IN_PROG,
    FIGHT_WON,
    RUN_AWAY,
    FIGHT_LOST
};

class Fight {
private:
    std::shared_ptr<Player> player_;
    std::shared_ptr<Enemy> enemy_;
    int fight_control;
public:
    Fight(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy);
    ~Fight();
    int retFight_status();
    void action_attack();
    void Fight_update();
    void setStatRunAway();
};

#endif //RPG_FIGHT_H
