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
    vector<vector<int>> map;



//    string state;
//    vector<Player*> players;
//    vector<Enemy*> enemies;
public:
    Game();
    vector<vector<int>> setMap();
    void draw();
};


#endif //SIMIAMSVSMAAWOX_GAME_H
