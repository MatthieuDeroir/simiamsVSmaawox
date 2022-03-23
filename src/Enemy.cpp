//
// Created by Matthieu Deroir on 23/03/2022.
//

#include "../include/Enemy.h"


Enemy::Enemy(char sprite, int x, int y) {
    this->hp = 10;
    this->att = 10;
    this->sprite = sprite;
    this->x = x;
    this->y = y;
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

int Enemy::getX() {
    return this->x;
}
int Enemy::setX(int x) {
    this->x = x;
}

int Enemy::getY() {
    return this->x;
}
int Enemy::setY(int y) {
    this->y = y;
}

// Methods
void Enemy::toString() {
    cout << "HP: " << this->hp << "; ATT: " << this->att << "// SPRITE: " << this->sprite << endl;
}

