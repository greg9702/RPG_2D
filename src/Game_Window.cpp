#include "Game_Window.h"

Game_Window::Game_Window() {
    std::cout << "WINDOW CONSTRUCTOR CALLED" << std::endl;
    Windowx.create(sf::VideoMode(760,560), "RPG");
    Windowx.setKeyRepeatEnabled(false);
    Windowx.setPosition(sf::Vector2i(50, 50));
    Windowx.setFramerateLimit(60);                  // set FPS

    if(!gTexture.loadFromFile("../game_files/grass.png"))
        std::cout << "Cant load g image " << std::endl;
    if(!pTexture.loadFromFile("../game_files/player.png"))
        std::cout << "Cant load image " << std::endl;
    if(!tTexture.loadFromFile("../game_files/tree.png"))
        std::cout << "Cant load t image " << std::endl;
    if(!eTexture.loadFromFile("../game_files/enemy.png"))
        std::cout << "Cant load e image " << std::endl;

    if (!font.loadFromFile("../game_files/Sansation_Regular.ttf"))
        std::cout << "Error loading font\n" ;
}

Game_Window::~Game_Window() {
    std::cout << "WINDOW DESTRUCTOR CALLED!" << std::endl;
}

void Game_Window::drawWindow(std::unique_ptr<Map> &map_, std::shared_ptr<Player> player_) {                      // MAP VIEW WINDOW
    Windowx.clear();

    treeImage.setTexture(tTexture);
    playerImage.setTexture(pTexture);
    grassImage.setTexture(gTexture);

    sf::Text text;
    text.setFont(font);
    text.setString(player_->showStats());
    text.setCharacterSize(20); // in pixels, not points!
    text.setPosition(40,400);

    enemyImage.setTexture(eTexture);

    int xposition = 0;
    int yposition = 0;

    for (int i = 0; i < Map_size; i++ ) {
        for(int j = 0; j < 2 * Map_size; j++ ) {

            if (map_->map[i][j] == ' ') {
                grassImage.setPosition(xposition, yposition);
                Windowx.draw(grassImage);
            }else if (map_->map[i][j] == '*') {
                treeImage.setPosition(xposition, yposition);
                Windowx.draw(treeImage);
            }else if (map_->map[i][j] == 'p') {
                playerImage.setPosition(xposition, yposition);
                Windowx.draw(playerImage);
            }else if (map_->map[i][j] == 'e') {
                enemyImage.setPosition(xposition, yposition);
                Windowx.draw(enemyImage);
            }
            xposition += 40;
        }
        yposition += 40;
        xposition = 0;
    }
    Windowx.draw(text);
    Windowx.display();
}

void Game_Window::drawWindow(std::shared_ptr<Player> player_, std::shared_ptr<Enemy> enemy_) {                  //FIGHT WINDOW
    Windowx.clear();

    sf::Font font;
    if (!font.loadFromFile("../game_files/Sansation_Regular.ttf"))
    {
        std::cout << "Error loading font\n" ;
    }

    sf::Text instruction_fight;
    instruction_fight.setFont(font);
    instruction_fight.setCharacterSize(20);
    std::string stext = "Enter 1 to atack \nEnter 2 to run away";
    instruction_fight.setString(stext);

    sf::Text text;
    text.setFont(font);
    stext = "\nPLAYER HP: " + std::to_string(player_->retHp()) + "\nENEMY HP: " + std::to_string(enemy_->retHp());
    text.setString(stext);
    text.setCharacterSize(48); // in pixels, not points!
    //text.setStyle(sf::Text::Bold );
    text.setPosition(0,20);
    instruction_fight.setPosition(0,0);
    Windowx.draw(instruction_fight);
    Windowx.draw(text);
    Windowx.display();
}

void Game_Window::drawWindow() {                                             // END GAME WINDOW
    Windowx.clear();

    sf::Text text;
    text.setFont(font);
    std::string stext;
    stext = "YOU ARE DEAD! \nGAME OVER";
    text.setString(stext);
    text.setCharacterSize(48); // in pixels, not points!
    //text.setStyle(sf::Text::Bold );
    text.setPosition(0,0);

    Windowx.draw(text);
    Windowx.display();
}
