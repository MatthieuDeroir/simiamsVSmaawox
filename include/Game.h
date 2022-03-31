//
// Created by Matthieu Deroir on 23/03/2022.
//

#ifndef SIMIAMSVSMAAWOX_GAME_H
#define SIMIAMSVSMAAWOX_GAME_H

#include "header.h"
#include "Player.h"
#include "Enemy.h"

class Game {
private:
    int MAP_HEIGHT;
    int MAP_WIDTH;

    int MAX_ENEMY;

    int round;

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
    Game(int w, int h);

    //main game loop functionalities
    void draw();

    void init();

    void update(vector<vector<int> > range);

    //support func
    int count_line(vector<int> map);

    vector<vector<int> > push_row(vector<vector<int> > vec);

    vector<vector<int> > spawner(vector<vector<int> > vec, int round);

    //game spec
    void setMap(vector<vector<int> > map);

    vector<vector<int> > getMap();

    int getRound();

    void setRound(int round);

    //game UI
    void displayHUI();

    void displayFUI();

    //vector comparison
    void drawRange(vector<vector<int> > map, vector<vector<int> > range);

    vector<vector<int> > applyDamage(vector<vector<int> > map, vector<vector<int> > range);

    //Player implementation
    void playerTurn(vector<vector<int> > range);

};


#endif //SIMIAMSVSMAAWOX_GAME_H
