//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/Enemy.h"


Enemy::Enemy(char sprite) {
    this->hp = 10;
    this->att = 10;
    this->sprite = sprite;
}

// Getter & Setter
int Enemy::getHp() {
    return this->hp;
}

void Enemy::setHp(int hp) {
    this->hp = hp;
}

int Enemy::getAtt() {
    return this->att;
}

void Enemy::setAtt(int att) {
    this->att = att;
}

char Enemy::getSprite() {
    return this->sprite;
}

char Enemy::setSprite(char sprite) {
    this->sprite = sprite;
}

// Methods
void Enemy::toString() {
    cout << "HP: " << this->hp << "; ATT: " << this->att << "// SPRITE: " << this->sprite << endl;
}

