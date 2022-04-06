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
    Champion();
};

#endif //SIMIAMSVSMAAWOX_CHAMPION_H
