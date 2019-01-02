#include "Game.h"

int main () {
    try {
        std::unique_ptr<Game> game(new Game());
    }catch (int my_exc) {
        if (my_exc == -1) std::cout << "Can't load graphic" << std::endl;
        if (my_exc == -2) std::cout << "Can't load map" << std::endl;
    }
    return 0;
}
