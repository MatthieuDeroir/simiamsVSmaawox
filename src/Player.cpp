//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/Player.h"


Player::Player(string name, int hp = 100, int money = 0, int mana = 100, int score = 0) {
    this->name = name;
    this->hp = hp;
    this->money = money;
    this->mana = mana;
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

int Player::getMana() {
    return this->mana;
}

void Player::setMana(int mana) {
    this->mana = mana;
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

void Player::takeDamage(int damage){
    if (this->hp <= damage){
        cout << "Game Over" << endl;
    } else{
        this->hp -= damage;
    }
}

void Player::buy(int price){
    if (this->money < price){
        cout << "$imiam$ insuffisant" << endl;
    } else{
        this->money -= price;
    }
}

void Player::spendMana(int mana){
    if (this->mana < mana){
        cout << "Manwox insuffisant" << endl;
    } else{
        this->mana -= mana;
    }
}



