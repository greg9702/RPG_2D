#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <memory>
enum Object_type {
    WALL,
    FREE,
    ENEMY,
    PLAYER
};

class Object {  // this class is only an interface for all object on map
protected:
    int posx;
    int posy;
    int type; // keep information about object // all parameters are set by constructor
public:
    Object(const int& x_, const int& y_, const int& typ_);
    virtual ~Object() = 0;
    virtual int retPosx() const = 0;
    virtual int retPosy() const = 0; // return position
    virtual int retType() const = 0;
};

#endif
