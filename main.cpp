// TO COMPILE
// g++ -std=c++11 main.cpp src/* include/*.h defines/defines.cpp

// TO RUN
// ./a.out

#include "include/header.h"
#include "include/Player.h"
#include "include/Game.h"
#include "include/Spell.h"
#include "include/defines.h"

int main(int argc, char** argv) {
    bool retry = true;
    char os;
    cout << "Windows ou Mac ? (w/m)" << endl;
    cin >> os;

    while (retry) {
        srand(time(0));

        string usr_input = " ";
        system("clear");

        Player *player = new Player();

        Game *game = new Game(9, 9, player, os);

        game->startMenu();
        player = playerInitialization();
        game->setPlayer(player);
        string welcome_msg = "Bienvenue sur Maawox versus Simsim : le retour du Roi de la coline d'à côté de la montagne verte";
        cout << welcome_msg << endl;

        while (!game->getPlayer()->getGameOver()) {
            game->update();
        }
        retry = game->gameOverMenu();
    }
    return 0;
}


