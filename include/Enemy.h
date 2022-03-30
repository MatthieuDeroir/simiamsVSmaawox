//
// Created by Matthieu Deroir on 23/03/2022.
//

#ifndef SIMIAMSVSMAAWOX_ENEMY_H
#define SIMIAMSVSMAAWOX_ENEMY_H

#include "header.h"


class Enemy {
private:
    char sprite;
    int hp;
    int att;
    int x;
    int y;

public:
    Enemy(char sprite, int x, int y);


    // Getter & Setter
    int getHp();
    void setHp(int hp);

    int getAtt();
    void setAtt(int att);

    char getSprite();
    void setSprite(char sprite);

    int getX();
    void setX(int x);

    int getY();
    void setY(int y);
    //toString
    void toString();
    // Methods

};


#endif //SIMIAMSVSMAAWOX_ENEMY_H
