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
    int max_hp;
    int hp;
    int money;
    int mana;
    int score;
    vector<Champion*> champs;

public:
    //Class Constructor
    Player(string name, int hp, int money, int mana, int score, vector<Champion*> champs);

    // Getter & Setter
    string getName();
    void setName(string name);

    int getHp();
    void setHp(int hp);

    int getMaxHp();
    void setMaxHp(int max_hp);

    int getMoney();
    void setMoney(int money);

    int getMana();
    void setMana(int mana);

    int getScore();
    void setScore(int score);

    vector<Champion*> getChampions();
    void setChampions(vector<Champion*> champs);

    //toString
    void toString();
    // Methods

    void takeDamage(int damage);
    void spendMoney(int price);
    void spendMana(int mana);

};

#endif //SIMIAMSVSMAAWOX_PLAYER_H
