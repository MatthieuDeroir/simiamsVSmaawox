//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/Player.h"


Player::Player(string name, int hp = 100, int att = 1, int def = 1, int money = 0, char sprite = '.', int score = 0) {
    this->name = name;
    this->hp = hp;
    this->money = money;
    this->score = score;
}


// Getter & Setter
string Player::getName() {
    return this->name;
}

void Player::setName(string name) {
    this->name = name;
}

int Player::getHp() {
    return this->hp;
}

void Player::setHp(int hp) {
    this->hp = hp;
}

int Player::getMoney() {
    return this->money;
}

void Player::setMoney(int money) {
    this->money = money;
}

int Player::getScore(){
    return this->score;
}

void Player::setScore(int score){
    this->score = score;
}

//To String
void Player::toString() {
    cout << "Player: " << this->name << "// HP: " << this->hp << "// MONEY: " << this->money << endl;
}
// Methods



