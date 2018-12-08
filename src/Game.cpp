#include "Game.h"

Game::Game()
        : game_over(false) {
    player = new Player(1,1,'p', 1, 100, 25, 10, 0, 0);
    objects.push_back(player);
    enemy1 = new Enemy(5,5,'e', 1, 50, 20, 5, 5, 10);
    objects.push_back(enemy1);
    enemy2 = new Enemy(3,3,'e',1, 50, 20, 5, 5, 10);
    objects.push_back(enemy2);
    map = new Map(objects);
    game_window = new Game_Window();
    Game::start();
}

void Game::start() {

    while (!game_over) {
        Game::draw();
        button = Game::input();
        Game::update(button);
    }
}

void Game::draw() {
    button = game_window->drawMap(map, player);
    std::cout << button << std::endl;
}

char Game::input() {
    sf::Event Event;
        while ((game_window->Windowx).pollEvent(Event)) {
            if (Event.type == sf::Event::KeyPressed) {
                if (Event.key.code == sf::Keyboard::Escape) {
                    return '0';
                }
                if (Event.key.code == sf::Keyboard::A) {
                    return 'a';
                }
                if (Event.key.code == sf::Keyboard::W) {
                    return 'w';
                }
                if (Event.key.code == sf::Keyboard::S) {
                    return 's';
                }
                if (Event.key.code == sf::Keyboard::D) {
                    return 'd';
                }
                if (Event.key.code == sf::Keyboard::E) {
                    return 'e';
                }
            }
        }
   return '-';
}

void Game::update(char& button) {

    try {
        Game::action(button);
        player->Player::updatePlayer(); // TODO no need to put this here
        map->Map::updateMap(objects);
    } catch (int exception) {
        if (exception == -1) {
            game_over = true;      //player is dead
        }
        if (exception == -2) {
            game_over = true;
        }
    }
}

void Game::action(const char &button_) {
    if (button_ == 'a' || button_ == 'w' || button_ == 's' || button_ == 'd' || button_ == 'q' || button == 'e') {
        int newx = player->retPosx();
        int newy = player->retPosy();
        switch (button) {
            case 'a': {
                newx--;
                break;
            }
            case 'd': {
                newx++;
                break;
            }
            case 'w': {
                newy--;
                break;
            }
            case 's': {
                newy++;
                break;
            } case 'e': {
                //player->showEquipment();
                break;
            }
            case '0': {
                game_over = true;
            }
            default:
                break;
        }
        std::cout << map->Map::checkField(newx, newy);
        if (map->Map::checkField(newx, newy) == 'f') {
            std::cout << "DOWN " << std::endl;
            player->Player::movePlayer(button);
        }
//        else if (map->Map::checkField(newx, newy) == 'e') {
//            Enemy *enemy = dynamic_cast<Enemy *>(retObjPointer(objects, newx, newy));  //TODO mem leak there // do i need this cast?
            //std::unique_ptr<Fight> ptr(new Fight(player,enemy));
//            Fight *fight = new Fight(player, enemy);                            //TODO smart ptr
//            delete fight;
//            if (enemy->retHp() <= 0) {
//                delete enemy;
//                objects.erase(std::remove(objects.begin(), objects.end(), enemy), objects.end());
//            }
//        }
    }
}

Object *Game::retObjPointer(std::vector<Object *> &objects_, const int &x_, const int &y_) {
    for (auto i : objects_) {
        if (i->retPosx() == x_ && i->retPosy() == y_) {
            return i;
        }
    }
}

Game::~Game() {                                                 //TODO fix mem leak
    std::cout << "GAME DESTROYED" << std::endl;
    delete game_window;
    delete map;                 // delete map
    for (auto &i : objects) {   // delete all objects on map
        delete i;
    }

}

std::string Game::getCurrentTimestamp()                                 //fuction display time
{                                                                       //useful for debugging
    using std::chrono::system_clock;
    auto currentTime = std::chrono::system_clock::now();
    char buffer[80];

    auto transformed = currentTime.time_since_epoch().count() / 1000000;

    auto millis = transformed % 1000;

    std::time_t tt;
    tt = system_clock::to_time_t ( currentTime );
    auto timeinfo = localtime (&tt);
    strftime (buffer,80,"%F %H:%M:%S",timeinfo);
    sprintf(buffer, "%s:%03d",buffer,(int)millis);

    return std::string(buffer);
}