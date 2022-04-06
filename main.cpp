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


    srand(time(NULL));

    string usr_input = " ";
    system("clear");

    string welcome_msg = "Bienvenue sur Maawox versus Simsim : le retour du Roi de la coline d'à côté de la montagne verte";

    cout << welcome_msg << endl;

    Player *player = playerInitialization();

    Game *game = new Game(9, 15, player);


//        game->init();
//    while (usr_input != "q!"){
//        //system("pause");
//        //system("cls");
//        game->update();
//    }
    return 0;
}


