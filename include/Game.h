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
    int MAP_HEIGHT = 10;
    int MAP_WIDTH = 10;

    vector<vector<int>> map(int MAP_HEIGHT, vector<int> (MAP_WIDTH, 0));


//    string state;
//    vector<Player*> players;
//    vector<Enemy*> enemies;
public:
    void Draw();
};


#endif //SIMIAMSVSMAAWOX_GAME_H
