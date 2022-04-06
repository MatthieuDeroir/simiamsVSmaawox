//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/header.h"
#include "../include/Game.h"

//TODO Create a Level Object which will contains all specificity of a given level
// (difficulty, terrain type, enemy type etc...)
// this would allow us to create a level selector, or even a campaign;



Game::Game(int w, int h, Player *player) {
    this->MAP_WIDTH = w;
    this->MAP_HEIGHT = h;
    this->MAX_ENEMY = 61;


}

//main func

void Game::init() {
    vector<vector<int> > map(this->MAP_HEIGHT, vector<int>(this->MAP_WIDTH, 0));
    setMap(map);
}

void Game::update() {

    int dmg;
    vector<int> tmp_map = getMap()[getMap().size() - 1];

    dmg = count_line(tmp_map);
    setMap(push_row(getMap()));
    setRound((getRound()) + 1);
    //spawn les enemies
    setMap(spawner(getMap(), getRound()));
    draw();
    this->player->takeDamage(dmg);
    playerTurn(); //TODO PLAYER TURN
}

void Game::draw() {
    system("clear");
    displayHUI();
    color('f', "lblue");
    for (int i = 0; i < this->map.size(); i++) {
        cout << "      ";
        for (int j = 0; j < this->map[i].size(); j++) {
            if (this->map[i][j] == 0) {
                cout << BLUE << enemy_dict[map[i][j]] << " " << RESET;
            } else if (this->map[i][j] < 10) {
                cout << GREEN << enemy_dict[map[i][j]] << " " << RESET;
            } else if (this->map[i][j] < 36) {
                cout << YELLOW << enemy_dict[map[i][j]] << " " << RESET;

            } else if (this->map[i][j] >= 36) {
                cout << RED << enemy_dict[map[i][j]] << " " << RESET;

            }

        }
        cout << endl;
    }
    displayFUI();
}

//support func
int Game::count_line(vector<int> map) {
    int i = 0;
    int count = 0;

    while (i < map.size()) {
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
    int en_nb = abs(cos((1 + round))*10);

    cout << en_nb << endl;

    // growing ennemy nb mecanic in functions of round nb =
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

Player *Game::getPlayer() {
    return this->player;
}

void Game::setPlayer(Player *player) {
    this->player = player;
}

//Game UI
void Game::displayHUI() {
    color('f', "pink");

    cout << BGMAGENTA << BLACK << "######## ROUND N. : " << getRound() << " ########" << RESET << endl;
}

void Game::displayFUI() {
    cout << MAGENTA << "      " << "  " << "@" << "     " << "#" << "     " << "%" << RESET << endl;

    cout << "##############################" << endl;
    cout << "#      " << GREEN << "HitPoint : " << this->player->getHp() << "/" << this->player->getMaxHp() << RESET << "      #"
          << endl;

    cout << "#      " << CYAN << "Manawox : 0/100" << RESET << "       #" << endl;

    cout << "#      $imiam$ : 0           #" << endl;
    cout << "#                            #" << endl;
    cout << "##############################" << endl;

}

// vector comparison

void Game::drawRange(vector<vector<int> > range) {
    system("clear");
    displayHUI();


    for (int i = 0; i < range.size(); i++) {
        cout << "      ";
        for (int j = 0; j < range[i].size(); j++) {
            if (range[i][j] > 0) {
                cout << BGRED << enemy_dict[map[i][j]] << RESET << " ";

            } else if (range[i][j] == 0) {
                cout << WHITE << enemy_dict[map[i][j]] << " " << RESET;

            }
        }
        cout << endl;
    }
    displayFUI();
}

void Game::drawEnemyKilled(vector<vector<int> > prev_map) {
    system("clear");
    displayHUI();
    int e_nb;

    e_nb = 0;

    for (int i = 0; i < prev_map.size(); i++) {
        cout << "      ";
        for (int j = 0; j < prev_map[i].size(); j++) {
            if (prev_map[i][j] > this->map[i][j]) {
                cout << BLUE << enemy_dict[map[i][j]] << RESET << " ";
                e_nb++;
            } else {
                cout << WHITE << enemy_dict[map[i][j]] << " " << RESET;

            }
        }
        cout << endl;
    }
    displayFUI();
    cout << RESET << "Vous avez touché " << BLUE << e_nb << RESET << " enemi(s) !" << endl;
}

vector<vector<int> > Game::applyDamage(vector<vector<int> > map, Champion *champ, vector<vector<int> > range) {
    int dmg_alea;
    for (int i = 0; i < range.size(); i++) {
        for (int j = 0; j < range[i].size(); j++) {
            if (range[i][j] > 0 && map[i][j] > 0) {
                dmg_alea = rand() % (range[i][j] * champ->getAtt());
                map[i][j] -= dmg_alea;
                this->player->setMoney(this->player->getMoney() + dmg_alea);
                if (dmg_alea)
                    cout << "Attaque réussie en" << GREEN << "[" << i << "," << j << "]" << RESET << " !" << endl;
                else
                    cout << "Attaque ratée en" << RED << "[" << i << "," << j << "]" << RESET << " !" << endl;
            }
            if (map[i][j] < 0)
                map[i][j] = 0;
        }
        cout << endl;
    }
    return map;
}

//Player implementation
void Game::playerTurn() {
/*
 *
 *  vector<vector<int> > tmp;
    tmp = getMap();

    string usr_input;
    cout << "1 pour visualiser" << endl;
    getline(cin, usr_input);
    if (usr_input == "1") {
        system("clear");
        this->drawRange(range);
        cout << "1 pour lancer" << endl;
        getline(cin, usr_input);
        if (usr_input == "1") {
            setMap(this->applyDamage(this->getMap(), range));
            this->drawEnemyKilled(tmp);
            cout << "Appuyez sur une touche pour continuer..." << endl;
            getline(cin, usr_input);
        }
    }
}


