//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/Game.h"

Game::Game(){
    this->MAP_WIDTH = 10;
    this->MAP_HEIGHT = 10;
}

vector<vector<int>> Game::setMap(){
    vector<vector<int>> map(this->MAP_HEIGHT, vector<int> (this->MAP_WIDTH, 0));
    this->map = map;
}

void Game::draw(){
    cout << this->map.size() << endl;

    for (int i = 0; i < this->map.size(); i++){
        cout << "yo" << endl;
    }

}