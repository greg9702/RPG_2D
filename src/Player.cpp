#include "Player.h"

Player::Player(const int &x_, const int &y_, const char& type_, const int &lvl_, const int& hp_, const int& atk_, const int& arm_, const int& exp_, const int& gold_)
        : Object(x_, y_, type_), Character(lvl_, hp_, atk_, arm_, exp_, gold_) {
//    Equipment.push_back(new Weapon(0,"LITTLE SWORD",'w',5));
//    Equipment.push_back(new Armour(0,"LEATHER COAT",'a',5));
//    Equipment.push_back(new Weapon(10,"TINY AXE",'w',10));
    this->updatePlayer();
}

Player::~Player() {
    std::cout << "Player destructor called" << std::endl;
//    for (auto &i : Equipment) {
//        delete i;
//    }
}

int Player::retPosx() { return this->m_posx; }

int Player::retPosy() { return this->m_posy; }

void Player::movePlayer(const char &button) {
    std::cout << button << std::endl;
    switch (button) {
        case 'a':
            this->m_posx -= 1;
            break;
        case 'd':
            this->m_posx += 1;
            break;
        case 'w':
            this->m_posy -= 1;
            break;
        case 's':
            this->m_posy += 1;
            break;

        default:
            break;
    }
}

std::string Player::showStats() {
//    std::cout << "(" << this->Player::retPosx() << "," << this->Player::retPosy() << ")" << std::endl
//              << "HP: " << this->m_hp << std::endl
//              << "ATACK: " << this->retAtk() << std::endl
//              << "LVL: " << this->m_level << std::endl
//              << "EXP: " << this->m_exp << std::endl
//              << "GOLD: " << this->m_gold << std::endl;
    return ( "(" + std::to_string(this->Player::retPosx()) + "," + std::to_string(this->Player::retPosy()) + ")" );
}


char Player::retType() {
    return 'p';
}

void Player::takeDamage(const int& atack_) {
    this->m_hp = this->m_hp - atack_; //+ this->m_armor + (dynamic_cast<Armour*>(Equipment.at(1)))->retArmArm();
    std::cout << "Enemy atacked for " << atack_ - this->m_armor << std::endl;
}

void Player::updatePlayer() {
    if (this->retHp() <= 0) throw -1;
    //this->m_atack += (dynamic_cast<Weapon*>(Equipment.at(0)))->retWeapAtk();
}

void Player::getLoot(const std::vector<int> &loot_) {
    this->m_exp +=loot_.at(0);
    this->m_gold +=loot_.at(1);
}

int Player::retAtk() {
    return this->m_atack; //+ (dynamic_cast<Weapon*>(Equipment.at(0)))->retWeapAtk();
}

//void Player::showEquipment() {                                              // TODO fix all bugs!!!
//    std::string raw_in;
//    char a;
//    do {
//        printf("\033c");
//        std:: cout << "Your equipment: " << std::endl;
//        for (int i = 0; i < Equipment.size(); ++i) {
//            std::cout << "[" << i + 1 << "] " << Equipment.at(i)->retName() << std::endl;
//        }
//        std::cout << std::endl;
//        std::cout << "Enter q to exit" << std::endl;
//        std::cout << "Enter l to show an item details" << std::endl;
//        std::cout << "Enter u to use an item " << std::endl;
//        std::cout << "Enter d to drop an item " << std::endl;
//        std::cin >> raw_in;
//        a = raw_in.at(0);
//        if (a == 'l') {
//            int  b;                                     // TODO fix this shit
//            do {
//                std::cout << "Enter item number: ";
//                std::cin >> b;
//                std::cout << b << std::endl;
//                if (b > 0 || b <= Equipment.size()) {
////                    std::cout << Equipment.at(b-1)->retType() << std::endl;
//                    if (Equipment.at(b-1)->retType() == 'w') (dynamic_cast<Weapon*>(Equipment.at(b-1)))->showItem();
//                    if (Equipment.at(b-1)->retType() == 'a') (dynamic_cast<Armour*>(Equipment.at(b-1)))->showItem();
//                }
//                getchar();
//                getchar();
//            }while(b <= 0 || b > Equipment.size());
//        }
//        if (a == 'u') {
//            int  b;                                     // TODO fix this shit
//            do {
//                std::cout << "Enter item number: ";
//                std::cin >> b;
//                std::cout << b << std::endl;
//                if (b > 2 || b <= Equipment.size() ) {
//                    if (Equipment.at(b - 1)->retType() == 'w') {
//                        iter_swap(Equipment.begin(), Equipment.begin() + b - 1);
//                    }
//                    if (Equipment.at(b - 1)->retType() == 'a') {
//                        iter_swap(Equipment.begin() + 1, Equipment.begin() + b - 1);
//                    }
//                } else { std::cout << "Item already in use" << std::endl; }
//                getchar();
//                getchar();
//            }while(b <= 0 || b > Equipment.size());
//        }
//        if (a == 'd') {
//            int  b;                                     // TODO fix this shit
//            do {
//                std::cout << "Enter item number: ";
//                std::cin >> b;
//                std::cout << b << std::endl;
//                if (b == 1 || b == 2) {
//                    std::cout << "Can't drop equiped item!" << std::endl;
//                }
//                getchar();
//                getchar();
//            }while(b <= 0 || b > Equipment.size());
//        }
//    } while (a != 'q');
//}