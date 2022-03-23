#include "include/header.h"
#include "include/Player.h"
#include "include/Enemy.h"
// TO COMPILE
// g++ main.cpp src/* include/*
// TO RUN
// ./a.out

int main() {
    cout << "Bienvenue sur Maawox versus Simsim : le retour du Roi de la coline d'à côté de la montagne verte" << endl;

    Player* playerG = new Player("Guigz", 200, 12, 20, 100, '|');
    Player* playerM = new Player("Nirma", 200, 12, 20, 100, '!');


    Enemy* enemyS = new Enemy('@');
    Enemy* enemyM = new Enemy('&');


    playerG->toString();
    playerM->toString();
    enemyS->toString();
    enemyM->toString();
    return 0;
}


