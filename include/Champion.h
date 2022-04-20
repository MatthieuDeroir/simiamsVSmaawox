//
// Created by Matthieu Deroir on 31/03/2022.
//

#ifndef SIMIAMSVSMAAWOX_CHAMPION_H
#define SIMIAMSVSMAAWOX_CHAMPION_H

#include "header.h"
#include "Spell.h"

class Champion {
private:
    string name;
    char sprite;
    int att;
    vector<Spell*> spells;
    int base_cost;
    bool current_champ;
public:
    Champion();
    Champion(string name, char sprite, int att, vector<Spell*> spells);

    //Getter & Setter
    int getAtt();
    void setAtt(int att);

    string getName();
    void setName(string name);

    vector<Spell*> getSpells();
    void setSpells(vector<Spell*> spells);

    char getSprite();
    void setSprite(char sprite);

    bool getCurrentChamp();
    void setCurrentChamp(bool current_champ);

    //toString
    void toString();
    //Upgrades
    void upgradeAtt();
};

#endif //SIMIAMSVSMAAWOX_CHAMPION_H
