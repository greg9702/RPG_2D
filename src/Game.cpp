#include "Game.h"

Game::Game()
        : game_over(false){
    std::cout << "GAME CONSTRUCTOR CALLED" << std::endl;
    player = new Player(1,1,'p', 1, 100, 25, 10, 0, 0);
    objects.push_back(player);
    enemies.push_back(new Enemy(5,5,'e', 1, 55, 10, 5, 40, 10));
    enemies.push_back(new Enemy(3,3,'e',1, 54, 20, 5, 5, 10));
    enemies.push_back(new Enemy(10,3,'e',1, 82, 32, 5, 5, 10));
    for (auto i : enemies) {
        objects.push_back(i);
    }
    map = new Map(objects);
    game_window = new Game_Window();
    game_stage = MAP_VIEW;
    Game::start();
}

Game::~Game() {                                                 //TODO fix mem leak
    std::cout << "GAME DESTRUCTOR CALLED" << std::endl;
    delete game_window;
    delete map;                 // delete map
    for (auto &i : objects) {   // delete all objects on map
        delete i;
    }
}

void Game::start() {

    while (!game_over) {
        Game::draw();
        button = Game::input();
        Game::update(button);
    }
}

void Game::draw() {
    if(game_stage == MAP_VIEW) game_window->drawWindow(map, player);
    if(game_stage == FIGHT_VIEW) game_window->drawWindow(player, enemy);
    if(game_stage == END_SCREEN) game_window->drawWindow();
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
                if (Event.key.code == sf::Keyboard::Num1 ) {
                    return '1';
                }
                if (Event.key.code == sf::Keyboard::Num2 ) {
                    return '2';
                }
                if (Event.key.code == sf::Keyboard::Num2 ) {
                    return '3';
                }
                if (Event.key.code == sf::Keyboard::Num2 ) {
                    return '4';
                }
                if (Event.key.code == sf::Keyboard::Num2 ) {
                    return '5';
                }
            }
        }
   return '-';          // default
}

void Game::update(char& button) {
        Game::action(button);
        player->Player::updatePlayer();
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
            case '0': {
                game_over = true;
                break;
            }
            default:
                break;
        }
        if (map->Map::checkField(newx, newy) == ENEMY) {
            enemy = dynamic_cast<Enemy *>(retObjPointer(objects, newx, newy));
            fight = new Fight(player,enemy);
            game_stage = FIGHT_VIEW;
        }
        if (map->Map::checkField(newx, newy) == FREE) {
            player->Player::movePlayer(button);
        }
    }
    if (game_stage == FIGHT_VIEW) {
        switch (button) {
            case '2': {                   //run away
                game_stage = MAP_VIEW;
                //enemy = nullptr;                              //TODO do I need this?
                delete fight;
                break;
            }
            case '1': {
                fight->action_atack();
                break;
            }
            default:
                break;
        }
        if (fight->retFight_status() == FIGHT_LOST) {
            game_stage = END_SCREEN;
            delete enemy;
            objects.erase(std::remove(objects.begin(), objects.end(), enemy), objects.end());
            enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
            delete fight;
        }
        if (fight->retFight_status() == FIGHT_WON){
            delete enemy;
            objects.erase(std::remove(objects.begin(), objects.end(), enemy), objects.end());
            enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
            delete fight;
            game_stage = MAP_VIEW;
        }
    }
    if (game_stage == END_SCREEN) {
        switch (button) {
            case '0' :
                game_over = true;
        }
    }
}

Object *Game::retObjPointer(std::vector<Object *> &objects_, const int &x_, const int &y_) {
    for (auto i : objects_) {
        if (i->retPosx() == x_ && i->retPosy() == y_) {
            return i;
        }
    }
    return nullptr;
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