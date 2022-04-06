//
// Created by Matthieu Deroir on 31/03/2022.
//

#include "../include/Champion.h"

Champion::Champion(string name, int att, vector<Spell*> spells) {
    this->att = att;
    this->name = name;
    this->spells = spells;
}

//Getter & Setter
void Champion::setAtt(int att) {
    this->att = att;

}
int Champion::getAtt() {
    return this->att;
}

void Champion::setName(string name) {
    this->name = name;
}
string Champion::getName() {
    return this->name;
}

void Champion::setSpells(vector<Spell*> spells) {
    this->spells = spells;
}
vector<Spell*> Champion::getSpells() {
    return this->spells;
}

//toString
void Champion::toString(){
    cout << "Name : " << this->name << "// Attack :" << this->att << endl;
    for (int i = 0; i < this->spells.size(); i++){
        cout << "Spell " << i+1 << " : " << endl;
        this->spells[i]->toString();
    }
}

//method
void Champion::upgradeAtt(){
    setAtt(this->att++);
}