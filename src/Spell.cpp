//
// Created by Matthieu Deroir on 31/03/2022.
//

#include "../include/Spell.h"
#include "../include/header.h"

Spell::Spell(string name, int price, int manaCost, vector<vector<int> > base_range) {
    this->name = name;
    this->price = price;
    this->manaCost = manaCost;
    this->base_range = base_range;
    this->range = rwVector(0, base_range);
}

//Getter & Setter
string Spell::getName() {
    return this->name;
}

void Spell::setName(string name) {
    this->name = name;
}


int Spell::getPrice() {
    return this->price;
}

void Spell::setPrice(int price) {
    this->price = price;
}


int Spell::getManaCost() {
    return this->manaCost;
}

void Spell::setManaCost(int manaCost) {
    this->manaCost = manaCost;
}

vector<vector<int> > Spell::getRange() {
    return this->range;
}

void Spell::setRange(vector<vector<int> > range) {
    this->range = range;
}


vector<vector<int> > Spell::getBaseRange() {
    return this->base_range;
}

void Spell::setBaseRange(vector<vector<int> > base_range) {
    this->base_range = base_range;
}

//To String
void Spell::toString() {
    cout << "Name : " << this->name << "// Price: " << this->price << "$imiam$// Mana cost: " << this->manaCost << endl;
}

//Methods
void Spell::upgradeSpell() {
    vector<vector<int> > newRange(9, vector<int>(3, 0));
    for (int i = 0; i < this->getBaseRange().size(); i++) {
        for (int j = 0; j < this->getBaseRange()[i].size(); j++) {
            if (this->getBaseRange()[i][j] > 0){
                newRange[i][j] = this->getBaseRange()[i][j] + 1;
            }
            else {
                newRange[i][j] = 0;
            }

        }
    }
    this->setBaseRange(newRange);
    setManaCost(balanceManaCost(this->getBaseRange()));
};

