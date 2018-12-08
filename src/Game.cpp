#include "Game.h"

Game::Game()
        : game_over(false){
    player = new Player(1,1,'p', 1, 100, 25, 10, 0, 0);
    objects.push_back(player);
    enemy1 = new Enemy(5,5,'e', 1, 55, 20, 5, 5, 10);
    objects.push_back(enemy1);
    enemy2 = new Enemy(3,3,'e',1, 54, 20, 5, 5, 10);
    objects.push_back(enemy2);
    map = new Map(objects);
    game_window = new Game_Window();
    game_stage = MAP_VIEW;
    Game::start();
}

void Game::start() {

    while (!game_over) {
        Game::draw();
        button = Game::input();
        //std::cout << button << std::endl;
        //std::cout << game_stage << std::endl;
        Game::update(button);
    }
}

void Game::draw() {
    if(game_stage == MAP_VIEW) game_window->drawMap(map, player);
    if(game_stage == FIGHT_VIEW) game_window->drawMap(player, enemy);
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
                if (Event.key.code == sf::Keyboard::Q) {
                    return 'q';
                }
            }
        }
   return '-';          // default
}

void Game::update(char& button) {
        Game::action(button);
        player->Player::updatePlayer(); // TODO no need to put this here
        map->Map::updateMap(objects);
}

void Game::action(const char &button_) {
    if (game_stage == MAP_VIEW){
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
            }
            case 'e': {
                //player->showEquipment();
                break;
            }
            case 'q': {
                game_over = true;
                break;
            }
            default:
                break;
        }
        if (map->Map::checkField(newx, newy) == 'e') {
            enemy = dynamic_cast<Enemy *>(retObjPointer(objects, newx, newy));
            fight = new Fight(player,enemy);
            game_stage = FIGHT_VIEW;
        }
        //std::cout << map->Map::checkField(newx, newy);
        if (map->Map::checkField(newx, newy) == 'f') {
            player->Player::movePlayer(button);
        }

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

    if (game_stage == FIGHT_VIEW) {
        std::cout << "FIGHT" << std::endl;
    switch (button) {
        case 'q': {
            fight->setFight(0);
            break;
        }
        default:
            break;
    }
    if (fight->retFight_status()) {
        std::cout << "FIGHT LAST" << std::endl;
    } else {

        delete enemy;
        objects.erase(std::remove(objects.begin(), objects.end(), enemy), objects.end());
        delete fight;
        game_stage = MAP_VIEW;
    }
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