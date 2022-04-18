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

//game menu displays

void Game::startMenu() {
    string user_input = "\0";
    system("clear");
    while (user_input != "1" && user_input != "2"){
        cout << BGBLACK << "###############################################################################################" << RESET << endl;
        cout << MAGENTA << BGBLACK << "#    __| _)             _)          "<< RESET << BGBLACK <<"\\\\   /  __|     "<< YELLOW <<"\\   |                                     #" <<  RESET << endl;
        cout << MAGENTA << BGBLACK <<"#  \\__ \\  |   ` \\  (_-<  |   ` \\    " << RESET << BGBLACK << " \\ \\ / \\__ \\ "<< YELLOW <<"   |\\/ |   _` |   _` | \\ \\  \\ /  _ \\ \\ \\ /   #" << RESET << endl;
        cout << MAGENTA << BGBLACK << "#  ____/ _| _|_|_| ___/ _| _|_|_|    " << RESET << BGBLACK << " \\_/  ____/   "<< YELLOW <<"_|  _| \\__,_| \\__,_|  \\_/\\_/ \\___/  _\\_\\   #" << RESET << endl;
        cout << BGBLACK << "###############################################################################################" << RESET << endl;
        cout << BGBLACK << "#                                    1 - Nouvelle Partie                                      #" << RESET << endl;
        cout << BGBLACK << "#                                    2 - Charger une Partie                                   #" << RESET << endl;
        cout << BGBLACK << "#                                    3 - Aide                                                 #" << RESET << endl;
        cout << BGBLACK << "#                                    4 - Options                                              #" << RESET << endl;
        cout << BGBLACK << "#                                    5 - Quitter                                              #" << RESET << endl;
        cout << BGBLACK << "###############################################################################################" << RESET << endl;
        cin >> user_input;
        if (user_input == "3"){
            this->helpMenu();
        }
        else if (user_input == "4"){
            this->optionsMenu();
        }

    }
    this->init();
}

void Game::helpMenu(){
    system("clear");
    string user_input = "\0";
    cout << BGBLACK << "###############################################################################################"
         << RESET << endl;
    cout << BGBLACK << "#                                 Bienvenue dans " << MAGENTA << "Simsim" << RESET << BGBLACK
         << " vs " << YELLOW << BGBLACK << "Maawox" << RESET << BGBLACK << "                             #" << RESET
         << endl;
    cout << BGBLACK << "###############################################################################################"
         << RESET << endl;
    cout << BGBLACK << "# Vous êtes sur le point d'entrer dans un univers rempli de dangers...                        #"
         << RESET << endl;
    cout << BGBLACK << "# Les Simsims, petites créatures aussi têtues qu'hostiles ont décidé d'envahir le Royaume     #"
         << RESET << endl;
    cout << BGBLACK << "# Vous êtes chargés de l'organisation de la défense du royaume à l'aide des champions du Roi  #"
         << RESET << endl;
    cout << BGBLACK << "###############################################################################################"
         << RESET << endl;
    cout << BLACK << BGWHITE
         << "#                                       Phase de préparation                                  #" << RESET
         << endl;
    cout << BGBLACK << "###############################################################################################"
         << RESET << endl;
    cout << BGBLACK << "# Vous devrez tout d'abord selectionner 3 champions parmi ceux disponibles                    #"
         << RESET << endl;
    cout << BGBLACK << "###############################################################################################"
         << RESET << endl;
    cout << BLACK << BGWHITE
         << "#                                       Phase de jeu                                          #" << RESET
         << endl;
    cout << BGBLACK << "# A chaque round un nombre aléatoire de Simsim apparaitra                                     #"
         << RESET << endl;
    cout << BGBLACK << "# Mais attention, ce nombre s'accroit en fonction du nombre de round écoulé                   #"
         << RESET << endl;
    cout << BGBLACK << "# Vous perdrez des" << GREEN << BGBLACK << " Points de Vies " << RESET << BGBLACK
         << "à chaque fois qu'un Simsim parviendra à passer vos défenses #" << RESET << endl;
    cout << BGBLACK << "# Vous perdez lorsque vous n'avez plus de" << GREEN << BGBLACK << " Points de Vies " << RESET
         << BGBLACK << "!                                    #" << RESET << endl;
    cout << BGBLACK << "# Un round se décompose en trois parties qui correspondent au tour de chaque champion         #"
         << RESET << endl;
    cout << BGBLACK << "# Chaque champion pourra effectuer une action parmi 4 :                                       #"
         << RESET << endl;
    cout << BGBLACK << "# " << RED << "Attaquer " << RESET << BGBLACK
         << " : selection d'un sort à utiliser                                                  #" << RESET << endl;
    cout << BGBLACK << "# " << RED << "Boutique " << RESET << BGBLACK
         << " : selection d'un sort ou d'une caracteristique à améliorer                        #" << RESET << endl;
    cout << BGBLACK << "# " << RED << "Changer de position " << RESET << BGBLACK
         << " : selection d'un champion avec lequel échanger sa place                #" << RESET << endl;
    cout << BGBLACK << "# " << RED << "Passer son tour " << RESET << BGBLACK
         << " : passe le tour du champion                                                #" << RESET << endl;
    cout << BGBLACK << "# Chaque sort coute du" << BLUE << BGBLACK << " Manawox " << RESET << BGBLACK
         << "en fonction de sa puissance                                    #" << RESET << endl;
    cout << BGBLACK << "# Vous récupérez des point de" << BLUE << BGBLACK << " Manawox " << RESET << BGBLACK
         << " à chaque round                                         #" << RESET << endl;
    cout << BGBLACK << "# Vous gagnez des" << YELLOW << BGBLACK << " $imiam$ " << RESET << BGBLACK
         << ", la monnaie du jeu, en fonction du nombre des dégats infligés      #" << RESET << endl;
    cout << BGBLACK << "# Ces" << YELLOW << BGBLACK << " $imiam$ " << RESET << BGBLACK
         << ", vous permettront d'acheter des améliorations dans la boutique                 #" << RESET << endl;
    cout << BGBLACK << "###############################################################################################"
         << RESET << endl;
    cout << "Appuyer sur une touche puis sur Entrer pour revenir au menu principal..." << endl;
    cin >> user_input;
}

void Game::optionsMenu(){
    system("clear");
    string user_input = "\0";
    cout << "WORK IN PROGRESS" << endl;
    cout << "Appuyer sur une touche puis sur Entrer pour revenir au menu principal..." << endl;
    cin >> user_input;
}

bool Game::gameOverMenu() {
    string user_input;
    system("clear");
    cout << RED << "@@@@@@@@   @@@@@@   @@@@@@@@@@   @@@@@@@@      @@@@@@   @@@  @@@  @@@@@@@@  @@@@@@@" << endl;
    cout << "@@@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@     @@@@@@@@  @@@  @@@  @@@@@@@@  @@@@@@@@" << endl;
    cout << "!@@        @@!  @@@  @@! @@! @@!  @@!          @@!  @@@  @@!  @@@  @@!       @@!  @@@" << endl;
    cout << "!@!        !@!  @!@  !@! !@! !@!  !@!          !@!  @!@  !@!  @!@  !@!       !@!  @!@" << endl;
    cout << "!@! @!@!@  @!@!@!@!  @!! !!@ @!@  @!!!:!       @!@  !@!  @!@  !@!  @!!!:!    @!@!!@!" << endl;
    cout << " !! !!@!!  !!!@!!!!  !@!   ! !@!  !!!!!:       !@!  !!!  !@!  !!!  !!!!!:    !!@!@!" << endl;
    cout << ":!!   !!:  !!:  !!!  !!:     !!:  !!:          !!:  !!!  :!:  !!:  !!:       !!: :!!" << endl;
    cout << ":!:   !::  :!:  !:!  :!:     :!:  :!:          :!:  !:!   ::!!:!   :!:       :!:  !:!" << endl;
    cout << "::: ::::  ::   :::  :::     ::    :: ::::     ::::: ::    ::::     :: ::::  ::   :::" << endl;
    cout << " :: :: :    :   : :   :      :    : :: ::       : :  :      :      : :: ::    :   : :" << RESET << endl;
    cout << endl << "Voulez vous rejouer ?(y/n)" << endl;
    cin >> user_input;

    return (user_input == "y");
}

//main game loop functions

void Game::init() {
    vector<vector<int> > map(this->MAP_HEIGHT, vector<int>(this->MAP_WIDTH, 0));
    this->setMap(map);
}

void Game::update() {

    int dmg;
    vector<int> tmp_map = getMap()[getMap().size() - 1];

    dmg = count_line(tmp_map);
    setMap(push_row(getMap()));
    setRound((getRound()) + 1);
    //spawn les enemies
    setMap(spawner(getMap(), getRound()));
    playerTurn(); //TODO PLAYER TURN
    this->player->takeDamage(dmg, this->round);
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
    int en_nb = (rand() % ((1 + round))) + 1;

    cout << en_nb << endl;

    // growing ennemy nb mecanic in functions of round nb =
    if (en_nb > MAP_WIDTH * (MAX_ENEMY - 1))
        en_nb = MAP_WIDTH * (MAX_ENEMY - 1);
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

void
Game::displayFUI() { //affichage du bas de l'UI //TODO : faire les bordures à droite pour qu'elles soient dynamiques avec la valeur d'affichage des stats


    if (this->player->getChampions()[0]->getCurrentChamp()) {
        cout << RESET << "      " << "  " << this->player->getChampions()[0]->getSprite() << MAGENTA << "     "
             << this->player->getChampions()[1]->getSprite() << "     " << this->player->getChampions()[2]->getSprite()
             << RESET << endl;
    } else if (this->player->getChampions()[1]->getCurrentChamp()) {
        cout << MAGENTA << "      " << "  " << this->player->getChampions()[0]->getSprite() << RESET << "     "
             << this->player->getChampions()[1]->getSprite() << MAGENTA << "     "
             << this->player->getChampions()[2]->getSprite()
             << RESET << endl;
    } else if (this->player->getChampions()[2]->getCurrentChamp()) {
        cout << MAGENTA << "      " << "  " << this->player->getChampions()[0]->getSprite() << "     "
             << this->player->getChampions()[1]->getSprite() << "     " << RESET
             << this->player->getChampions()[2]->getSprite()
             << RESET << endl;
    } else {
        cout << RESET << "      " << "  " << this->player->getChampions()[0]->getSprite() << MAGENTA << "     "
             << this->player->getChampions()[1]->getSprite() << "     " << this->player->getChampions()[2]->getSprite()
             << RESET << endl;
    }
    cout << "##############################" << endl;
    cout << "#      " << GREEN << "HitPoint : " << this->player->getHp() << "/" << this->player->getMaxHp() << RESET;
    multiprint(" ", 8 - to_string(this->player->getHp()).length());
    cout << "#" << endl;

    cout << "#      " << CYAN << "Manawox : " << this->player->getMana() << "/" << this->player->getMaxMana() << RESET;
    multiprint(" ", 8 - to_string(this->player->getMana()).length());
    cout << "#" << endl;

    cout << "#      " << YELLOW << "$imiam$ : " << this->player->getMoney() << RESET;
    multiprint(" ", 12 - to_string(this->player->getMoney()).length());
    cout << "#" << endl;
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

void Game::drawEnemyKilled(
        vector<vector<int> > prev_map) { // affiche en surbrillance les cases enemies touchées après une attaque
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
    for (int i = 0; i < range.size(); i++) {
        for (int j = 0; j < range[i].size(); j++) {
            if (range[i][j] > 0 && map[i][j] > 0) {
                dmg_alea = rand() % ((range[i][j] * champ->getAtt()) + 1);
                if (dmg_alea > map[i][j]) {
                    dmg_alea = map[i][j];
                }
                map[i][j] -= dmg_alea;
                this->player->setMoney(this->player->getMoney() + (dmg_alea * this->round));
                if (dmg_alea) {
                    cout << "Attaque réussie en " << GREEN << "[" << i << "," << j << "]" << RESET << " !" << endl;
                    cout << "Vous infligez " << GREEN << dmg_alea << " dégats ! " << RESET << " !" << endl;
                } else
                    cout << "Attaque ratée en" << RED << "[" << i << "," << j << "]" << RESET << " !" << endl;
            }
            if (map[i][j] < 0)
                map[i][j] = 0;
        }
        cout << endl;
    }
    return map;
}


void Game::shop(Champion *champion) {
    string user_choice;
    bool flag = false;
    bool invalid_syntaxte = false;
    while (!flag) {
        cout << "Boutique " << this->player->getMoney() << " $imiam$" << endl << endl;
        cout << "1 - Stat" << endl;
        cout << "2 - Potions" << endl;
        cout << "3 - Champion" << endl;
        cin >> user_choice;

        if (user_choice == "1") {
            invalid_syntaxte = false;
            while(!invalid_syntaxte) {
                cout << "Boutique " << this->player->getMoney() << " $imiam$" << endl << endl;
                if (this->player->getMaxMana() == this->player->getManaBase()) {
                    cout << "1 - MaxMANA - " << this->player->getMaxManaBaseCost() << " $imiam$  "
                         << this->player->getMaxMana()
                         << " Manawox Max." << endl;
                } else {
                    cout << "1 - MaxMANA - "
                         << (this->player->getMaxMana() - this->player->getManaBase()) /
                            this->player->getMaxManaBaseUp() *
                            this->player->getMaxManaBaseCost() * 2 << "$imiam$  "
                         << this->player->getMaxMana() << " Manawox Max." << endl;
                }
                if (this->player->getManaRegen() == this->player->getManaRegenBase()) {
                    cout << "2 - REGENMANA - " << this->player->getManaRegenBaseCost() << "$imiam$  "
                         << this->player->getManaRegen() << " Manawox/Tour" << endl;
                } else {
                    cout << "2 - REGENMANA - " << (this->player->getManaRegen() - this->player->getManaRegenBase()) /
                                                  this->player->getManaRegenBaseUp() *
                                                  this->player->getManaRegenBaseCost() * 2 << "$imiam$  "
                         << this->player->getManaRegen() << " Manawox/Tour" << endl;
                }
                if (this->player->getMaxHp() == this->player->getHpBase()) {
                    cout << "3 - MaxHP - " << this->player->getMaxHpBaseCost() << "$imiam$  "
                         << this->player->getMaxHp()
                         << " Hp Max." << endl;
                } else {
                    cout << "3 - MaxHP - "
                         << (this->player->getMaxHp() - (this->player->getHpBase() / this->player->getMaxHpBaseUp()) *
                                                        this->player->getMaxHpBaseCost() * 2) << "$imiam$  "
                         << this->player->getMaxHp()
                         << " Hp Max." << endl;
                }
                cout << "4 - retour" << endl;
                cin >> user_choice;

                if (user_choice == "1") {
                    if (this->player->getMoney() -
                        ((this->player->getMaxMana() - this->player->getManaBase()) / this->player->getMaxManaBaseUp() *
                         this->player->getMaxManaBaseCost() * 2) >= 0 &&
                        this->player->getMaxMana() > this->player->getManaBase()) {
                        this->player->setMoney(this->player->getMoney() -
                                               ((this->player->getMaxMana() - this->player->getManaBase()) /
                                                this->player->getMaxManaBaseUp() *
                                                this->player->getMaxManaBaseCost() * 2));
                        this->player->setMaxMana(this->player->getMaxMana() + this->player->getMaxManaBaseUp());
                    } else if (this->player->getMaxMana() == this->player->getManaBase() && this->player->getMoney() -
                                                                                            ((this->player->getMaxMana() -
                                                                                              this->player->getManaBase()) /
                                                                                             this->player->getMaxManaBaseUp() *
                                                                                             this->player->getMaxManaBaseCost() *
                                                                                             2) >= 0) {
                        this->player->setMoney(this->player->getMoney() - this->player->getMaxManaBaseCost());
                        this->player->setMaxMana(this->player->getMaxMana() + this->player->getMaxManaBaseUp());
                    } else {
                        cout << RED << "$imiam$ insuffisant" << RESET << endl;
                        invalid_syntaxte = false;
                    }

                } else if (user_choice == "2") {
                    if (this->player->getMoney() -
                        ((this->player->getManaRegen() - this->player->getManaRegenBase()) / this->player->getManaRegenBaseUp() * this->player->getManaRegenBaseCost() * 2) >= 0 && this->player->getManaRegen() > this->player->getManaRegenBase()){
                                                this->player->setMoney(this->player->getMoney() -
                                               ((this->player->getManaRegen() - this->player->getManaRegenBase()) /
                                                this->player->getManaRegenBaseUp() *
                                                this->player->getManaRegenBaseCost() * 2));
                        this->player->setManaRegen(this->player->getManaRegen() + this->player->getManaRegenBaseUp());
                    } else if (this->player->getManaRegen() == this->player->getManaRegenBase() && this->player->getMoney() >= this->player->getManaRegenBaseCost() * 2) {
                        cout << "acac";
                        this->player->setMoney(this->player->getMoney() - this->player->getManaRegenBaseCost());
                        this->player->setManaRegen(this->player->getManaRegen() + this->player->getManaRegenBaseUp());
                    } else {
                        cout << RED << "$imiam$ insuffisant" << RESET << endl;
                        invalid_syntaxte = false;
                    }


                } else if (user_choice == "3") {
                    if (this->player->getMoney() -
                        ((this->player->getMaxHp() - this->player->getHpBase()) / this->player->getMaxHpBaseUp() *
                         this->player->getMaxHpBaseCost() * 2) >= 0 &&
                        this->player->getMaxHp() > this->player->getHpBase()) {
                        this->player->setMoney(this->player->getMoney() -
                                               ((this->player->getMaxHp() - this->player->getHpBase()) /
                                                this->player->getMaxHpBaseUp() *
                                                this->player->getMaxHpBaseCost() * 2));
                        this->player->setMaxHp(this->player->getMaxHp() + this->player->getMaxHpBaseUp());
                    } else if (this->player->getMaxHp() == this->player->getHpBase() && this->player->getMoney() -
                                                                                        ((this->player->getMaxHp() -
                                                                                          this->player->getHpBase()) /
                                                                                         this->player->getMaxHpBaseUp() *
                                                                                         this->player->getMaxHpBaseCost() *
                                                                                         2) >= 0) {
                        this->player->setMoney(this->player->getMoney() - this->player->getMaxHpBaseCost());
                        this->player->setMaxHp(this->player->getMaxHp() + this->player->getMaxHpBaseUp());
                    } else {
                        cout << RED << "$imiam$ insuffisant" << RESET << endl;
                        invalid_syntaxte = false;
                    }
                } else if (user_choice == "4") {
                    invalid_syntaxte = true;
                } else {
                    cout << RED << "Invalid syntaxte" << RESET << endl;
                    invalid_syntaxte = false;
                }
            }
        } else if (user_choice == "2") {
            invalid_syntaxte = false;
            while (!invalid_syntaxte) {
                cout << "Boutique " << this->player->getMoney() << " $imiam$" << endl << endl;
                cout << this->player->getHp() << "/" << this->player->getMaxHp() << " Hp / "
                     << this->player->getMoney() << " $imiam$" << endl;
                cout << "1 - Potion vie minime " << this->player->getHpPotion10() << " HP / " << "10 $imiam$"
                     << endl;
                cout << "2  -Potion vie Un peu cool " << this->player->getHpPotion50() << " HP / "
                     << "50 $imiam$" << endl;
                cout << "3 - Potion regen au max " << this->player->getHpPotionMax() << " HP / "
                     << this->player->getMaxHp() / 2 << "$imiam$" << endl;
                cin >> user_choice;

                if (user_choice == "1" || user_choice == "2" || user_choice == "3" || user_choice == "4") {
                    if (user_choice != "4") {
                        if (user_choice == "1") {
                            if (this->player->getMoney() >= 40) {
                                if (this->player->getHp() - this->player->getMaxHp() >
                                    this->player->getHpPotion10()) {
                                    cout << "Vous buvez de l'eau " << this->player->getName() << " gagne "
                                         << this->player->getHpPotion10() << " HP" << endl;
                                    this->player->setHp(this->player->getHp() + this->player->getHpPotion10());
                                    this->player->setMoney(this->player->getMoney() - 10);
                                } else if (this->player->getHp() - this->player->getMaxHp() <
                                           this->player->getHpPotion10()) {
                                    cout << "Vous buvez de l'eau " << this->player->getName() << " gagne "
                                         << this->player->getHp() - this->player->getMaxHp() << endl;
                                    this->player->setHp(this->player->getMaxHp());
                                    this->player->setMoney(this->player->getMoney() - 10);
                                }
                            } else {
                                cout << RED << "$imiam$ insuffisant" << RESET << endl;
                            }
                        } else if (user_choice == "2") {
                            if (this->player->getMoney() >= 40) {
                                if (this->player->getHp() - this->player->getMaxHp() >
                                    this->player->getHpPotion50()) {
                                    cout << "Vous buvez de l'alcool " << this->player->getName() << " gagne "
                                         << this->player->getHpPotion50() << " HP" << endl;
                                    this->player->setHp(this->player->getHp() + this->player->getHpPotion50());
                                    this->player->setMoney(this->player->getMoney() - 50);
                                } else if (this->player->getHp() - this->player->getMaxHp() <
                                           this->player->getHpPotion50()) {
                                    cout << "Vous buvez de l'alcool " << this->player->getName() << " gagne "
                                         << this->player->getHp() - this->player->getMaxHp() << endl;
                                    this->player->setHp(this->player->getMaxHp());
                                    this->player->setMoney(this->player->getMoney() - 50);
                                }
                            } else {
                                cout << RED << "$imiam$ insuffisant" << RESET << endl;
                            }
                        } else if (user_choice == "3") {
                            if (this->player->getMoney() >= this->player->getMaxHp() / 2) {
                                cout << "Vous buvez beaucoup d'alcool" << this->player->getName() << " gagne "
                                     << this->player->getHp() - this->player->getMaxHp() << " HP" << endl;
                                this->player->setHp(this->player->getMaxHp());
                                this->player->setMoney(this->player->getMoney() - this->player->getMaxHp() / 2);
                            } else {
                                cout << RED << "$imiam$ insuffisant" << RESET << endl;
                            }
                        }
                    } else if (user_choice == "4") {
                        invalid_syntaxte = true;
                    }
                } else {
                    invalid_syntaxte = false;
                }
            }
        } else if (user_choice == "3") {
            invalid_syntaxte = false;
            while (!invalid_syntaxte) {
                cout << "Boutique " << this->player->getMoney() << " $imiam$" << endl << endl;
                cout << "1 - ATTAQUE - " << champion->getAtt() * 100 << " $imiam$" << endl;
                for (int i = 0; i < champion->getSpells().size(); ++i) {
                    cout << i + 2 << " - Ameliorer " << champion->getSpells()[i]->getName() << " - "
                         << count_vec(champion->getSpells()[i]->getRange()) * 2 << " $imiam$" << endl;
                }
                cout << "6 - Retour" << endl;
                cin >> user_choice;
                if (user_choice == "1") {
                    if (this->player->getMoney() - champion->getAtt() * 100 >= 0) {
                        champion->upgradeAtt();
                        cout << champion->getName() << " gagne 1 point d'attaque // Att: " << champion->getAtt()
                             << endl;
                        this->player->setMoney(this->player->getMoney() - champion->getAtt() * 100);
                    } else {
                        cout << RED << "$imiam$ insuffisant" << RESET << endl;
                    }
                } else if (user_choice == "2" || user_choice == "3" || user_choice == "4" ||
                           user_choice == "5") {
                    if (this->player->getMoney() -
                        count_square(champion->getSpells()[stoi(user_choice) - 2]->getRange()) * 2 >= 0) {
                        champion->getSpells()[stoi(user_choice) - 2]->upgradeSpell();
                        cout << "Vous ameliorez l'attaque de "
                             << champion->getSpells()[stoi(user_choice) - 2]->getName()
                             << endl;
                        this->player->setMoney(this->player->getMoney() -
                                               count_square(champion->getSpells()[stoi(user_choice) - 2]->getRange()) *
                                               2);

                    } else {
                        cout << RED << "$imiam$ insuffisant" << RESET << endl;
                    }
                }else{
                    invalid_syntaxte = true;
                }
            }
        } else {
            flag = true;
            //mis a jour de la range quand on quitte le shop
            this->player->rangeUpdate();
        }
    }
}


//Player implementation
void Game::playerTurn() {
    string user_choice = "\0";
    vector<vector<int> > tmp;
    for (int i = 0; i < this->player->getChampions().size(); ++i) { // Pour chaque champion
        bool invalid_syntax = true;
        //set current_champ to true when its the champion turn to change color on display
        this->player->rangeUpdate();
        this->player->getChampions()[i]->setCurrentChamp(true);


        while (invalid_syntax) {
            tmp = getMap();
            system("clear");
            this->draw();
            cout << "# Au tour de " << MAGENTA << this->player->getChampions()[i]->getName() << RESET << "            #"
                 << endl;
            cout << "##############################" << endl;
            cout << "# 1 - Attaque                #" << endl;
            cout << "# 2 - Boutique               #" << endl;
            cout << "# 3 - Changer de position    #" << endl;
            cout << "# 4 - Passer son tour        #" << endl;
            cout << "##############################" << endl;

            cin >> user_choice;

            if (user_choice == "1") { // Attaque

                int spell_choice_back = 6;
                int spell_choice;
                bool confirm_spell_choice;
                system("clear");
                this->draw();
                do {

                    for (int j = 0; j <
                                    this->player->getChampions()[i]->getSpells().size(); j++) { // Pour tout les sort du champion

                        if (j != spell_choice_back) {
                            if (this->player->getMana() <
                                this->player->getChampions()[i]->getSpells()[j]->getManaCost()) {
                                cout << RED << j + 1 << " - "
                                     << this->player->getChampions()[i]->getSpells()[j]->getName()
                                     << " - " << this->player->getChampions()[i]->getSpells()[j]->getManaCost() << " Ø"
                                     << RESET
                                     << endl;

                            } else {
                                cout << j + 1 << " - " << this->player->getChampions()[i]->getSpells()[j]->getName()
                                     << " - " << this->player->getChampions()[i]->getSpells()[j]->getManaCost() << " Ø"
                                     << endl;
                            }
                        } else {
                            if (this->player->getMana() <
                                this->player->getChampions()[i]->getSpells()[j]->getManaCost()) {
                                cout << RED << j + 1 << " - "
                                     << this->player->getChampions()[i]->getSpells()[j]->getName()
                                     << " - " << this->player->getChampions()[i]->getSpells()[j]->getManaCost() << " Ø"
                                     << RESET
                                     << endl;

                            } else {
                                cout << j + 1 << " - " << this->player->getChampions()[i]->getSpells()[j]->getName()
                                     << " - " << this->player->getChampions()[i]->getSpells()[j]->getManaCost() << " Ø"
                                     << " - Confirmer" << endl;
                            }
                        }
                    }
                    cout << "5 - Retour" << endl;


                    invalid_syntax = true;
                    while (invalid_syntax) { // Choix sort
                        cin >> user_choice;
                        if (user_choice == "1" || user_choice == "2" || user_choice == "3" || user_choice == "4" ||
                            user_choice == "5") {
                            spell_choice = stoi(user_choice) - 1;
                            if (spell_choice != 4 && this->player->getMana() <
                                                     this->player->getChampions()[i]->getSpells()[spell_choice]->getManaCost()) {
                                cout << RED << "Manawox Insuffisante" << RESET << endl;
                                cout << endl << "Veuillez selectionner un sort : " << endl;
                                invalid_syntax = true;
                            } else {
                                invalid_syntax = false;
                            }
                        } else {
                            cout << RED << "Invalid syntaxe !" << RESET << endl;
                            cout << endl << "Veuillez selectionner un sort : " << endl;
                            invalid_syntax = true;
                        }
                    }


                    if (spell_choice_back != spell_choice && spell_choice != 4) { // Si tu choisi un sort different
                        system("clear");
                        this->drawRange(this->player->getChampions()[i]->getSpells()[spell_choice]->getRange(),
                                        this->player->getChampions()[i]); // Dessine la range
                        confirm_spell_choice = false;
                    } else {
                        confirm_spell_choice = true;
                    }

                    spell_choice_back = spell_choice;
                    cout << confirm_spell_choice << endl;

                } while (!confirm_spell_choice);

                if (spell_choice != 4) {
                    this->player->setMana(this->player->getMana() -
                                          this->player->getChampions()[i]->getSpells()[spell_choice]->getManaCost());
                    setMap(this->applyDamage(this->getMap(), this->player->getChampions()[i],
                                             this->player->getChampions()[i]->getSpells()[spell_choice]->getRange()));
                    this->drawEnemyKilled(tmp);
                    if (i != 2){
                        cout << "Appuyer sur une touche puis sur Entrer pour passer au tour du champion suivant..." << endl;
                        cin >> user_choice;
                    }
                } else if (spell_choice == 4) {
                    invalid_syntax = true;
                }


            } else if (user_choice == "2") {
                //Banque
                this->shop(this->player->getChampions()[i]);
                invalid_syntax = false;
            } else if (user_choice == "3") {


                char sprite_choice;
                cout << "Avec quel champion souhaitez vous changer de position ?" << endl;
                cin >> sprite_choice;
                this->player->swapChamp(this->player->getChampions()[i]->getSprite(), sprite_choice);
                invalid_syntax = false;

            } else if (user_choice == "4") {

                cout << YELLOW << this->player->getChampions()[i]->getName() << RESET << " passe son tour de pise (lol)"
                     << endl;
                cout << "Appuyez sur une touche puis sur Enter pour passer au champion suivant.." << endl;
                invalid_syntax = false;


            } else {
                cout << RED << "Invalid syntaxe !" << RESET << endl;
                invalid_syntax = true;
            }
            //setting the current champ to false
            this->player->getChampions()[i]->setCurrentChamp(false);
        }
    }
    cout << "Appuyez sur une touche puis sur Enter pour passer au round suivant.." << endl;
    this->player->regenMana();
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
