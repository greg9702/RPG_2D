#include <string>
#include "Object.h"


Object::Object(const int &x_, const int &y_, const  char& type_)
        : posx(x_), posy(y_), type(type_) {
    std::cout << "OBJECT CONSTRUCTOR CALLED" << std::endl;
}

Object::~Object() {
    std::cout << "OBJECT DESTRUCTOR CALLED" << std::endl;
}
