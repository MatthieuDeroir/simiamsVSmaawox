//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/header.h"
#include "../include/Game.h"



Game::Game(int w, int h, Player *player, char os) {
    this->MAP_WIDTH = w;
    this->MAP_HEIGHT = h;
    this->MAX_ENEMY = 61;
    this->os = os;
    this->player = player;
    this->round = 0;
}

//game menu displays


void Game::startMenu() {
    string user_input = "\0";
    clear(os);
    while (user_input != "1" && user_input != "2") {
        cout << BGBLACK
             << "###############################################################################################"
             << RESET << endl;
        cout << MAGENTA << BGBLACK << "#    __| _)             _)          " << RESET << BGBLACK << "\\\\   /  __|     "
             << YELLOW << "\\   |                                     #" << RESET << endl;
        cout << MAGENTA << BGBLACK << "#  \\__ \\  |   ` \\  (_-<  |   ` \\    " << RESET << BGBLACK
             << " \\ \\ / \\__ \\ " << YELLOW << "   |\\/ |   _` |   _` | \\ \\  \\ /  _ \\ \\ \\ /   #" << RESET
             << endl;
        cout << MAGENTA << BGBLACK << "#  ____/ _| _|_|_| ___/ _| _|_|_|    " << RESET << BGBLACK << " \\_/  ____/   "
             << YELLOW << "_|  _| \\__,_| \\__,_|  \\_/\\_/ \\___/  _\\_\\   #" << RESET << endl;
        cout << BGBLACK
             << "###############################################################################################"
             << RESET << endl;
        cout << BGBLACK
             << "#                                    1 - Nouvelle Partie                                      #"
             << RESET << endl;
        cout << BGBLACK
             << "#                                    2 - Charger une Partie                                   #"
             << RESET << endl;
        cout << BGBLACK
             << "#                                    3 - Aide                                                 #"
             << RESET << endl;
        cout << BGBLACK
             << "#                                    4 - Options                                              #"
             << RESET << endl;
        cout << BGBLACK
             << "#                                    5 - Quitter                                              #"
             << RESET << endl;
        cout << BGBLACK
             << "###############################################################################################"
             << RESET << endl;
        cin >> user_input;
        if (user_input == "3") {
            this->helpMenu();
        } else if (user_input == "4") {
            this->optionsMenu();
        }

    }
    this->init();
}

void Game::helpMenu() {
    clear(os);

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

void Game::optionsMenu() {
    clear(os);

    string user_input = "\0";
    cout << "WORK IN PROGRESS" << endl;
    cout << "Appuyer sur une touche puis sur Entrer pour revenir au menu principal..." << endl;
    cin >> user_input;
}

bool Game::gameOverMenu() {
    string user_input;
    clear(os);


    cout << RED << "@@@@@@@@   @@@@@@   @@@@@@@@@@   @@@@@@@@      @@@@@@   @@@  @@@  @@@@@@@@  @@@@@@@" << endl;
    cout << "@@@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@     @@@@@@@@  @@@  @@@  @@@@@@@@  @@@@@@@@" << endl;
    cout << "!@@        @@!  @@@  @@! @@! @@!  @@!          @@!  @@@  @@!  @@@  @@!       @@!  @@@" << endl;
    cout << "!@!        !@!  @!@  !@! !@! !@!  !@!          !@!  @!@  !@!  @!@  !@!       !@!  @!@" << endl;
    cout << "!@! @!@!@  @!@!@!@!  @!! !!@ @!@  @!!!:!       @!@  !@!  @!@  !@!  @!!!:!    @!@!!@!" << endl;
    cout << " !! !!@!!  !!!@!!!!  !@!   ! !@!  !!!!!:       !@!  !!!  !@!  !!!  !!!!!:    !!@!@!" << endl;
    cout << ":!!   !!:  !!:  !!!  !!:     !!:  !!:          !!:  !!!  :!:  !!:  !!:       !!: :!!" << endl;
    cout << ":!:   !::  :!:  !:!  :!:     :!:  :!:          :!:  !:!   ::!!:!   :!:       :!:  !:!" << endl;
    cout << "::: ::::  ::   :::  :::     ::    :: ::::     ::::: ::    ::::     :: ::::  ::   :::" << endl;
    cout << ":: :: :    :   : :   :      :    : :: ::       : :  :      :      : :: ::    :   : :" << RESET << endl;

    cout << endl << "Voulez vous rejouer ?(y/n)" << endl;
    cin >> user_input;

    return (user_input == "y");
}

//main game loop functions

//initialisation de la map de jeu en fonction des constante établies
void Game::init() {
    vector<vector<int> > map(this->MAP_HEIGHT, vector<int>(this->MAP_WIDTH, 0));
    this->setMap(map);
}

//boucle principale du jeu
void Game::update() {

    //fais avancer les enemis
    setMap(push_row(getMap()));
    //incremente le nb de round par 1
    setRound((getRound()) + 1);
    //spawn les enemies
    setMap(spawner(getMap(), getRound()));
    //tour du joueur
    playerTurn(); //TODO PLAYER TURN
    //applique les degats infligés au joueur s'il y en a
    this->player->takeDamage(count_line(getMap()[getMap().size() - 1]), this->round);
}

//fonction principal d'affichage de la map
void Game::draw() {
    clear(os);

    displayHUI();
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
//permet d'additionner les valeurs d'un vecteur
//utile pour compter les dégats infligés au joueur
int Game::count_line(vector<int> map) {
    int i = 0;
    int count = 0;

    while (i < map.size()) {
        count += map[i];
        i++;
    }
    return count;
}

//fonction qui permet de faire avancer les valeurs d'un vector à deux dimensions d'une ligne à la suivante
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

//fait apparaître les enemis au début de chaque round à la première ligne du vector
vector<vector<int> > Game::spawner(vector<vector<int> > vec, int round) {
    int en_nb = (rand() % ((1 + round))) + 1;
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
    cout << BGMAGENTA << BLACK << "######## ROUND N. : " << getRound() << " ########" << RESET << endl;
}

void
Game::displayFUI() { //affichage du bas de l'UI

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
    cout << "# " << MAGENTA << this->player->getChampions()[0]->getName() << RESET <<  " - Attaque : " << this->player->getChampions()[0]->getAtt() << RESET;
    multiprint(" ", 14-(this->player->getChampions()[0]->getName().length() + to_string(this->player->getChampions()[0]->getAtt()).length()));
    cout << "#" << endl;
    cout << "# " << MAGENTA << this->player->getChampions()[1]->getName() << RESET << " - Attaque : " << this->player->getChampions()[1]->getAtt() << RESET;
    multiprint(" ", 14-(this->player->getChampions()[1]->getName().length() + to_string(this->player->getChampions()[0]->getAtt()).length()));
    cout << "#" << endl;
    cout << "# " << MAGENTA << this->player->getChampions()[2]->getName() << RESET << " - Attaque : " << this->player->getChampions()[2]->getAtt() << RESET;
    multiprint(" ", 14-(this->player->getChampions()[2]->getName().length() + to_string(this->player->getChampions()[0]->getAtt()).length()));
    cout << "#" << endl;
    cout << "##############################" << endl;

}

// vector comparison

void Game::drawRange(vector<vector<int> > range, Champion *champ) { // affiche les cases visées par une attaque
    clear(os);

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

void Game::drawEnemyKilled(
        vector<vector<int> > prev_map) { // affiche en surbrillance les cases enemies touchées après une attaque
    clear(os);

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
    clear(os);

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

void Game::drawSpellDamageShop(vector<vector<int> > range) { //affiche les dégats maximum des sorts ainsi que leur amélioration potentielle
    clear(os);

    for (int i = 0; i < range.size(); i++) {
        cout << "      ";
        for (int j = 0; j < range[i].size(); j++) {
            if (range[i][j] > 0) {
                cout << BGWHITE << BLACK << this->enemy_dict[range[i][j]] << RESET << " ";
            } else {
                cout << WHITE << range[i][j] << " " << RESET;

            }
        }
        cout << GREEN << "    =======>     " << RESET;
        for (int j = 0; j < range[i].size(); j++) {
            if (range[i][j] > 0) {
                cout << BGGREEN << enemy_dict[range[i][j] + 1] << RESET << " ";
            } else {
                cout << WHITE << range[i][j] << " " << RESET;

            }
        }

        cout << endl;
    }
    displayFUI();
}

//applique les dégats d'un sort donné (via sa caractéristique range) sur une map =
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
                this->player->setMoney(this->player->getMoney() + (dmg_alea * (1 + (this->round / 10))));
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
        this->draw();
        cout << "Boutique " << this->player->getMoney() << " $imiam$" << endl << endl;
        cout << "1 - Stat" << endl;
        cout << "2 - Potions" << endl;
        cout << "3 - Champion/Sorts" << endl;
        cout << "4 - Retour" << endl;
        cin >> user_choice;

        if (user_choice == "1") {
            invalid_syntaxte = false;
            while (!invalid_syntaxte) {
                this->draw();
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
                         << (this->player->getMaxHp() - this->player->getHpBase()) / this->player->getMaxHpBaseUp() *
                            this->player->getMaxHpBaseCost() * 2 << "$imiam$  "
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
                        ((this->player->getManaRegen() - this->player->getManaRegenBase()) /
                         this->player->getManaRegenBaseUp() * this->player->getManaRegenBaseCost() * 2) >= 0 &&
                        this->player->getManaRegen() > this->player->getManaRegenBase()) {
                        this->player->setMoney(this->player->getMoney() -
                                               ((this->player->getManaRegen() - this->player->getManaRegenBase()) /
                                                this->player->getManaRegenBaseUp() *
                                                this->player->getManaRegenBaseCost() * 2));
                        this->player->setManaRegen(this->player->getManaRegen() + this->player->getManaRegenBaseUp());
                    } else if (this->player->getManaRegen() == this->player->getManaRegenBase() &&
                               this->player->getMoney() >= this->player->getManaRegenBaseCost() * 2) {
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
                        this->player->setHp(this->player->getHp() + this->player->getMaxManaBaseUp());
                    } else if (this->player->getMaxHp() == this->player->getHpBase() &&
                               this->player->getMoney() >= this->player->getMaxHpBaseCost() *
                                                           2) {
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
                this->draw();
                cout << "Boutique " << this->player->getMoney() << " $imiam$" << endl << endl;
                cout << this->player->getHp() << "/" << this->player->getMaxHp() << " Hp / "
                     << this->player->getMoney() << " $imiam$" << endl;
                cout << "1 - Potion " << this->player->getHpPotion10() << " HP / " << "10 $imiam$"
                     << endl;
                cout << "2 - Super Potion " << this->player->getHpPotion50() << " HP / "
                     << "50 $imiam$" << endl;
                cout << "3 - Maxi Potion" << this->player->getHpPotionMax() << " HP / "
                     << this->player->getMaxHp() / 2 << "$imiam$" << endl;
                cout << "4 - Manawoxide " << this->player->getMaxMana() << " Ø / " << this->player->getMaxMana() / 2 << endl;
                cout << "5 - Retour" << endl;
                cin >> user_choice;

                if (user_choice == "1" || user_choice == "2" || user_choice == "3" || user_choice == "4" ||
                    user_choice == "5") {
                    if (user_choice != "5") {
                        if (user_choice == "1") {
                            if (this->player->getMoney() >= 10) {
                                if (this->player->getHp() < this->player->getMaxHp()) {
                                if (this->player->getHp() - this->player->getMaxHp() >
                                    this->player->getHpPotion10()) {
                                    cout << this->player->getName() << " boit une potion" << this->player->getName() << " gagne "
                                         << this->player->getHpPotion10() << " HP" << endl;
                                    this->player->setHp(this->player->getHp() + this->player->getHpPotion10());
                                    this->player->setMoney(this->player->getMoney() - 10);
                                } else if (this->player->getHp() - this->player->getMaxHp() <
                                           this->player->getHpPotion10()) {
                                    cout << this->player->getName() << " boit une potion " << this->player->getName() << " gagne "
                                         << this->player->getHp() - this->player->getMaxHp() << "HP" << endl;
                                    this->player->setHp(this->player->getMaxHp());
                                    this->player->setMoney(this->player->getMoney() - 10);
                                }
                            } else {
                                    cout << RED << "$imiam$ insuffisant" << RESET << endl;
                                }
                            }else{
                                cout << RED << "Hp au déjà au max" << endl << endl;
                            }
                        } else if (user_choice == "2") {
                            if (this->player->getHp() < this->player->getMaxHp()) {
                                if (this->player->getMoney() >= 40) {
                                    if (this->player->getHp() - this->player->getMaxHp() >
                                        this->player->getHpPotion50()) {
                                        cout << this->player->getName() << " boit une super potion "
                                             << this->player->getName() << " gagne "
                                             << this->player->getHpPotion50() << " HP" << endl;
                                        this->player->setHp(this->player->getHp() + this->player->getHpPotion50());
                                        this->player->setMoney(this->player->getMoney() - 50);
                                    } else if (this->player->getHp() - this->player->getMaxHp() <
                                               this->player->getHpPotion50()) {
                                        cout << this->player->getName() << " boit une super potion "
                                             << this->player->getName() << " gagne "
                                             << this->player->getHp() - this->player->getMaxHp() << "HP" << endl;
                                        this->player->setHp(this->player->getMaxHp());
                                        this->player->setMoney(this->player->getMoney() - 50);
                                    }
                                } else {
                                    cout << RED << "$imiam$ insuffisant" << RESET << endl;
                                }
                            }else{
                                cout << RED << "Hp au déjà au max" << endl << endl;
                            }
                        } else if (user_choice == "3") {
                            if (this->player->getHp() < this->player->getMaxHp()) {
                                if (this->player->getMoney() >= this->player->getMaxHp() / 2) {
                                    cout << this->player->getName() << " boit une maxi potion "
                                         << this->player->getName()
                                         << " gagne "
                                         << this->player->getHp() - this->player->getMaxHp() << " HP" << endl;
                                    this->player->setHp(this->player->getMaxHp());
                                    this->player->setMoney(this->player->getMoney() - this->player->getMaxHp() / 2);
                                } else {
                                    cout << RED << "$imiam$ insuffisant" << RESET << endl;
                                }
                            }else{
                                cout << RED << "Hp au déjà au max" << endl << endl;
                            }
                        }
                        if (user_choice == "4") {
                            if (this->player->getMana() < this->player->getMaxMana()) {
                                if (this->player->getMoney() >= this->player->getMaxMana() / 2) {
                                    if (this->player->getMana() - this->player->getMaxMana() >
                                        this->player->getManaPotion()) {
                                        cout << this->player->getName() << " boit un manawoxide : "
                                             << this->player->getName() << " gagne "
                                             << this->player->getManaPotion() << " Ø" << endl;
                                        this->player->setHp(this->player->getMana() + this->player->getManaPotion());
                                        this->player->setMoney(this->player->getMaxMana() / 2);
                                    } else if (this->player->getMana() - this->player->getMaxMana() <
                                               this->player->getManaPotion()) {
                                        cout << this->player->getName() << " boit un manawoxide : "
                                             << this->player->getName() << " gagne "
                                             << this->player->getMana() - this->player->getMaxMana() << "Ø" << endl;
                                        this->player->setMana(this->player->getMaxMana());
                                        this->player->setMoney(
                                                this->player->getMoney() - this->player->getMaxMana() / 2);
                                    }
                                } else {
                                    cout << RED << "$imiam$ insuffisant" << RESET << endl;
                                }
                            }else{
                                cout << RED << "Manawox déjà au max" << endl << endl;
                            }
                        }
                    } else if (user_choice == "5") {
                        invalid_syntaxte = true;
                    }
                } else {
                    invalid_syntaxte = false;
                }
            }
        } else if (user_choice == "3") {
            invalid_syntaxte = false;
            while (!invalid_syntaxte) {
                this->draw();
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
                        this->player->setMoney(this->player->getMoney() - (champion->getAtt() - 1) * 100);
                    } else {
                        cout << RED << "$imiam$ insuffisant" << RESET << endl;
                    }
                } else if (user_choice == "2" || user_choice == "3" || user_choice == "4" ||
                           user_choice == "5") {
                    int spell_index = stoi(user_choice) - 2;
                    if (this->player->getMoney() -
                        count_square(champion->getSpells()[spell_index]->getRange()) >= 0) {

                        this->drawSpellDamageShop(champion->getSpells()[stoi(user_choice) - 2]->getRange());
                        cout << "1 - confirmer l'amelioration de "
                             << champion->getSpells()[stoi(user_choice) - 2]->getName() << endl;
                        cout << "2 - Retour" << endl;
                        cin >> user_choice;
                        if (user_choice == "1") {
                            champion->getSpells()[spell_index]->upgradeSpell();
                            cout << "Vous ameliorez l'attaque de "
                                 << champion->getSpells()[spell_index]->getName()
                                 << endl;
                            this->player->setMoney(this->player->getMoney() -
                                                   count_square(
                                                           champion->getSpells()[spell_index]->getRange()));

                            //mis a jour de la range quand on quitte le shop
                            this->player->rangeUpdate();
                        }
                    } else {
                        cout << RED << "$imiam$ insuffisant" << RESET << endl;
                    }
                } else {
                    invalid_syntaxte = true;
                }
            }
        } else {
            flag = true;
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
            clear(os);

            this->draw();
            cout << "# Au tour de " << GREEN << this->player->getChampions()[i]->getName() << RESET;
            multiprint(" ", 16 - this->player->getChampions()[i]->getName().length());
            cout << "#"
                 << endl;
            cout << "##############################" << endl;
            cout << "# 1 - "<< CYAN << "Sorts"<< RESET <<"                  #" << endl;
            cout << "# 2 - "<< YELLOW << "Boutique"<< RESET <<"               #" << endl;
            cout << "# 3 - "<< MAGENTA << "Changer de position"<< RESET <<"    #" << endl;
            cout << "# 4 - "<< RED << "Passer son tour"<< RESET <<"        #" << endl;
            cout << "##############################" << endl;

            cin >> user_choice;

            if (user_choice == "1") { // Attaque

                int spell_choice_back = 6;
                int spell_choice;
                bool confirm_spell_choice;
                clear(os);

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
                        clear(os);

                        this->drawRange(this->player->getChampions()[i]->getSpells()[spell_choice]->getRange(),
                                        this->player->getChampions()[i]); // Dessine la range
                        confirm_spell_choice = false;
                    } else {
                        confirm_spell_choice = true;
                    }

                    spell_choice_back = spell_choice;

                } while (!confirm_spell_choice);

                if (spell_choice != 4) {
                    this->player->setMana(this->player->getMana() -
                                          this->player->getChampions()[i]->getSpells()[spell_choice]->getManaCost());
                    setMap(this->applyDamage(this->getMap(), this->player->getChampions()[i],
                                             this->player->getChampions()[i]->getSpells()[spell_choice]->getRange()));
                    this->drawEnemyKilled(tmp);
                    if (i != 2) {
                        cout << "Appuyer sur une touche puis sur Entrer pour passer au tour du champion suivant..."
                             << endl;
                        cin >> user_choice;
                    }
                } else if (spell_choice == 4) {
                    invalid_syntax = true;
                }


            } else if (user_choice == "2") {
                //Banque
                this->shop(this->player->getChampions()[i]);

            } else if (user_choice == "3") {


                char sprite_choice;
                cout << "Avec quel champion souhaitez vous changer de position ?" << endl;
                cin >> sprite_choice;
                if (this->player->getChampions()[i]->getSprite() != sprite_choice){
                    this->player->swapChamp(this->player->getChampions()[i]->getSprite(), sprite_choice);
                    invalid_syntax = false;
                }
                else {
                    invalid_syntax = true;
                }
            } else if (user_choice == "4") {

                cout << YELLOW << this->player->getChampions()[i]->getName() << RESET << " passe son tour !"
                     << endl;
                cout << "Appuyez sur une touche puis sur Enter pour passer au champion suivant.." << endl;
                invalid_syntax = false;

            } else {
                cout << RED << "Invalid syntaxe !" << RESET << endl;
                invalid_syntax = true;
            }
            //setting the current champ to false
            for (int i = 0; i < this->player->getChampions().size(); i++){
                this->player->getChampions()[i]->setCurrentChamp(false);
            }
        }
    }

    cout << "Appuyez sur une touche puis sur Enter pour passer au round suivant.." << endl;
    this->player->regenMana();
    cin >> user_choice;
}

void Game::clear(char os){
    if (os == 'm'){
        system("clear");
    }
    else if (os == 'w'){
        system("cls");
    }
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
