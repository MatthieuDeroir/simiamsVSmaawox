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
    vector<vector<int> > map;


//    string state;
//    vector<Player*> players;
//    vector<Enemy*> enemies;
public:
    Game(int w, int h);

    //main game loop functionalities
    void draw();

    void init();

    void update();

    //support func
    int count_line(vector<int>  map);

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


};


#endif //SIMIAMSVSMAAWOX_GAME_H
