// TO COMPILE
// g++ main.cpp src/* include/*

// TO RUN
// ./a.out

#include "include/header.h"
#include "include/Player.h"
#include "include/Enemy.h"
#include "include/Game.h"
#include "include/Spell.h"


int main() {


    srand(time(NULL));

    string usr_input = " ";
    system("clear");

    cout << "Bienvenue sur Maawox versus Simsim : le retour du Roi de la coline d'à côté de la montagne verte" << endl;

    Game* game = new Game(9, 15);


    vector<vector<int> > sort1(10, vector<int>(10, 10));
    Spell* spell = new Spell("MAGIE DE FEU", 100, 5, sort1);
    spell->getRange();

//    Player* playerG = new Player("Guigz", 200, 12, 20, 100, '|', 0);
//    Player* playerM = new Player("Nirma", 200, 12, 20, 100, '!', 0);


//    Enemy* enemyS = new Enemy(48, 0, 2);
//    Enemy* enemyM = new Enemy('&', 0, 4);


//    playerG->toString();
//    playerM->toString();
//    enemyS->toString();
//    enemyM->toString();

        game->init();

    while (usr_input != "q!"){

        //IMPORTANT : pour utilisation sous windows
        // il faut commenter les deux lignes system ci-dessous et décommenter les suivantes
        getline(cin, usr_input);
        system("clear");
        //system("pause");
        //system("cls");
        game->update();
        game->draw();
    }


    return 0;
}


