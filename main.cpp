// TO COMPILE
// g++ main.cpp src/* include/*

// TO RUN
// ./a.out

#include "include/header.h"
#include "include/Player.h"
#include "include/Enemy.h"
#include "include/Game.h"
#include "include/Spell.h"
#include "include/defines.h"


int main() {
    bool retry = true;

    while (retry) {
        srand(time(0));

        string usr_input = " ";
        system("clear");



        Player *player = playerInitialization();

        Game *game = new Game(9, 9, player);

        game->startMenu();
        string welcome_msg = "Bienvenue sur Maawox versus Simsim : le retour du Roi de la coline d'à côté de la montagne verte";
        cout << welcome_msg << endl;

        while (!game->getPlayer()->getGameOver()) {
            game->update();
        }
        retry = game->gameOverMenu();
    }
    return 0;
}


