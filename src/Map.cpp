#include "Map.h"

Map::Map(std::vector<std::shared_ptr<Object>> &objects_) {
    std::cout << "MAP CONSTRUCTOR CALLED" << std::endl;
    std::string line;
    std::ifstream myfile ("../game_files/map_template.txt"); 
    int j = 0;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            for(int i = 0; i < Map_size; i++) {
                this->clean_map[j][i] = line[i];
            }
            j++;
        }
        myfile.close();

    } else {
        throw -2;
    }
    Map::fillMap(objects_);
}

void Map::fillMap(std::vector<std::shared_ptr<Object>> &objects_) {
    for(int j = 0; j < Map_size; j++) {
        {
            for(int i = 0; i < Map_size; i++) {
                this->map[j][i] = this->clean_map[j][i];
            }
        }
    }
    for (auto& i : objects_) {
        if (i->retType() == PLAYER) map [i->retPosy()][i->retPosx()] = 'p'; // add player
        if (i->retType() == ENEMY) map [i->retPosy()][i->retPosx()] = 'e'; // add enemies
    }
}

void Map::updateMap(std::vector<std::shared_ptr<Object>> &objects_) {
    Map::fillMap(objects_);
}

int Map::checkField(const int x_, const int y_) const {
    if ( this->map[y_][x_] == '*') {
        return WALL;
    } else if (this->map[y_][x_] == ' ') {
        return FREE;
    } else if (this->map[y_][x_] == 'e') {
        return ENEMY;
    }
    return 99;
}

Map::~Map() {
    std::cout << "MAP DESTRUCTOR CALLED" << std::endl;
}
