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
    int def;
    int money;
    int max_mana;
    int mana;
    int mana_regen;
    int score;
    vector<Champion*> champs;

    //upgrades base cost const
    int UPGRADE_COST_COEFF; //for all upgrades
    int MANA_REGEN_BASE_COST;
    int MANA_BASE_COST;
    int MANA_REGEN_BASE_UP;
    int MANA_BASE_UP;

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

    int getDef();
    void setDef(int def);

    int getMoney();
    void setMoney(int money);

    int getMana();
    void setMana(int mana);

    int getMaxMana();
    void setMaxMana(int max_mana);

    int getManaRegen();
    void setManaRegen(int mana);

    int getScore();
    void setScore(int score);

    vector<Champion*> getChampions();
    void setChampions(vector<Champion*> champs);

    //toString
    void toString();
    // Methods

    void takeDamage(int damage, int round);
    void spendMoney(int price);
    void spendMana(int mana);
    void rangeUpdate(Champion* champ1, Champion* champ2);
    void swapChamp(char champ1, char champ2);

    //Upgrades
    void upgradeDef();
    void upgradeHpMax();
    void upgradeManaMax();
    void upgradeManaRegen();

    //Regen
    void regenHp();
    void regenMana();



};

#endif //SIMIAMSVSMAAWOX_PLAYER_H
