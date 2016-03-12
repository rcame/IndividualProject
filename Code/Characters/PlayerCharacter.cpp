#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() {
    //Initialize the position at the middle of the screen and in the middle
    // of a square
    terrainPosX = STARTX + ((SCREEN_WIDTH /2) / BLOCK_WIDTH);
    terrainPosY = STARTY + ((SCREEN_HEIGHT/2) /BLOCK_WIDTH);

    screenPosX = (terrainPosX - STARTX) * BLOCK_WIDTH - BLOCK_WIDTH/2;
    screenPosY = (terrainPosY - STARTY - 1) * BLOCK_WIDTH - BLOCK_WIDTH/2;


    dir = 0;
    hasMoved = false;
}

void PlayerCharacter::render() {
    if(isMoving){
        hasMoved = true;
        lastDir = dir;
        //Flips the texture when moving left
        if(dir == LEFT){
            playerMoving[dir]->render((int) screenPosX, (int) screenPosY, NULL, 0.0, NULL, SDL_FLIP_HORIZONTAL);
        } else {
            playerMoving[dir]->render((int) screenPosX, (int) screenPosY);
        }
    } else {
        //For walking animation
        if(hasMoved){
            hasMoved = false;
            if(lastDir == DOWN){
                if(playerMoving[DOWN] == &gStock_Front_Walking1){
                    playerMoving[DOWN] = &gStock_Front_Walking2;
                } else {
                    playerMoving[DOWN] = &gStock_Front_Walking1;
                }

                //The player has moved down in the map by 1 square
                terrainPosY++;
            } else if(lastDir == UP){
                if(playerMoving[UP] == &gStock_Back_Walking1){
                    playerMoving[UP] = &gStock_Back_Walking2;
                } else {
                    playerMoving[UP] = &gStock_Back_Walking1;
                }

                //The player has moved up in the map by 1 square
                terrainPosY--;
            } else if(lastDir == LEFT || lastDir == RIGHT){
                if(playerMoving[lastDir] == &gStock_Side_Right_Walking){
                    playerMoving[lastDir] = &gStock_Side_Right_Walking2;
                } else if(playerMoving[lastDir] == &gStock_Side_Right_Walking2){
                    playerMoving[lastDir] = &gStock_Side_Right_Walking3;
                } else {
                    playerMoving[lastDir] = &gStock_Side_Right_Walking;
                }

                //The player has moved left or right
                lastDir == LEFT ? terrainPosX-- : terrainPosX++;
            }

        }
        //Flips the texture when moving left
        if(dir == LEFT){
            playerStationary[dir]->render((int) screenPosX, (int) screenPosY, NULL, 0.0, NULL, SDL_FLIP_HORIZONTAL);
        } else {
            playerStationary[dir]->render((int) screenPosX, (int) screenPosY);
        }
    }

}

void PlayerCharacter::updateRender(bool isMoving, int dir) {
    this->isMoving = isMoving;
    this->dir = dir;

}

int PlayerCharacter::getTerrainPosX() {
    return terrainPosX;
}

int PlayerCharacter::getTerrainPosY() {
    return terrainPosY;
}

int *PlayerCharacter::getCantTraverse() {
    return cantTraverse;
}

int PlayerCharacter::getCantTraverseSize() {
    return cantTraverseSize;
}