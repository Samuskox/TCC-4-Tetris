#include "piece.h"
#include "tetris.h"
#include <iostream>

Piece::Piece(Tetris* _pointerToTetris, int _num, Vector2 _position){
    this->pointerToTetris = _pointerToTetris;
    this->num = _num;
    this->position = _position;

    switch(num){
        case 1:
            color = RED;
            blocks[0] = {-1, 0};
            blocks[1] = {0, 0};
            blocks[2] = {0, -1};
            blocks[3] = {1, -1};
            break;
        case 2:
            color = GREEN;
            blocks[0] = {-1, 0};
            blocks[1] = {0, 0};
            blocks[2] = {0, -1};
            blocks[3] = {1, -1};
            break;
        case 3:
            color = BLUE;
            blocks[0] = {0, 1};
            blocks[1] = {0, 0};
            blocks[2] = {0, -1};
            blocks[3] = {-1, -1};
            break;
        case 4:
            color = YELLOW;
            blocks[0] = {0, 0};
            blocks[1] = {1, 0};
            blocks[2] = {0, -1};
            blocks[3] = {1, -1};
            break;
        case 5:
            color = ORANGE;
            blocks[0] = {0, 1};
            blocks[1] = {0, 0};
            blocks[2] = {0, -1};
            blocks[3] = {1, -1};
            break;
        case 6:
            color = PURPLE;
            blocks[0] = {0, 1};
            blocks[1] = {0, 0};
            blocks[2] = {-1, 0};
            blocks[3] = {1, 0};
            break;
        case 7:
            color = PINK;
            blocks[0] = {-1, 0};
            blocks[1] = {0, 0};
            blocks[2] = {1, 0};
            blocks[3] = {2, 0};
            break;
        default:
            color = WHITE;
            break;
    }
}



Piece::~Piece(){

}

void Piece::rotate(){
    if(num == 4){
        return;
    }
    //std::cout << "Tentando rotacionar" << std::endl;
    Vector2 newBlocks[4];
    for(int i = 0; i < 4; i++){
        newBlocks[i].x = -blocks[i].y;
        newBlocks[i].y = blocks[i].x;
    }
    if(isValidMove({0,0}, newBlocks)){
        for(int i = 0; i < 4; i++){
            blocks[i] = newBlocks[i];
        }
        //std::cout << "Rotacionou SEM SE MOVER" << std::endl;
        return ;
    }
    if(isValidMove({1,0}, newBlocks)){
        for(int i = 0; i < 4; i++){
            blocks[i] = newBlocks[i];
        }
        position.x += 1;
        //std::cout << "Rotacionou SE MOVENDO PRA DIREITA" << std::endl;
        return ;
    } 
    if(isValidMove({-1,0}, newBlocks)){
        for(int i = 0; i < 4; i++){
            blocks[i] = newBlocks[i];
        }
        //std::cout << "Rotacionou SE MOVENDO PRA ESQUERDA" << std::endl;
        position.x -= 1;
        return;
    } 
    if(isValidMove({0,1}, newBlocks)){
        for(int i = 0; i < 4; i++){
            blocks[i] = newBlocks[i];
        }
        position.y += 1;
        //std::cout << "Rotacionou SE MOVENDO PRA BAIXO" << std::endl;
        return;
    }
}

void Piece::move(Vector2 direction){
    if(pointerToTetris == nullptr){
        return;
    }
    Vector2 newPosition = {position.x + direction.x, position.y + direction.y};
    if(isValidMove(direction, blocks)){
        position = newPosition;
    }
}

bool Piece::isValidMove(Vector2 direction, Vector2 newBlocks[4]){
    if(pointerToTetris == nullptr){
        return false;
    }
    for(int i = 0; i<4; i++){

        int newX = position.x + direction.x + newBlocks[i].x;
        int newY = position.y + direction.y + newBlocks[i].y;

        if(newX >= pointerToTetris->getWidth()){
            return false;
        }
        if(newY >= pointerToTetris->getHeight()){
            return false;
        }
        if(newX < 0){
            return false;
        }
        if(pointerToTetris->grid[newY][newX] > 0){
            return false;
        }
        printf("Checking move: (%d, %d)\n", newX, newY);
    }

    return true;
}

void Piece::draw(){
    
    for(int i = 0; i < 4; i++){
        if(position.y + blocks[i].y < 0) continue; // não desenha blocos que estão acima do campo de jogo
        DrawRectangle(
            (position.x + blocks[i].x) * pointerToTetris->getCellSize() + pointerToTetris->getOffsetX(),
            (position.y + blocks[i].y) * pointerToTetris->getCellSize() + 7,
            pointerToTetris->getCellSize() - (pointerToTetris->getSpaceBetweenCells()),
            pointerToTetris->getCellSize() - (pointerToTetris->getSpaceBetweenCells()),
            color);
    }
}

void Piece::drawGhost(){
if(pointerToTetris == nullptr || blocks == nullptr){
        return;
    }
    Vector2 ghostPosition = position;

    bool canGoDown = true;
    while(canGoDown) {
        // Tentamos ver se a posição abaixo da GHOST é válida
        for(int i = 0; i < 4; i++) {
            int nextX = ghostPosition.x + blocks[i].x;
            int nextY = ghostPosition.y + 1 + blocks[i].y; // +1 para testar em baixo

            // Se bater nas bordas, no chão ou em outra peça
            if (nextX < 0 || nextX >= pointerToTetris->getWidth() || 
                nextY >= pointerToTetris->getHeight() || 
                (nextY >= 0 && pointerToTetris->grid[nextY][nextX] > 0)) {
                canGoDown = false;
                break;
            }
        }

        if(canGoDown) {
            ghostPosition.y += 1;
        }
    }
    for(int i = 0; i < 4; i++){
        if(ghostPosition.y + blocks[i].y < 0) continue; //  não desenha blocos que estão acima do campo de jogo
        DrawRectangle(
            (ghostPosition.x + blocks[i].x) * pointerToTetris->getCellSize() + pointerToTetris->getOffsetX(),
            (ghostPosition.y + blocks[i].y) * pointerToTetris->getCellSize() + 7,
            pointerToTetris->getCellSize() - (pointerToTetris->getSpaceBetweenCells()),
            pointerToTetris->getCellSize() - (pointerToTetris->getSpaceBetweenCells()),
            Fade(color, 0.7f));
    }
}

bool Piece::canFall(){
    if(isValidMove({0,1}, blocks)){
        move({0,1});
        return true;
    }
    return false;
}

void Piece::hardDrop(){
    //a função mais minimalista de todas kkkkkkkkkkk
    while(canFall()){

    }
}
