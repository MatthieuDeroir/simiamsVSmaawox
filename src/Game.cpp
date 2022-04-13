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
    this->player = player;
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
    this->player->takeDamage(dmg, this->round);
    draw();
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

//base game func
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
    int en_nb = (1 + round)*round;

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


//Game UI
void Game::displayHUI() { //affichage de l'entête de l'UI
    color('f', "pink");

    cout << BGMAGENTA << BLACK << "######## ROUND N. : " << getRound() << " ########" << RESET << endl;
}

void Game::displayFUI() { //affichage du bas de l'UI //TODO : faire les bordures à droite pour qu'elles soient dynamiques avec la valeur d'affichage des stats
    cout << MAGENTA << "      " << "  " << "M" << "     " << "W" << "     " << "A" << RESET << endl;

    cout << "##############################" << endl;
    cout << "#      " << GREEN << "HitPoint : " << this->player->getHp() << "/" << this->player->getMaxHp() << RESET
         << "      #"
         << endl;

    cout << "#      " << CYAN << "Manawox : " << this->player->getMana() << "/" << this->player->getMaxMana()<< RESET << "       #" << endl;

    cout << "#      " << YELLOW << "$imiam$ : " << this->player->getMoney() << RESET << "           #" << endl;
    cout << "##############################" << endl;

}

// vector comparison

void Game::drawRange(vector<vector<int> > range, Champion *champ) { // affiche les cases visées par une attaque
    system("clear");
    displayHUI();

//    auto it = find(this->player->getChampions().begin(), this->player->getChampions().end(), champ);
//    int mul = distance(this->player->getChampions().begin(), it);

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

void Game::drawEnemyKilled(vector<vector<int> > prev_map) { // affiche en surbrillance les cases enemies touchées après une attaque
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

void Game::drawSpellDamage(vector<vector<int> > range) { //affiche les dégats maximum des sorts
    system("clear");
    displayHUI();

    for (int i = 0; i < range.size(); i++) {
        cout << "      ";
        for (int j = 0; j < range[i].size(); j++) {
            if (range[i][j] > 0) {
                cout << BGGREEN << range[i][j] << RESET << " ";
            } else {
                cout << WHITE << range[i][j] << " " << RESET;

            }
        }
        cout << endl;
    }
    displayFUI();
}

vector<vector<int> > Game::applyDamage(vector<vector<int> > map, Champion *champ, vector<vector<int> > range) {
    int dmg_alea;
//    auto it = find(this->player->getChampions().begin(), this->player->getChampions().end(), champ);
//    int mul = distance(this->player->getChampions().begin(), it) + 1;
    for (int i = 0; i < range.size(); i++) {
        for (int j = 0; j < range[i].size(); j++) {
            if (range[i][j] > 0 && map[i][j] > 0) {
                dmg_alea = rand() % ((range[i][j] * champ->getAtt()) + 1);
                map[i][j] -= dmg_alea;
                this->player->setMoney(this->player->getMoney() + dmg_alea);
                if (dmg_alea) {
                    cout << "Attaque réussie en " << GREEN << "[" << i << "," << j << "]" << RESET << " !" << endl;
                    cout << "Vous infligez " << GREEN << dmg_alea << " dégats ! " << RESET << " !" << endl;
                }
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
    string user_choice = "\0";
    vector<vector<int> > tmp;
    for (int i = 0; i < this->player->getChampions().size(); ++i) { // Pour chaque champion
        bool invalid_syntax = true;
        //set current_champ to true when its the champion turn to change color on display
        this->player->getChampions()[i]->setCurrentChamp(true);


        while (invalid_syntax) {
            tmp = getMap();
            system("clear");
            this->draw();
            cout << "Au tour de " << GREEN << this->player->getChampions()[i]->getName() << endl;

            cout << "1 Attaque" << endl;
            cout << "2 Boutique" << endl;
            cout << "3 Changer de position" << endl;
            cout << "4 Passer son tour" << endl;
            cin >> user_choice;

            if (user_choice == "1") { // Attaque


                int spell_choice_back = 5;
                int spell_choice;
                bool confirm_spell_choice;
                system("clear");
                this->draw();
                do {

                    for (int j = 0; j <this->player->getChampions()[i]->getSpells().size(); j++){ // Pour tout les sort du champion

                        if (j != spell_choice_back) {
                            cout << j + 1 << " - " << this->player->getChampions()[i]->getSpells()[j]->getName()
                                 << endl;
                        } else {
                            cout << j + 1 << " - " << this->player->getChampions()[i]->getSpells()[j]->getName()
                                 << " - Confirmer" << endl;
                        }
                    }


                    invalid_syntax = true;
                    while (invalid_syntax) { // Choix sort
                        cin >> user_choice;
                        if (user_choice == "1" || user_choice == "2" || user_choice == "3" || user_choice == "4" || user_choice == "5") {
                            spell_choice = stoi(user_choice) - 1;
                            invalid_syntax = false;
                        } else {
                            cout << "Invalid syntaxe !" << endl;
                            invalid_syntax = true;
                        }
                    }


                    if (spell_choice_back != spell_choice) { // Si tu choisi un sort different
                        system("clear");
                        this->drawRange(this->player->getChampions()[i]->getSpells()[spell_choice]->getRange(),
                                        this->player->getChampions()[i]); // Dessine la range
                        confirm_spell_choice = false;
                    }else{
                        confirm_spell_choice = true;
                    }

                    spell_choice_back = spell_choice;

                } while (!confirm_spell_choice);

                if (spell_choice != 4){
                    setMap(this->applyDamage(this->getMap(), this->player->getChampions()[i],
                                             this->player->getChampions()[i]->getSpells()[spell_choice]->getRange()));
                    this->player->setMana(this->player->getMana() -
                                          this->player->getChampions()[i]->getSpells()[spell_choice]->getManaCost());
                    this->drawEnemyKilled(tmp);
                }
                else if (spell_choice == 4) {
                    invalid_syntax = true;
                }



            } else if (user_choice == "2") {
                //Banque

                invalid_syntax = false;
            } else if (user_choice == "3") {


                char sprite_choice;
                cout << "Avec quel champion souhaitez vous changer de position ?" << endl;
                cin >> sprite_choice;
                this->player->swapChamp(this->player->getChampions()[i]->getSprite(), sprite_choice);
                invalid_syntax = false;
            } else if (user_choice == "4") {

                invalid_syntax = false;
            } else {
                cout << "Invalid Syntaxe" << endl;
                invalid_syntax = true;
            }
            //setting the current champ to false
            this->player->getChampions()[i]->setCurrentChamp(false);
        }
    }
    cout << "Appuyez sur une touche puis sur Enter pour passer au round suivant.." << endl;
    cin >> user_choice;
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


