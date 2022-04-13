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

    //const definition
    this->MANA_BASE_COST = 0;
    this->MANA_REGEN_BASE_COST = 0;
    this->MANA_BASE_UP = 0;
    this->MANA_REGEN_BASE_UP = 0;
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

void Player::takeDamage(int dmg, int round){

    if (this->hp <= dmg){
        cout << "Vous subissez " << RED << dmg << RESET << " dégats !"  << endl;
        setHp(getHp() - dmg);
        cout << "Game Over" << endl; //TODO GAME OVER SCREEN
    } else if (dmg > 0){
        cout << "Vous subissez " << RED << dmg << RESET << " dégats !"  << endl;
        setHp(getHp() - dmg);
    }
    else if (round != 1)
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

void Player::rangeUpdate(Champion* champ1, Champion* champ2){

    vector<vector<int> > newRange;

    auto it1 = find(this->getChampions().begin(), this->getChampions().end(), champ1);
    int mul1 = distance(this->getChampions().begin(), it1);

    auto it2 = find(this->getChampions().begin(), this->getChampions().end(), champ1);
    int mul2 = distance(this->getChampions().begin(), it2);

//    for (int y = 0; y < champ1->getSpells().size(); y++){
//        for (int i = 0; i < champ1->getSpells()[y]->getRange().size(); i++){
//            for (int j = 0; j < champ1->getSpells()[y]->getRange()[i].size(); j++){
//                if (j/3 == mul2){
//                        for (int i1 = 0; i < champ1->getSpells()[y]->getRange().size(); i++){
//                            for (int j1 = 0; j < champ1->getSpells()[y]->getRange()[i].size(); j++){
//                                if (j1/3 == mul1){
//                                    cout << champ1->getSpells()[y]->getRange()[i1][j1] << champ1->getSpells()[y]->getRange()[i][j] << endl;
//                                    champ1->getSpells()[y]->getRange()[i1][j1] = champ1->getSpells()[y]->getRange()[i][j];
//                                    cout << champ1->getSpells()[y]->getRange()[i1][j1] << champ1->getSpells()[y]->getRange()[i][j] << endl;
//                                }
//                            }
//                        }
//                }
//            }
//        }
//    }
//    for (int y = 0; y < champ2->getSpells().size(); y++){
//        for (int i = 0; i < champ2->getSpells()[y]->getRange().size(); i++){
//            for (int j = 0; j < champ2->getSpells()[y]->getRange()[i].size(); j++){
//                if (j/3 == mul1){
//                    for (int i1 = 0; i < champ2->getSpells()[y]->getRange().size(); i++){
//                        for (int j1 = 0; j < champ2->getSpells()[y]->getRange()[i].size(); j++){
//                            if (j1/3 == mul2){
//                                champ2->getSpells()[y]->getRange()[i1][j1] = champ2->getSpells()[y]->getRange()[i][j];
//
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }

}

void Player::swapChamp(char champOrig, char champDest){
    int orig;
    int dest;
    for (int i = 0; i < this->champs.size(); i++){
        if (champs[i]->getSprite() == champDest){
            orig = i;
        }
    }
    for (int j = 0; j < this->champs.size(); j++){
        if (champs[j]->getSprite() == champOrig) {
            dest = j;
        }
    }
    swap(champs[orig], champs[dest]);
    rangeUpdate(champs[orig], champs[dest]);
    cout << YELLOW << champs[dest]->getName() << RESET << " a changé de position avec " << YELLOW << champs[orig]->getName() << RESET << endl;
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
    if (this->getManaRegen() + this->getMana() <= this->getMaxMana()) {
        this->setMana(this->getMana() + this->getManaRegen());
    }else if (this->getManaRegen() + this->getMana() > this->getMaxMana()) {
        this->setMana(this->getMaxMana());
    }else if (this->getMana() > this->getMaxMana())
        this->setMana(this->getMaxMana());
}





