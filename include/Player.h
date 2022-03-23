//
// Created by Matthieu Deroir on 23/03/2022.
//

#ifndef SIMIAMSVSMAAWOX_PLAYER_H
#define SIMIAMSVSMAAWOX_PLAYER_H

#include "header.h"


class Player {
private:
    string name;
    char sprite;
    int hp;
    int att;
    int def;
    int money;
    int score;

public:
    //Class Constructor
    Player(string name, int hp, int att, int def, int money, char sprite, int score);

    // Getter & Setter
    string getName();
    void setName(string name);

    int getHp();
    void setHp(int hp);

    int getAtt();
    void setAtt(int att);

    int getDef();
    void setDef(int def);

    int getMoney();
    void setMoney(int att);

    int getScore();
    void setScore(int score);

    char getSprite();
    void setSprite(char sprite);
    //toString
    void toString();
    // Methods

};

#endif //SIMIAMSVSMAAWOX_PLAYER_H
