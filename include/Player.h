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
    int gameOver;

    int score;
    vector<Champion*> champs;

    //upgrades base cost const
    int UPGRADE_COST_COEFF; //for all upgrades
    int MANA_BASE;
    int MANA_REGEN_BASE;
    int MANA_REGEN_BASE_COST;
    int MANA_BASE_COST;
    int MANA_REGEN_BASE_UP;
    int MANA_BASE_UP;

    int HP_BASE;
    int HP_REGEN_BASE_COST;
    int HP_BASE_COST;
    int HP_REGEN_BASE_UP;
    int HP_BASE_UP;

    int HP_POTION_10;
    int HP_POTION_50;
    int HP_POTION_MAX;

    int MANA_POTION_MAX;

public:
    //default constructor
    Player();
    //Class Constructor
    Player(string name, int hp, int money, int mana, int mana_regen, int score, vector<Champion*> champs);

    Player* playerInitialization();

    // Getter & Setter
    string getName();
    void setName(string name);

    int getHp();
    void setHp(int hp);

    int getMaxHp();
    void setMaxHp(int max_hp);

    int getHpRegen();
    void setHpRegen(int hp_regen);

    int getMaxHpBaseCost();

    int getHpRegenBaseCost();

    int getMaxHpBaseUp();

    int getHpRegenBaseUp();

    int getManaBase();
    int getManaRegenBase();
    int getHpBase();

    int getHpPotion10();
    int getHpPotion50();
    int getHpPotionMax();

    int getManaPotion();

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

    int getMaxManaBaseCost();

    int getManaRegenBaseCost();

    int getMaxManaBaseUp();

    int getManaRegenBaseUp();

    int getScore();
    void setScore(int score);

    int getGameOver();
    void setGameOver(int gameOver);

    vector<Champion*> getChampions();
    void setChampions(vector<Champion*> champs);

    //toString
    void toString();
    // Methods

    void takeDamage(int damage, int round);
    void spendMoney(int price);
    void spendMana(int mana);
    void rangeUpdate();
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
