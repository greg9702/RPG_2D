#include <string>
#include "Object.h"


Object::Object(const int &x_, const int &y_, const  char& type_)
        : m_posx(x_), m_posy(y_), m_type(type_) {
    std::cout << "OBJECT CONSTRUCTOR CALLED" << std::endl;
}

Object::~Object() {
    std::cout << "OBJECT DESTRUCTOR CALLED" << std::endl;
}
