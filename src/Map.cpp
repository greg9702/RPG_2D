#include "Map.h"

Map::Map(std::vector<Object*> &objects_) {
    std::cout << "MAP CONSTRUCTOR CALLED" << std::endl;
    std::string line;
    std::ifstream myfile ("../game_files/map_template.txt"); // TODO move this to game_files folder
    int j = 0;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            for(int i = 0; i < 20; i++) {
                this->clean_map[j][i] = line[i];            // TODO throw error when .at() // X and Y vice versa
            }
            j++;
        }
        myfile.close();

    } else {
        std::cout << "Can't read map file" << std::endl;   // TODO move this to main file
        throw -2;
    }
    Map::fillMap(objects_);
}

void Map::fillMap(std::vector<Object*> &objects_) {
    for(int j = 0; j < 20; j++) {
        {
            for(int i = 0; i < 20; i++) {
                this->map[j][i] = this->clean_map[j][i];
            }
        }
    }
    for (auto& i : objects_) {
        if (i->retType() == 'p') map [i->retPosy()][i->retPosx()] = 'p'; // draw player
        if (i->retType() == 'e') map [i->retPosy()][i->retPosx()] = 'e'; // draw enemies
    }
}

void Map::updateMap(std::vector<Object*> &objects_) {
    Map::fillMap(objects_);
}

int Map::checkField(const int x_, const int y_) {
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
