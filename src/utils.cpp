//
// Created by Matthieu Deroir on 30/03/2022.
//

#include "../include/header.h"


void print(string str) { // un print basique pour le debug
    cout << str << endl;
}


//fonction pour appliquer un vecteur de 3 par 9 à un vecteur de 9 par 9 ==>
// TODO: à implementer dans la Classe Spell
// TODO : rajouter les tailles des deux vector en parametre pour la rendre modulable
vector<vector<int> > rwVector(int index_multiplier, vector<vector<int> > cubic_vec) {
    vector<vector<int> > vec(9, vector<int>(9, 0));
    for (int i = 0; i < cubic_vec.size(); i++) {
        for (int j = 0; j < cubic_vec[i].size(); j++) {
            vec[i][j + (3 * index_multiplier)] = cubic_vec[i][j];
        }
    }
    return vec;
}

//additionne les valeurs d'un vector
int count_vec(vector<vector<int> > vec) {
    int nb = 0;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            nb += vec[i][j];
        }
    }
    return nb;
}

//compte le nombre d'occurence de valeur  supérieure à 0 d'un vector
int count_square(vector<vector<int> > vec) {
    int nb = 0;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (vec[i][j] > 0) {
                nb += 1;
            }
        }
    }
    return nb;
}

//fonction de balance du manaCost des sorts en utilisant les deux fonctions précédentes
// TODO: ==> à implementer dans la classe Spell !!!
int balanceManaCost(vector<vector<int> > vec) {
    int manacost = 0;
    manacost += count_square(vec);
    manacost = manacost * 1 + (count_vec(vec) / 10);
    return manacost;
}


//fonction qui permet de print une chaine de caractère nb fois
void multiprint(string str, int nb) {
    for (int i = 0; i < nb; i++) {
        cout << str;
    }
}



