//
// Created by Matthieu Deroir on 06/04/2022.
//

#include "../include/header.h"
#include "../include/Spell.h"
#include "../include/Champion.h"
#include "../include/Player.h"

//Spell range and damage creation template
//vector<vector<int> > range_*_1 = {
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//};
//
//vector<vector<int> > range_*_2 = {
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//};
//vector<vector<int> > range_*_3 = {
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//};
//vector<vector<int> > range_*_4 = {
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//        { 0, 0, 0},
//};
//ranges.push_back(range_*_1);
//ranges.push_back(range_*_2);
//ranges.push_back(range_*_3);
//ranges.push_back(range_*_4);

static vector<vector<vector<int> > > rangesInitialization() {
    vector<vector<vector<int> > > ranges;

    //range sorts mage
    vector<vector<int> > range_m_1 = {
            {2, 2, 2},
            {2, 3, 2},
            {2, 2, 2},
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
            {0, 1, 0},
    };

    vector<vector<int> > range_m_2 = {
            {0, 2, 0},
            {0, 0, 2},
            {0, 2, 0},
            {2, 0, 0},
            {0, 2, 0},
            {0, 0, 2},
            {0, 2, 0},
            {2, 0, 0},
            {0, 2, 0},
    };
    vector<vector<int> > range_m_3 = {
            {2, 3, 2},
            {0, 2, 0},
            {0, 2, 0},
            {2, 3, 2},
            {0, 2, 0},
            {0, 2, 0},
            {2, 3, 2},
            {0, 2, 0},
            {0, 2, 0},
    };
    vector<vector<int> > range_m_4 = {
            {0, 0, 0},
            {1, 1, 1},
            {1, 1, 1},
            {2, 2, 2},
            {2, 2, 2},
            {3, 3, 3},
            {3, 3, 3},
            {4, 4, 4},
            {4, 4, 4},
    };

    ranges.push_back(range_m_1);
    ranges.push_back(range_m_2);
    ranges.push_back(range_m_3);
    ranges.push_back(range_m_4);

    //range sorts warrior
    vector<vector<int> > range_w_1 = {
            {1, 2, 1},
            {0, 2, 0},
            {0, 2, 0},
            {0, 2, 0},
            {0, 2, 0},
            {0, 2, 0},
            {0, 2, 0},
            {0, 2, 0},
            {1, 2, 1},
    };
    vector<vector<int> > range_w_2 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {3, 3, 3},
            {5, 5, 5},
    };
    vector<vector<int> > range_w_3 = {
            {3, 3, 3},
            {0, 0, 0},
            {3, 3, 3},
            {0, 0, 0},
            {3, 3, 3},
            {0, 0, 0},
            {3, 3, 3},
            {0, 0, 0},
            {0, 0, 0},
    };
    vector<vector<int> > range_w_4 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {2, 0, 2},
            {2, 0, 2},
            {2, 0, 2},
            {2, 0, 2},
            {2, 1, 2},
    };

    ranges.push_back(range_w_1);
    ranges.push_back(range_w_2);
    ranges.push_back(range_w_3);
    ranges.push_back(range_w_4);

    //range sorts archer;
    vector<vector<int> > range_a_1 = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1},
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1},
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1},
    };
    vector<vector<int> > range_a_2 = {
            {3, 5, 3},
            {0, 5, 0},
            {0, 5, 0},
            {0, 5, 0},
            {0, 5, 0},
            {0, 5, 0},
            {0, 5, 0},
            {0, 5, 0},
            {0, 5, 0},
    };
    vector<vector<int> > range_a_3 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 2, 0},
            {3, 3, 3},
    };
    vector<vector<int> > range_a_4 = {
            {3, 4, 3},
            {2, 3, 2},
            {2, 3, 2},
            {2, 3, 2},
            {2, 3, 2},
            {1, 2, 1},
            {1, 2, 1},
            {1, 2, 1},
            {1, 2, 1},
    };

    ranges.push_back(range_a_1);
    ranges.push_back(range_a_2);
    ranges.push_back(range_a_3);
    ranges.push_back(range_a_4);

    //range sort thief
    vector<vector<int> > range_t_1 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 4, 0},
            {4, 6, 4},
            {0, 6, 0},
            {6, 6, 6},
    };

    vector<vector<int> > range_t_2 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {3, 3, 3},
            {3, 0, 3},
            {3, 3, 3},
    };
    vector<vector<int> > range_t_3 = {
            {0, 0,  0},
            {0, 0,  0},
            {0, 0,  0},
            {0, 0,  0},
            {0, 0,  0},
            {0, 0,  0},
            {0, 10, 0},
            {0, 10, 0},
            {0, 10, 0},
    };
    vector<vector<int> > range_t_4 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {4, 4, 4},
            {0, 1, 0},
            {2, 2, 2},
            {2, 2, 2},
            {0, 1, 0},
            {4, 4, 4},
    };
    ranges.push_back(range_t_1);
    ranges.push_back(range_t_2);
    ranges.push_back(range_t_3);
    ranges.push_back(range_t_4);

    //range sort knights
    vector<vector<int> > range_k_1 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {6, 0, 6},
            {6, 6, 6},
    };

    vector<vector<int> > range_k_2 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 1, 0},
            {1, 2, 1},
            {2, 3, 2},
            {3, 4, 3},
            {4, 5, 4},
    };
    vector<vector<int> > range_k_3 = {
            {0, 4, 0},
            {4, 5, 4},
            {0, 4, 0},
            {0, 2, 0},
            {0, 2, 0},
            {0, 2, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
    };
    vector<vector<int> > range_k_4 = {
            {3, 0, 3},
            {0, 3, 0},
            {3, 0, 3},
            {3, 0, 3},
            {0, 3, 0},
            {3, 0, 3},
            {3, 0, 3},
            {0, 3, 0},
            {3, 0, 3},
    };
    ranges.push_back(range_k_1);
    ranges.push_back(range_k_2);
    ranges.push_back(range_k_3);
    ranges.push_back(range_k_4);

//range sort engineer
    vector<vector<int> > range_e_1 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {7, 7, 7},
    };

    vector<vector<int> > range_e_2 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 4, 0},
            {4, 6, 4},
            {0, 4, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
    };
    vector<vector<int> > range_e_3 = {
            {2, 0, 2},
            {2, 0, 2},
            {2, 0, 2},
            {0, 2, 0},
            {0, 2, 0},
            {0, 2, 0},
            {2, 0, 2},
            {2, 0, 2},
            {2, 0, 2},
    };
    vector<vector<int> > range_e_4 = {
            {4, 0, 4},
            {0, 0, 0},
            {4, 0, 4},
            {0, 0, 0},
            {4, 0, 4},
            {0, 0, 0},
            {4, 0, 4},
            {0, 0, 0},
            {4, 0, 4},
    };
    ranges.push_back(range_e_1);
    ranges.push_back(range_e_2);
    ranges.push_back(range_e_3);
    ranges.push_back(range_e_4);

    vector<vector<int> > range_p_1 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {4, 3, 0},
            {4, 0, 0},
            {4, 0, 0},
    };

    vector<vector<int> > range_p_2 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 3, 4},
            {0, 0, 4},
            {0, 0, 4},
    };
    vector<vector<int> > range_p_3 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
            {3, 4, 3},
            {0, 4, 0},
            {0, 4, 0},
    };
    vector<vector<int> > range_p_4 = {
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2},
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
    };
    ranges.push_back(range_p_1);
    ranges.push_back(range_p_2);
    ranges.push_back(range_p_3);
    ranges.push_back(range_p_4);


    vector<vector<int> > range_b_1 = {
        { 0, 0, 1},
        { 0, 0, 1},
        { 0, 0, 1},
        { 0, 0, 1},
        { 0, 0, 1},
        { 0, 0, 1},
        { 3, 3, 3},
        { 3, 3, 3},
        { 3, 3, 3},
};

vector<vector<int> > range_b_2 = {
        { 1, 0, 0},
        { 1, 0, 0},
        { 1, 0, 0},
        { 3, 3, 3},
        { 3, 3, 3},
        { 3, 3, 3},
        { 0, 0, 1},
        { 0, 0, 1},
        { 0, 0, 1},
};
vector<vector<int> > range_b_3 = {
        { 3, 3, 3},
        { 3, 3, 3},
        { 3, 3, 3},
        { 1, 0, 0},
        { 1, 0, 0},
        { 1, 0, 0},
        { 1, 0, 0},
        { 1, 0, 0},
        { 1, 0, 0},
};
vector<vector<int> > range_b_4 = {
        { 0, 1, 0},
        { 0, 1, 0},
        { 0, 1, 0},
        { 0, 1, 0},
        { 0, 1, 0},
        { 0, 1, 0},
        { 3, 3, 3},
        { 3, 3, 3},
        { 3, 3, 3},
};
ranges.push_back(range_b_1);
ranges.push_back(range_b_2);
ranges.push_back(range_b_3);
ranges.push_back(range_b_4);

vector<vector<int> > range_c_1 = {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 2, 0},
        { 2, 2, 2},
};

vector<vector<int> > range_c_2 = {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 2, 2, 2},
        { 0, 0, 0},
        { 2, 2, 2},
};
vector<vector<int> > range_c_3 = {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 2, 0},
        { 2, 2, 2},
        { 2, 2, 2},
        { 2, 2, 2},
        { 0, 2, 0},
        { 0, 0, 0},
        { 0, 0, 0},
};
vector<vector<int> > range_c_4 = {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 5, 0},
        { 5, 9, 5},
        { 0, 5, 0},
        { 0, 5, 0},
        { 5, 9, 5},
        { 0, 5, 0},
        { 0, 5, 0},
};
ranges.push_back(range_c_1);
ranges.push_back(range_c_2);
ranges.push_back(range_c_3);
ranges.push_back(range_c_4);

    return ranges;
}
//Spells creation template
//Spell* spell_*_1 = new Spell("", 100, count_square(ranges[]), ranges[]);
//Spell* spell_*_2 = new Spell("", 100, count_square(ranges[]), ranges[]);
//Spell* spell_*_3 = new Spell("", 100, count_square(ranges[]), ranges[]);
//Spell* spell_*_4 = new Spell("", 100, count_square(ranges[]), ranges[]);
//
//spells_*.push_back(spell_*_1);
//spells_*.push_back(spell_*_2);
//spells_*.push_back(spell_*_3);
//spells_*.push_back(spell_*_4);

static vector<vector<Spell *> > spellInitialization() {

    vector<vector<vector<int> > > ranges = rangesInitialization();
    vector<vector<Spell *> > spells;
    vector<Spell *> spells_m;
    vector<Spell *> spells_w;
    vector<Spell *> spells_a;
    vector<Spell *> spells_t;
    vector<Spell *> spells_k;
    vector<Spell *> spells_e;
    vector<Spell *> spells_p;
    vector<Spell *> spells_b;
    vector<Spell *> spells_c;
    int i = 0;

    //mage spells
    Spell *spell_m_1 = new Spell("Boule de feu", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_m_2 = new Spell("Foudroiement", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_m_3 = new Spell("Blizzard", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_m_4 = new Spell("Raz-de-Marée", 100, balanceManaCost(ranges[i]), ranges[i++]);

    spells_m.push_back(spell_m_1);
    spells_m.push_back(spell_m_2);
    spells_m.push_back(spell_m_3);
    spells_m.push_back(spell_m_4);

    //warrior spells
    Spell *spell_w_1 = new Spell("Berzerk", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_w_2 = new Spell("Tournoiement de hache", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_w_3 = new Spell("Onde de choc", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_w_4 = new Spell("Furie sanguinaire", 100, balanceManaCost(ranges[i]), ranges[i++]);

    spells_w.push_back(spell_w_1);
    spells_w.push_back(spell_w_2);
    spells_w.push_back(spell_w_3);
    spells_w.push_back(spell_w_4);

    //archer spells
    Spell *spell_a_1 = new Spell("Volée de fleches", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_a_2 = new Spell("Tir de précision", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_a_3 = new Spell("Coup de dague", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_a_4 = new Spell("Fleches enflammées", 100, balanceManaCost(ranges[i]), ranges[i++]);

    spells_a.push_back(spell_a_1);
    spells_a.push_back(spell_a_2);
    spells_a.push_back(spell_a_3);
    spells_a.push_back(spell_a_4);
//thief spells
    Spell *spell_t_1 = new Spell("Dague assassine", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_t_2 = new Spell("Coup bas", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_t_3 = new Spell("Tir à bout portant", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_t_4 = new Spell("Rush", 100, balanceManaCost(ranges[i]), ranges[i++]);

    spells_t.push_back(spell_t_1);
    spells_t.push_back(spell_t_2);
    spells_t.push_back(spell_t_3);
    spells_t.push_back(spell_t_4);

//    knight spells
    Spell *spell_k_1 = new Spell("Bastion", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_k_2 = new Spell("Charge cavalière", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_k_3 = new Spell("Épée de la justice", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_k_4 = new Spell("Divine Providence", 100, balanceManaCost(ranges[i]), ranges[i++]);

    spells_k.push_back(spell_k_1);
    spells_k.push_back(spell_k_2);
    spells_k.push_back(spell_k_3);
    spells_k.push_back(spell_k_4);

//Engineer spells
    Spell *spell_e_1 = new Spell("La Pince Monseigneur", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_e_2 = new Spell("Frappe chirurgicale", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_e_3 = new Spell("Démolition", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_e_4 = new Spell("Calcul Integral", 100, balanceManaCost(ranges[i]), ranges[i++]);


    spells_e.push_back(spell_e_1);
    spells_e.push_back(spell_e_2);
    spells_e.push_back(spell_e_3);
    spells_e.push_back(spell_e_4);

    //Peasant spells
    Spell *spell_p_1 = new Spell("Essartage", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_p_2 = new Spell("Moissonnage", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_p_3 = new Spell("Jachère", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_p_4 = new Spell("Defense de la Patrie", 100, balanceManaCost(ranges[i]), ranges[i++]);

    spells_p.push_back(spell_p_1);
    spells_p.push_back(spell_p_2);
    spells_p.push_back(spell_p_3);
    spells_p.push_back(spell_p_4);

    Spell *spell_b_1 = new Spell("Bagatelle", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_b_2 = new Spell("Concerto", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_b_3 = new Spell("Fugue", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_b_4 = new Spell("Cacophonie", 100, balanceManaCost(ranges[i]), ranges[i++]);

spells_b.push_back(spell_b_1);
spells_b.push_back(spell_b_2);
spells_b.push_back(spell_b_3);
spells_b.push_back(spell_b_4);

    Spell *spell_c_1 = new Spell("Coup de Baton", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_c_2 = new Spell("Voeu Pieux", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_c_3 = new Spell("Protection", 100, balanceManaCost(ranges[i]), ranges[i++]);
    Spell *spell_c_4 = new Spell("Incantation Divine", 100, balanceManaCost(ranges[i]), ranges[i++]);

spells_c.push_back(spell_c_1);
spells_c.push_back(spell_c_2);
spells_c.push_back(spell_c_3);
spells_c.push_back(spell_c_4);


    //adding all spells in the spell vector
    spells.push_back(spells_m);
    spells.push_back(spells_w);
    spells.push_back(spells_a);
    spells.push_back(spells_t);
    spells.push_back(spells_k);
    spells.push_back(spells_e);
    spells.push_back(spells_p);
    spells.push_back(spells_b);
    spells.push_back(spells_c);

    return spells;
}

vector<Champion *> champInitialization() {
    vector<Champion *> champions;
    vector<vector<Spell *> > spells = spellInitialization();
    int i = 0;

    Champion *champ_mage = new Champion("Mage", 'M', 1, spells[i++]);
    champions.push_back(champ_mage);

    Champion *champ_warrior = new Champion("Warrior", 'W', 1, spells[i++]);
    champions.push_back(champ_warrior);

    Champion *champ_archer = new Champion("Archer", 'A', 1, spells[i++]);
    champions.push_back(champ_archer);

    Champion *champ_thief = new Champion("Thief", 'T', 1, spells[i++]);
    champions.push_back(champ_thief);

    Champion *champ_knight = new Champion("Knight", 'K', 1, spells[i++]);
    champions.push_back(champ_knight);

    Champion *champ_engineer = new Champion("Engineer", 'E', 1, spells[i++]);
    champions.push_back(champ_engineer);

    Champion *champ_peasant = new Champion("Peasant", 'P', 1, spells[i++]);
    champions.push_back(champ_peasant);

    Champion *champ_bard = new Champion("Bard", 'B', 1, spells[i++]);
    champions.push_back(champ_bard);

    Champion *champ_cleric = new Champion("Cleric", 'C', 1, spells[i++]);
    champions.push_back(champ_cleric);

    return champions;
}

Player *playerInitialization() {
    int MAX_CHAMP = 3;
    string user_choice = "0";
    vector<Champion *> champs = champInitialization();
    vector<Champion *> user_champs;
    string username;

    system("clear");
    cout << "Veuillez saisir un" << MAGENTA << " pseudo " << RESET << ": " << endl;
    cin >> username;
    getline(cin, username);
    system("clear");
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


