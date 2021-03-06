//
// Created by Matthieu Deroir on 23/03/2022.
//

#ifndef SIMIAMSVSMAAWOX_GAME_H
#define SIMIAMSVSMAAWOX_GAME_H

#include "header.h"
#include "Player.h"

class Game {
private:
    int MAP_HEIGHT;
    int MAP_WIDTH;

    char os;


    Player* player;

    int MAX_ENEMY;

    int round;

//    Player player;

    char enemy_dict[62] = {
            '0','1','2','3','4','5','6','7','8','9',

            'a','b','c','d','e','f','g','h','i','j',
            'k','l','m','n','o','p','q','r','s','t',
            'u','v','w','x','y','z',

            'A','B','C','D','E','F','G','H','I','J',
            'K','L','M','N','O','P','Q','R','S','T',
            'U','V','W','X','Y','Z'
    };
    vector<vector<int> > map;


//    string state;
//    vector<Player*> players;
//    vector<Enemy*> enemies;
public:
    Game(int w, int h, Player* player, char os);

    //menu
    void startMenu();

    void helpMenu();

    void optionsMenu();

    bool gameOverMenu();

    //main game loop functionalities
    void draw();

    void init();

    void update();

    //support func
    int count_line(vector<int> map);

    vector<vector<int> > push_row(vector<vector<int> > vec);

    vector<vector<int> > spawner(vector<vector<int> > vec, int round);

    //game spec
    void setMap(vector<vector<int> > map);

    vector<vector<int> > getMap();

    int getRound();

    void setRound(int round);

    Player* getPlayer();

    void setPlayer(Player* player);

    //game UI
    void displayHUI();

    void displayFUI();

    //vector comparison
        //drawing options
    void drawRange(vector<vector<int> > range, Champion* champ);

    void drawSpellDamage(vector<vector<int> > range);
    void drawSpellDamageShop(vector<vector<int> > range);

    void drawEnemyKilled(vector<vector<int> > prev_map);



        //vector differences
    vector<vector<int> > applyDamage(vector<vector<int> > map, Champion* champ, vector<vector<int> > range);

    void shop(Champion* champion);

    //Player implementation
    void playerTurn();

    //clear
    void clear(char os);

};


#endif //SIMIAMSVSMAAWOX_GAME_H
