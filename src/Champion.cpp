//
// Created by Matthieu Deroir on 31/03/2022.
//

#include "../include/Champion.h"

Champion::Champion(string name, char sprite, int att, vector<Spell*> spells) {
    this->sprite = sprite;
    this->att = att;
    this->name = name;
    this->spells = spells;
    this->current_champ = false;
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

char Champion::getSprite(){
    return this->sprite;
}
void Champion::setSprite(char sprite){
    this->sprite = sprite;
}

bool Champion::getCurrentChamp(){
    return this->current_champ;
}
void Champion::setCurrentChamp(bool current_champ){
    this->current_champ = current_champ;
}


//toString
void Champion::toString(){
    cout << "Name : " << this->name << "// Attack :" << this->att << endl;
//    for (int i = 0; i < this->spells.size(); i++){
//        cout << "Spell " << i+1 << " : " << endl;
//        this->spells[i]->toString();
//    }
}

//method
void Champion::upgradeAtt(){
    setAtt(this->att+1);
}