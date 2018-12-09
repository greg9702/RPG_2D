#ifndef MAP
#define MAP
#include <iostream>
#include <ctime>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include <fstream>
#include <string>

enum Map_field {
    WALL,
    FREE,
    ENEMY
};

class Map {
private:
    const static int length{20};
    const static int width{20};
    char clean_map[width][length];

public:
    char map[width][length];
    Map(std::vector<Object*> &objects_);
    ~Map();
    void updateMap(std::vector<Object*> &objects_);
    void fillMap(std::vector<Object*> &objects_);
    int checkField(const int x_, const int y_);     //TODO make handling of default case
};

#endif