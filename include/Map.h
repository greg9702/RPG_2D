#ifndef MAP
#define MAP
#include <iostream>
#include <ctime>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include <fstream>
#include <string>

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
    char checkField(const int& x_, const int& y_);
    void drawMap();
    void fillMap(std::vector<Object*> &objects_);
};

#endif