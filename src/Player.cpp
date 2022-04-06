//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/header.h"
#include "../include/Player.h"


Player::Player(string name, int hp, int money, int mana, int score, vector<Champion*> champs) {
    this->name = name;
    this->max_hp = hp;
    this->hp = hp;
    this->money = money;
    this->mana = mana;
    this->score = score;
    this->champs = champs;
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

int Player::getMaxHp(){
    return this->max_hp;
}

void Player::setMaxHp(int max_hp){
    this->max_hp = max_hp;
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

vector<Champion*> Player::getChampions(){
    return this->champs;
}

void Player::setChampions(vector<Champion*> champs){
    this->champs = champs;
}

//To String
void Player::toString() {
    cout << "Player: " << this->name << "// HP: " << this->hp << "// MONEY: " << this->money << endl;
}

// Methods

void Player::takeDamage(int dmg){

    if (this->hp <= dmg){
        cout << "Vous subissez " << RED << dmg << RESET << " dégats !"  << endl;
        setHp(getHp() - dmg);
        cout << "Game Over" << endl; //TODO GAME OVER SCREEN
    } else if (dmg > 0){
        cout << "Vous subissez " << RED << dmg << RESET << " dégats !"  << endl;
        setHp(getHp() - dmg);
    }
    else
    {
        cout << "Vous ne subissez " << GREEN << "aucun " << RESET << "dégats !"  << endl;
    }

    if (this->hp < 0)
        setHp(0);
    wait();
}

void Player::spendMoney(int price){
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



