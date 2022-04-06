//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/header.h"
#include "../include/Player.h"


Player::Player(string name, int hp, int money, int mana, int score, vector<Champion*> champs) {
    this->name = name;
    this->max_hp = hp;
    this->hp = hp;
    this->def = 0;
    this->money = money;
    this->mana = mana;
    this->max_mana = mana;
    this->mana_regen = 1;
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

int Player::getDef(){
    return this->def;
}
void Player::setDef(int def){
    this->def = def;
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

int Player::getMaxMana() {
    return this->max_mana;
}
void Player::setMaxMana(int max_mana) {
    this->max_mana = max_mana;
}

int Player::getManaRegen() {
    return this->mana_regen;
}
void Player::setManaRegen(int mana_regen) {
    this->mana = mana_regen;
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
    cout << "Player: " << this->name << "// HP: " << this->hp << "// MANA: " << this->mana << "// MONEY: " << this->money << endl;

    for (int i = 0; i < this->champs.size(); i++){
        cout << "Champion "<< i+1 << " : " << endl;
        champs[i]->toString();
    }
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
        cout << "Manawox insuffisant" << endl;
    } else{
        this->mana -= mana;
    }
}

//Upgrades
//Upgrades
void Player::upgradeDef(){
    this->def++;
}
void Player::upgradeHpMax(){
    this->setMaxHp(this->getMaxHp()+10);
}
void Player::upgradeManaMax(){
    this->setMaxHp(this->getMaxMana()+10);
}
void Player::upgradeManaRegen(){
    this->setManaRegen(this->getManaRegen()+1);
}

//Regen
void Player::regenHp(){
    this->setHp(getHp() + 10);
    if (this->getHp() > this->getMaxHp())
        this->setHp(this->getMaxHp());
}
void Player::regenMana(){
    this->setMana(this->getMana() + 10);
    if (this->getMana() > this->getMaxMana())
        this->setMana(this->getMaxMana());
}




