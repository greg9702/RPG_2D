#include <iostream>
#include "Game.h"

#if 0
class Base
{
public:
     virtual void function1() { std::cout << "B f1" << std::endl ;};
     virtual void function2() { std::cout << "B f1" << std::endl ;};
     Base() { std::cout << "B C" << std::endl; }
     ~Base() { std::cout << "B D" << std::endl; }
};

class D1: public Base
{
public:
    void function1() override { std::cout << "D1 f1" << std::endl ; };
    D1() { std::cout << "D1 C" << std::endl; }
    ~D1() { std::cout << "D1 D" << std::endl; }

};

class D2: public Base
{
public:
    void function2() override { std::cout << "D2 f2" << std::endl ;};
};

int main() {

    D1 raz;
    Base * ptr;
    ptr = &raz;
    ptr->function1();
    ptr->function2();


    return 0;
}

#endif

#if 1

int main () {
    Game* game = new Game;
    delete game;
    return 0;
}

#endif


#if 0

class Base {
public:
    Base() {std::cout << "Base constructor called! " << std::endl; }
    ~Base() {std::cout << "Base destructor called! " << std::endl; }
    virtual void Elo() = 0;
};


class Derived : public Base {
public:
    Derived() {std::cout << "Derived constructor called! " << std::endl; }
    ~Derived() {std::cout << "Derived destructor called! " << std::endl; }
    void Elo() override { std::cout << "ELO" << std::endl; }
};

int main () {
    {
        //std::vector<Base> cos;
        Derived xd;
        //cos.push_back(xd);
    }
    getchar();
}

#endif