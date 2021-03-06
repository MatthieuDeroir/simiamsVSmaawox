//
// Created by Matthieu Deroir on 31/03/2022.
//

#ifndef SIMIAMSVSMAAWOX_SPELL_H
#define SIMIAMSVSMAAWOX_SPELL_H

#include "header.h"

class Spell{
private:
    string name;
    int price;
    int manaCost;
    vector<vector<int> > range;
    vector<vector<int> > base_range;

public:
    //Class constructor
    Spell(string name, int price, int mana_cost, vector<vector<int> > base_range);

    //Getter & Setter
    string getName();
    void setName(string name);

    int getPrice();
    void setPrice(int price);

    int getManaCost();
    void setManaCost(int manaCost);

    vector<vector<int> > getRange();
    void setRange(vector<vector<int> > range);

    vector<vector<int> > getBaseRange();
    void setBaseRange(vector<vector<int> > base_range);

    //toString
    void toString();
    //Methods
    void upgradeSpell();
};


#endif //SIMIAMSVSMAAWOX_SPELL_H
