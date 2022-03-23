//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/Player.h"


Player::Player(string name, int hp = 100, int att = 1, int def = 1, int money = 0, char sprite = '.', int score = 0) {
    this->name = name;
    this->hp = hp;
    this->att = att;
    this->def = def;
    this->money = money;
    this->sprite = sprite;
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

int Player::getAtt() {
    return this->att;
}

void Player::setAtt(int att) {
    this->att = att;
}

int Player::getDef() {
    return this->def;
}

void Player::setDef(int def) {
    this->def = def;
}

int Player::getMoney() {
    return this->money;
}

void Player::setMoney(int money) {
    this->money = money;
}

char Player::getSprite() {
    return this->sprite;
}

void Player::setSprite(char sprite) {
    this->sprite = sprite;
}

int Player::getScore(){
    return this->score;
}

void Player::setScore(int score){
    this->score = score;
}

//To String
void Player::toString() {
    cout << "Player: " << this->name << "// HP: " << this->hp << "// ATT: " << this->att << "// DEF: " << this->def
         << "// MONEY: " << this->money << "// SPRITE: " << this->sprite << endl;
}
// Methods



