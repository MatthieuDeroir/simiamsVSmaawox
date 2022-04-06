//
// Created by Matthieu Deroir on 30/03/2022.
//

#include "../include/header.h"

//TODO : Implementer les fonctions suivantes dans les classes appropriées

void systemVarInit(){
    system("Red=$(tput bold ; tput setaf 1)");
}

void print(string str) {
    cout << str << endl;
}

void wait(){
    cout << "Appuyez sur une touche pour continuer..." << endl;
    system ("/bin/stty raw");
    getchar();
    system("/bin/stty cooked");
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

void color(char p, string color) {
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

