//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/header.h"
#include "../include/Player.h"
#include "../include/defines.h"

Player::Player(){

}

Player::Player(string name, int hp, int money, int mana, int mana_regen, int score, vector<Champion *> champs) {
    this->name = name;
    this->max_hp = hp;
    this->hp = hp;
    this->def = 0;
    this->money = money;
    this->mana = mana;
    this->max_mana = mana;
    this->mana_regen = mana_regen;
    this->score = score;
    this->champs = champs;
    this->gameOver = 0;

    //const definition
    this->MANA_BASE = mana;
    this->MANA_REGEN_BASE = mana_regen;

    this->MANA_BASE_COST = 10;
    this->MANA_REGEN_BASE_COST = 10;
    this->MANA_BASE_UP = 10;
    this->MANA_REGEN_BASE_UP = 10;

    this->HP_BASE = hp;

    this->HP_BASE_COST = 10;
    this->HP_REGEN_BASE_COST = 10;
    this->HP_BASE_UP = 10;
    this->HP_REGEN_BASE_UP = 10;

    //potion cost
    this->HP_POTION_10 = 10;
    this->HP_POTION_50 = 50;
    this->HP_POTION_MAX = this->max_hp;

    this->MANA_POTION_MAX = this->max_mana;
}

Player* Player::playerInitialization() {
    int MAX_CHAMP = 3;
    string user_choice = "0";
    vector<Champion *> champs = champInitialization();
    vector<Champion *> user_champs;
    string username;

    cout << "Veuillez saisir un" << MAGENTA << " pseudo " << RESET << ": " << endl;
    cin >> username;
    getline(cin, username);

    for (int i = 0; i < MAX_CHAMP; i++) {
        do  {
            cout << "Selectonner votre champion numéro " << i + 1 << " : " << endl;
            for (int j = 0; j < champs.size(); j++) {
                cout << j + 1 << " - " << champs[j]->getName() << endl;
            }
            cin >> user_choice;
        } while (!isdigit(user_choice[0]));
        user_champs.push_back(champs[stoi(user_choice) - 1]);
        champs.erase(find(champs.begin(), champs.end(), champs[stoi(user_choice) - 1]));
        user_choice = "0";
    }

    Player *player = new Player(username, 30, 100, 100, 10, 0, user_champs);

    return player;

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

int Player::getMaxHp() {
    return this->max_hp;
}

void Player::setMaxHp(int max_hp) {
    this->max_hp = max_hp;
}


int Player::getMaxHpBaseCost() {
    return this->HP_BASE_COST;
}

int Player::getHpRegenBaseCost() {
    return this->HP_REGEN_BASE_COST;
}

int Player::getMaxHpBaseUp() {
    return this->HP_BASE_UP;
}

int Player::getHpRegenBaseUp() {
    return this->HP_REGEN_BASE_UP;
}

int Player::getManaBase(){
    return this->HP_BASE;
}

int Player::getManaRegenBase(){
    return this->MANA_REGEN_BASE;
}

int Player::getHpBase(){
    return this->HP_BASE;
}

int Player::getHpPotion10() {
    return this->HP_POTION_10;
}int Player::getHpPotion50() {
    return this->HP_POTION_50;
}int Player::getHpPotionMax() {
    return this->HP_POTION_MAX;
}

int Player::getManaPotion(){
    return this->MANA_POTION_MAX;
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

int Player::getMana() {
    return this->mana;
}

void Player::setMana(int mana) {
    this->mana = mana;
}

int Player::getManaRegen() {
    return this->mana_regen;
}
void Player::setManaRegen(int mana_regen) {
    this->mana_regen = mana_regen;
}

int Player::getMaxMana() {
    return this->max_mana;
}
void Player::setMaxMana(int max_mana) {
    this->max_mana = max_mana;
}


int Player::getMaxManaBaseCost() {
    return this->MANA_BASE_COST;
}

int Player::getManaRegenBaseCost() {
    return this->MANA_REGEN_BASE_COST;
}

int Player::getMaxManaBaseUp() {
    return this->MANA_BASE_UP;
}

int Player::getManaRegenBaseUp() {
    return this->MANA_REGEN_BASE_UP;
}


int Player::getScore() {
    return this->score;
}

void Player::setScore(int score) {
    this->score = score;
}

vector<Champion *> Player::getChampions() {
    return this->champs;
}

void Player::setChampions(vector<Champion *> champs) {
    this->champs = champs;
}

int Player::getGameOver() {
    return this->gameOver;
}

void Player::setGameOver(int gameOver) {
    this->gameOver = gameOver;
}

//To String
void Player::toString() {
    cout << "Player: " << this->name << "// HP: " << this->hp << "// MANA: " << this->mana << "// MONEY: "
         << this->money << endl;

    for (int i = 0; i < this->champs.size(); i++) {
        cout << "Champion " << i + 1 << " : " << endl;
        champs[i]->toString();
    }
}

// Methods

void Player::takeDamage(int dmg, int round) {

    if (dmg > 0) {
        cout << "Vous subissez " << RED << dmg << RESET << " dégats !" << endl;
        setHp(getHp() - dmg);

    } else if (round != 1) {
        cout << "Vous ne subissez " << GREEN << "aucun " << RESET << "dégats !" << endl;
    }
    if (this->hp <= 0) {
        this->gameOver = 1;
        setHp(0);
    }
}

void Player::spendMoney(int price) {
    if (this->money < price) {
        cout << "$imiam$ insuffisant" << endl;
    } else {
        this->money -= price;
    }
}

void Player::spendMana(int mana) {
    if (this->mana < mana) {
        cout << "Manawox insuffisant" << endl;
    } else {
        this->mana -= mana;
    }
}


void Player::rangeUpdate() {
    for (int i = 0; i < this->getChampions().size(); i++) {
        for (int y = 0; y < this->getChampions()[i]->getSpells().size(); y++) {
            this->getChampions()[i]->getSpells()[y]->setRange(
                    rwVector(i, this->getChampions()[i]->getSpells()[y]->getBaseRange()));
        }
    }
}

void Player::swapChamp(char champOrig, char champDest) {
    int orig;
    int dest;
    for (int i = 0; i < this->champs.size(); i++) {
        if (champs[i]->getSprite() == champDest) {
            orig = i;
        }
    }
    for (int j = 0; j < this->champs.size(); j++) {
        if (champs[j]->getSprite() == champOrig) {
            dest = j;
        }
    }
    swap(champs[orig], champs[dest]);
    cout << YELLOW << champs[dest]->getName() << RESET << " a changé de position avec " << YELLOW
         << champs[orig]->getName() << RESET << endl;
}

//Upgrades
//Upgrades
void Player::upgradeDef() {
    this->def++;
}

void Player::upgradeHpMax() {
    this->setMaxHp(this->getMaxHp() + 10);
}

void Player::upgradeManaMax() {
    this->setMaxHp(this->getMaxMana() + 10);
}

void Player::upgradeManaRegen() {
    this->setManaRegen(this->getManaRegen() + 1);
}

//Regen
void Player::regenHp() {
    this->setHp(getHp() + 10);
    if (this->getHp() > this->getMaxHp())
        this->setHp(this->getMaxHp());
}

void Player::regenMana() {
    if (this->getManaRegen() + this->getMana() <= this->getMaxMana()) {
        this->setMana(this->getMana() + this->getManaRegen());
    } else if (this->getManaRegen() + this->getMana() > this->getMaxMana()) {
        this->setMana(this->getMaxMana());
    } else if (this->getMana() > this->getMaxMana())
        this->setMana(this->getMaxMana());
}





