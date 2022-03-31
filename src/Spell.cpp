//
// Created by Matthieu Deroir on 31/03/2022.
//

#include "../include/Spell.h"

Spell::Spell(string name, int price, int manaCost, vector<vector<int> > range){
    this->name = name;
    this->price = price;
    this->manaCost = manaCost;
    this->range = range;
}

//Getter & Setter
string Spell::getName(){
    return this->name;
}
void Spell::setName(string name){
    this->name = name;
}


int Spell::getPrice(){
    return this->price;
}
void Spell::setPrice(int price){
    this->price = price;
}


int Spell::getManaCost() {
    return this->manaCost;
}
void Spell::setManaCost(int manaCost){
    this->manaCost = manaCost;
}

vector<vector<int> > Spell::getRange(){
    return this->range;

    mana_cost
    get + nom var = fonction
            fonction camelCase

    getMana_cost // getManaCost ??
}

void Spell::setRange(vector<vector<int> > range){
    this->range = range;
}

//To String
void Spell::toString(){
    cout << "Attaque: " << this->name << "// Price: " << this->price << "$imiam$// Mana cost: " << this->manaCost << endl;
}

//Methods

