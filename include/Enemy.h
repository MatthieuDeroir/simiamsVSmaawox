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

public:
    Enemy(char sprite);


    // Getter & Setter
    int getHp();
    void setHp(int hp);

    int getAtt();
    void setAtt(int att);

    char getSprite();
    char setSprite(char sprite);
    //toString
    void toString();
    // Methods

};


#endif //SIMIAMSVSMAAWOX_ENEMY_H
