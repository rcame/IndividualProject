//
// Created by richard on 11/03/16.
//

#include "Character.h"

Character::Character(int posX, int posY) {
    terrainPosX = posX;
    terrainPosY = posY;
}

void Character::setVars(int health, int level, int attack, int defence) {
    this->health = health;
    this->level = level;
    this->attack = attack;
    this->defence = defence;

}

void Character::move(int dir, float timestep) {

}

bool Character::isOnScreen(int screenPosX, int screenPosY) {
    return terrainPosX >= screenPosX
            && terrainPosX <= screenPosX + SCREEN_WIDTH/BLOCK_WIDTH
            && terrainPosY >= screenPosY
            && terrainPosY <= screenPosY + SCREEN_HEIGHT/BLOCK_WIDTH;

}

void Character::printOut() {
    cout << "level: " << level << " health: " << health <<
            " Attack: " << attack << " Defence: " << defence << endl;
}