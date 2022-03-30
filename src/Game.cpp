//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/header.h"
#include "../include/Game.h"

//TODO Create a Level Object which will contains all specificity of a given level
// (difficulty, terrain type, enemy type etc...)
// this would allow us to create a level selector, or even a campaign;

Game::Game(int w, int h){
    this->MAP_WIDTH = w;
    this->MAP_HEIGHT = h;
}

//main func

void Game::init(){
    vector<vector<int>> map(this->MAP_HEIGHT, vector<int> (this->MAP_WIDTH, 0));
    setMap(map);
}

void Game::update(){
    dmg_to_player(getMap());
    setMap(push_row(getMap()));
    setRound((getRound())+1);
    setMap(spawner(getMap(), getRound()));
}

void Game::draw(){
    for (int i = 0; i < this->map.size() - 1; i++) {
        for (int j = 0; j < this->map[i].size() - 1; j++){
            cout << map[i][j] << " ";
    }
        cout << endl;
    }
}

//support func
int Game::dmg_to_player(vector<vector<int>> map) {
    unsigned int l_row = map.size() - 1;

    int i = 0;
    int dmg = 0;

    while (map[l_row][i]) {
        dmg += map[l_row][i];
        i++;
    }
    return dmg;
}

vector<vector<int>> Game::push_row(vector<vector<int>> vec) {
    //pushes the rows to row+1, beginning with penultimate
    // i = row
    // j = col
    int i = vec.size() - 2;
    int j = vec[i].size() - 1;
    while (i >= 0) {
        while (j >= 0) {
            vec[i + 1][j] = vec[i][j];
            j--;
        }
        j = vec[i].size() - 1;
        i--;
    }
    i = 0;
    j = 0;
    while (j < this->MAP_WIDTH - 1){
        vec[i][j] = 0;
        j++;
    }
    return vec;
}

vector<vector<int>> Game::spawner(vector<vector<int>> vec, int round) {
    int en_nb = 1 + round; // growing ennemy nb mecanic in functions of round nb =
    while (en_nb) {
        int rnb = rand() % this->MAP_WIDTH;
        if (vec[0][rnb] < this->MAP_WIDTH - 1) {
            vec[0][rnb]++;
            en_nb--;
        }
    }
    return vec;
}




//getters and setters

vector<vector<int>> Game::getMap(){
    return this->map;
}

void Game::setMap(vector<vector<int>> map){
    this->map = map;
}

int Game::getRound() {
    return this->round;
}

void Game::setRound(int round){
    this->round = round;
}

