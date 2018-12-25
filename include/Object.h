#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

class Object {  // this class is only an interface for all object on map
protected:
    int posx;
    int posy;
    char type; // keep information about object // all parameters are set by constructor
public:
    Object(const int& x_, const int& y_, const char& typ_);
    virtual ~Object() = 0;
    virtual int retPosx() = 0;
    virtual int retPosy() = 0; // show position
    virtual char retType() = 0;
};

#endif