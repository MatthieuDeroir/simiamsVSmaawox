//
// Created by Matthieu Deroir on 06/04/2022.
//

#include "../include/header.h"
#include "../include/Spell.h"
#include "../include/Champion.h"
#include "../include/Player.h"

static vector<vector<vector<int> > > rangesInitialization(){
    vector<vector<vector<int> > > ranges;

    //range sorts mage
    vector<vector<int> > range_m_1 = {
            { 2, 2, 2, 0, 0, 0, 0, 0, 0 },
            { 2, 3, 2, 0, 0, 0, 0, 0, 0 },
            { 2, 2, 2, 0, 0, 0, 0, 0, 0 },
            { 0, 1, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 1, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 1, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 1, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 1, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 1, 0, 0, 0, 0, 0, 0, 0 },
    };

    vector<vector<int> > range_m_2 = {
            { 0, 2, 0, 0, 0, 0, 0, 0, 0 },
            { 2, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 2, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 2, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 2, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 2, 0, 0, 0, 0, 0, 0 },
            { 0, 2, 0, 0, 0, 0, 0, 0, 0 },
            { 2, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 2, 0, 0, 0, 0, 0, 0, 0 },
    };
    vector<vector<int> > range_m_3 = {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 2, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 2, 0, 0, 0, 0, 0, 0, 0 },
            { 2, 3, 2, 0, 0, 0, 0, 0, 0 },
            { 0, 2, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 2, 0, 0, 0, 0, 0, 0, 0 },
            { 2, 3, 2, 0, 0, 0, 0, 0, 0 },
            { 0, 2, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 2, 0, 0, 0, 0, 0, 0, 0 },
    };
    vector<vector<int> > range_m_4 = {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 1, 1, 1, 0, 0, 0, 0, 0, 0 },
            { 1, 1, 1, 0, 0, 0, 0, 0, 0 },
            { 2, 2, 2, 0, 0, 0, 0, 0, 0 },
            { 2, 2, 2, 0, 0, 0, 0, 0, 0 },
            { 3, 3, 3, 0, 0, 0, 0, 0, 0 },
            { 3, 3, 3, 0, 0, 0, 0, 0, 0 },
            { 4, 4, 4, 0, 0, 0, 0, 0, 0 },
            { 4, 4, 4, 0, 0, 0, 0, 0, 0 },
    };

    //range sorts warrior
    vector<vector<int> > range_w_1 = {
            { 0, 0, 0, 0, 3, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 3, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 3, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 3, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 3, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 3, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 3, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 3, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 3, 0, 0, 0, 0 },
    };
    vector<vector<int> > range_w_2 = {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 3, 3, 3, 0, 0, 0 },
            { 0, 0, 0, 5, 5, 5, 0, 0, 0 },
    };
    vector<vector<int> > range_w_3 = {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 5, 0, 0, 0, 0 },
            { 0, 0, 0, 7, 7, 7, 0, 0, 0 },
    };
    vector<vector<int> > range_w_4 = {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 2, 0, 2, 0, 0, 0 },
            { 0, 0, 0, 2, 0, 2, 0, 0, 0 },
            { 0, 0, 0, 2, 0, 2, 0, 0, 0 },
            { 0, 0, 0, 2, 1, 2, 0, 0, 0 },
            { 0, 0, 0, 2, 1, 2, 0, 0, 0 },
    };

    //range sorts archer;
    vector<vector<int> > range_a_1 = {
            { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
    };
    vector<vector<int> > range_a_2 = {
            { 0, 0, 0, 0, 0, 0, 3, 5, 3 },
            { 0, 0, 0, 0, 0, 0, 0, 5, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 5, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 5, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 5, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 5, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 5, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 5, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 5, 0 },
    };
    vector<vector<int> > range_a_3 = {
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 2, 0 },
            { 0, 0, 0, 0, 0, 0, 3, 3, 3 },
    };
    vector<vector<int> > range_a_4 = {
            { 0, 0, 0, 0, 0, 0, 3, 4, 3 },
            { 0, 0, 0, 0, 0, 0, 2, 3, 2 },
            { 0, 0, 0, 0, 0, 0, 2, 3, 2 },
            { 0, 0, 0, 0, 0, 0, 2, 3, 2 },
            { 0, 0, 0, 0, 0, 0, 2, 3, 2 },
            { 0, 0, 0, 0, 0, 0, 1, 2, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 2, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 2, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 2, 1 },
    };

    ranges.push_back(range_m_1);
    ranges.push_back(range_m_2);
    ranges.push_back(range_m_3);
    ranges.push_back(range_m_4);

    ranges.push_back(range_w_1);
    ranges.push_back(range_w_2);
    ranges.push_back(range_w_3);
    ranges.push_back(range_w_4);

    ranges.push_back(range_a_1);
    ranges.push_back(range_a_2);
    ranges.push_back(range_a_3);
    ranges.push_back(range_a_4);

    return ranges;
}

static vector<vector<Spell*> > spellInitialization()
{

    //TODO : coup en mana pondéré par le total de points d'un sort
    vector<vector<vector<int> > > ranges = rangesInitialization();
    vector<vector<Spell*> > spells;
    vector<Spell*> spells_m;
    vector<Spell*> spells_w;
    vector<Spell*> spells_a;

    //mage spells
    Spell* spell_m_1 = new Spell("Boule de feu", 100, count_vec(ranges[0]), ranges[0]);
    Spell* spell_m_2 = new Spell("Foudroiement", 100, count_vec(ranges[1]), ranges[1]);
    Spell* spell_m_3 = new Spell("Blizzard", 100, count_vec(ranges[2]), ranges[2]);
    Spell* spell_m_4 = new Spell("Raz-de-Marée", 100, count_vec(ranges[3]), ranges[3]);

    //warrior spells
    Spell* spell_w_1 = new Spell("Berzerk", 100, count_vec(ranges[4]), ranges[4]);
    Spell* spell_w_2 = new Spell("Tournoiement de hache", 100, count_vec(ranges[5]), ranges[5]);
    Spell* spell_w_3 = new Spell("Coup de boule", 100, count_vec(ranges[6]), ranges[6]);
    Spell* spell_w_4 = new Spell("Furie sanguinaire", 100, count_vec(ranges[7]), ranges[7]);

    //archer spells
    Spell* spell_a_1 = new Spell("Volée de fleches", 100, count_vec(ranges[8]), ranges[8]);
    Spell* spell_a_2 = new Spell("Tir de précision", 100, count_vec(ranges[9]), ranges[9]);
    Spell* spell_a_3 = new Spell("Coup de dague", 100, count_vec(ranges[10]), ranges[10]);
    Spell* spell_a_4 = new Spell("Fleches enflammées", 100, count_vec(ranges[11]), ranges[11]);


    spells_m.push_back(spell_m_1);
    spells_m.push_back(spell_m_2);
    spells_m.push_back(spell_m_3);
    spells_m.push_back(spell_m_4);

    spells_w.push_back(spell_w_1);
    spells_w.push_back(spell_w_2);
    spells_w.push_back(spell_w_3);
    spells_w.push_back(spell_w_4);

    spells_a.push_back(spell_a_1);
    spells_a.push_back(spell_a_2);
    spells_a.push_back(spell_a_3);
    spells_a.push_back(spell_a_4);

    spells.push_back(spells_m);
    spells.push_back(spells_w);
    spells.push_back(spells_a);

    return spells;
}

vector<Champion*> champInitialization(){
    vector<Champion*> champions;
    vector<vector<Spell*> > spells = spellInitialization();

    Champion* champ_mage = new Champion("Mage", 1, spells[0]);

    Champion* champ_warrior = new Champion("Warrior", 1, spells[1]);

    Champion* champ_archer = new Champion("Archer", 1, spells[2]);

    champions.push_back(champ_mage);
    champions.push_back(champ_warrior);
    champions.push_back(champ_archer);

    return champions;
}

Player* playerInitialization(){
    vector<Champion*> champs = champInitialization();

    string username;
    cout << "Saisissez un nom : " << endl;
    cin >> username;
    Player* player = new Player(username, 30, 0, 100, 0, champs);

    return player;

}


