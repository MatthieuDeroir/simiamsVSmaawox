// TO COMPILE
// g++ main.cpp src/* include/*

// TO RUN
// ./a.out

#include "include/header.h"
#include "include/Player.h"
#include "include/Enemy.h"
#include "include/Game.h"


int main() {
    cout << "Bienvenue sur Maawox versus Simsim : le retour du Roi de la coline d'à côté de la montagne verte" << endl;

    Game *game = new Game();

    Player* playerG = new Player("Guigz", 200, 12, 20, 100, '|', 0);
    Player* playerM = new Player("Nirma", 200, 12, 20, 100, '!', 0);


    Enemy* enemyS = new Enemy(48, 0, 2);
    Enemy* enemyM = new Enemy('&', 0, 4);


    playerG->toString();
    playerM->toString();
    enemyS->toString();
    enemyM->toString();

    game->Draw();
    return 0;
}


