//
// Created by Matthieu Deroir on 30/03/2022.
//

#include "../include/header.h"

//TODO : Implementer les fonctions suivantes dans les classes appropriées


void print(string str) { // un print basique pour le debug
    cout << str << endl;
}

void wait() { //fonction de pause mais ne fonctionne pas avec le terminal Clion
    cout << "Appuyez sur une touche pour continuer..." << endl;
    system("/bin/stty raw");
    getchar();
    system("/bin/stty cooked");
}


vector<vector<int> > rwVector(int index_multiplier, vector<vector<int> > cubic_vec) {
    vector<vector<int> > vec(9, vector<int>(9, 0));
    for (int i = 0; i < cubic_vec.size(); i++) {
        for (int j = 0; j < cubic_vec[i].size(); j++) {
            vec[i][j + (3 * index_multiplier)] = cubic_vec[i][j];
        }
    }
    return vec;
}

//* 0 = black
//* 1 = red
//* 2 = green
//* 3 = yellow
//* 4 =
//dark blue
//* 5 = pink
//* 6 =
//light blue
//* 7 =
//
//white

void color(char p, string color) { //fonction d'affichage de couleur par ligne
    char os = 'm'; //change to w for windows

    if (os == 'm') {
        if (p == 'f') {
            if (color == "black")
                system("tput setaf 0");
            else if (color == "red")
                system("tput setaf 1");
            else if (color == "green")
                system("tput setaf 2");
            else if (color == "yellow")
                system("tput setaf 3");
            else if (color == "dblue")
                system("tput setaf 4");
            else if (color == "pink")
                system("tput setaf 5");
            else if (color == "lblue")
                system("tput setaf 6");
            else if (color == "white")
                system("tput setaf 7");
        } else if (p == 'b') {
            if (color == "black")
                system("tput setab 0");
            else if (color == "red")
                system("tput setab 1");
            else if (color == "green")
                system("tput setab 2");
            else if (color == "yellow")
                system("tput setab 3");
            else if (color == "dblue")
                system("tput setab 4");
            else if (color == "pink")
                system("tput setab 5");
            else if (color == "lblue")
                system("tput setab 9");
            else if (color == "white")
                system("tput setab 7");
        } else if (os == 'w') {
            //TODO color for cmd
        } else {
            print("Commande non reconnue");
        }
    }
}

int count_vec(vector<vector<int> > vec) {
    int nb = 0;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            nb += vec[i][j];
        }
    }
    return nb;
}

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

int balanceManaCost(vector<vector<int> > vec) {
    int manacost = 0;
    manacost += count_square(vec);
    manacost = manacost * 1 + (count_vec(vec) / 10);
    return manacost;
}

void multiprint(string str, int nb) {
    for (int i = 0; i < nb; i++) {
        cout << str;
    }
}



