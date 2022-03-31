//
// Created by Matthieu Deroir on 23/03/2022.
//

#ifndef SIMIAMSVSMAAWOX_PLAYER_H
#define SIMIAMSVSMAAWOX_PLAYER_H

#include "header.h"
#include "Champion.h"


class Player {
private:
    string name;
    int hp;
    int money;
    int score;
    vector<Champion> champ;

public:
    //Class Constructor
    Player(string name, int hp, int money, int score);

    // Getter & Setter
    string getName();
    void setName(string name);

    int getHp();
    void setHp(int hp);

    int getMoney();
    void setMoney(int att);

    int getScore();
    void setScore(int score);

    //toString
    void toString();
    // Methods

};

#endif //SIMIAMSVSMAAWOX_PLAYER_H
