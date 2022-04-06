//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/header.h"
#include "../include/Game.h"

//TODO Create a Level Object which will contains all specificity of a given level
// (difficulty, terrain type, enemy type etc...)
// this would allow us to create a level selector, or even a campaign;



Game::Game(int w, int h) {
    this->MAP_WIDTH = w;
    this->MAP_HEIGHT = h;
    this->MAX_ENEMY = 61;


}

//main func

void Game::init() {
    vector<vector<int> > map(this->MAP_HEIGHT, vector<int>(this->MAP_WIDTH, 0));
    setMap(map);
}

void Game::update(vector<vector<int> > range) {
    vector<int> tmp_map = getMap()[getMap().size() - 1];
    count_line(tmp_map);
    setMap(push_row(getMap()));
    setRound((getRound()) + 1);
    //spawn les enemies
    setMap(spawner(getMap(), getRound()));
//    playerTurn(range); //TODO PLAYER TURN
}

void Game::draw() {

    displayHUI();
    color('f', "lblue");
    for (int i = 0; i < this->map.size(); i++) {
        cout << "      ";
        for (int j = 0; j < this->map[i].size(); j++) {
            cout << enemy_dict[map[i][j]] << " ";
        }
        cout << endl;
    }
    displayFUI();
}

//support func
int Game::count_line(vector<int> map) {
    int i = 0;
    int count = 0;

    while (map[i]) {
        count += map[i];
        i++;
    }
    return count;
}

vector<vector<int> > Game::push_row(vector<vector<int> > vec) {
    //pushes the rows to row+1, beginning with penultimate
    // i = row
    // j = col
    int i = vec.size() - 2;
    int j = vec[i].size() - 1;
    while (i >= 0) {
        while (j >= 0) {
            vec[i + 1][j] = vec[i][j];
            vec[i][j] = 0;
            j--;
        }
        j = vec[i].size() - 1;
        i--;
    }
    return vec;
}

vector<vector<int> > Game::spawner(vector<vector<int> > vec, int round) {
    int en_nb = rand() % 1 + round; // growing ennemy nb mecanic in functions of round nb =
    if (en_nb > MAP_WIDTH * 60)
        en_nb = MAP_WIDTH * 60;
    while (en_nb) {
        int rnb = rand() % this->MAP_WIDTH;
        if (vec[0][rnb] < this->MAX_ENEMY) {
            vec[0][rnb]++;
            en_nb--;
        }
    }
    return vec;
}




//getters and setters

vector<vector<int> > Game::getMap() {
    return this->map;
}

void Game::setMap(vector<vector<int> > map) {
    this->map = map;
}

int Game::getRound() {
    return this->round;
}

void Game::setRound(int round) {
    this->round = round;
}

//Game UI
void Game::displayHUI() {
    color('f', "pink");

    cout << "######## ROUND N. : " << getRound() << " ########" << endl;
}

void Game::displayFUI() {
    color('f', "pink");
    cout << "      " << "  " << "@" << "     " << "#" << "     " << "%" << endl;

    color('f', "green");
    cout << "##############################" << endl;
    cout << "#                            #" << endl;
    cout << "#      HitPoint : 30/30      #" << endl;
    cout << "#                            #" << endl;

    color('f', "dblue");

    cout << "#      Manawox : 0/100       #" << endl;
    cout << "#                            #" << endl;

    color('f', "yellow");

    cout << "#      $imiam$ : 0           #" << endl;
    cout << "#                            #" << endl;
    cout << "##############################" << endl;

}

// vector comparison

void Game::drawRange(vector<vector<int> > map, vector<vector<int> > range) {
    for (int i = 0; i < range.size(); i++) {
        cout << "      ";
        for (int j = 0; j < range[i].size(); j++) {
            if (range[i][j] == 1) {
                color('b', "red");

                cout << map[i][j] << " ";
                color('b', "black");

            } else if (range[i][j] == 0) {
                cout << map[i][j] << " ";
            }
        }
        cout << endl;
    }
}

vector<vector<int> > Game::applyDamage(vector<vector<int> > map, vector<vector<int> > range) {
    for (int i = 0; i < range.size(); i++) {
        cout << "      ";
        for (int j = 0; j < range[i].size(); j++) {
            if (range[i][j] > 0)
                map[i][j] -= range[i][j];
            if (map[i][j] < 0)
                map[i][j] = 0;
        }
        cout << endl;
    }
    return map;
}

//Player implementation

void Game::playerTurn(vector<vector<int> > range)
{
    string usr_input;
    cout << "1 pour visualiser" << endl;
    getline(cin, usr_input);
    if (usr_input == "1"){
        system("clear");
        this->drawRange(this->getMap(), range);
        cout << "1 pour lancer" << endl;
        getline(cin, usr_input);
        if (usr_input == "1") {
            this->applyDamage(this->getMap(), range);
            this->draw();
        }
    }
}


