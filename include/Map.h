#ifndef MAP
#define MAP
#include <iostream>
#include <ctime>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include <fstream>
#include <string>

#define Map_size 20



class Map {
private:
    const static int length{Map_size};
    const static int width{Map_size};
    char clean_map[width][length]; // clean map temaplate
public:
    char map[width][length];
    Map(std::vector<Object*> &objects_);
    ~Map();
    void updateMap(std::vector<Object*> &objects_);
    void fillMap(std::vector<Object*> &objects_);
    int checkField  (const int x_, const int y_) const;     //TODO make handling of default case
};

#endif