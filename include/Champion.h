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
    int att;
    vector<Spell*> spells;
public:
    Champion(string name, int att, vector<Spell*> spells);

    //Getter & Setter
    int getAtt();
    void setAtt(int att);

    string getName();
    void setName(string name);

    vector<Spell*> getSpells();
    void setSpells(vector<Spell*> spells);

    //toString
    void toString();
    //Upgrades
    void upgradeAtt();
};

#endif //SIMIAMSVSMAAWOX_CHAMPION_H
