//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/header.h"
class Player {
private:
    string name;
    char sprite;
    int hp;
    int att;
    int def;
    int money;

public:
    Player(string name, int hp, int att, int def, int money, char sprite){
        this->name = name;
        this->hp = hp;
        this->att = att;
        this->def = def;
        this->money = money;
        this->sprite = sprite;
    }


    // Getter & Setter
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }

    int getHp(){
        return this->hp;
    }
    void setHp(int hp){
        this->hp = hp;
    }

    int getAtt(){
        return this->att;
    }
    void setAtt(int att){
        this->att = att;
    }

    int getDef(){
        return this->def;
    }
    void setDef(int def){
        this->def = def;
    }

    int getMoney(){
        return this->money;
    }
    void setMoney(int att){
        this->money = money;
    }

    char getSprite(){
        return this->sprite;
    }
    void setSprite(char sprite){
        this->sprite = sprite;
    }





    // Methods



};