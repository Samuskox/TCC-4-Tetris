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
    std::cout << "Tentando rotacionar" << std::endl;
    Vector2 newBlocks[4];
    for(int i = 0; i < 4; i++){
        newBlocks[i].x = blocks[i].y;
        newBlocks[i].y = -blocks[i].x;
    }
    if(isValidMove({0,0}, newBlocks)){
        for(int i = 0; i < 4; i++){
            blocks[i] = newBlocks[i];
        }
        std::cout << "Rotacionou SEM SE MOVER" << std::endl;
        return ;
    }
    if(isValidMove({1,0}, newBlocks)){
        for(int i = 0; i < 4; i++){
            blocks[i] = newBlocks[i];
        }
        position.x += 1;
        std::cout << "Rotacionou SE MOVENDO PRA DIREITA" << std::endl;
        return ;
    } 
    if(isValidMove({-1,0}, newBlocks)){
        for(int i = 0; i < 4; i++){
            blocks[i] = newBlocks[i];
        }
        std::cout << "Rotacionou SE MOVENDO PRA ESQUERDA" << std::endl;
        position.x -= 1;
        return;
    } 
    if(isValidMove({0,1}, newBlocks)){
        for(int i = 0; i < 4; i++){
            blocks[i] = newBlocks[i];
        }
        position.y += 1;
        std::cout << "Rotacionou SE MOVENDO PRA BAIXO" << std::endl;
        return;
    }
}

void Piece::move(Vector2 direction){
    Vector2 newPosition = {position.x + direction.x, position.y + direction.y};
    if(isValidMove(direction, blocks)){
        position = newPosition;
    }
}

bool Piece::isValidMove(Vector2 direction, Vector2 newBlocks[4]){
    for(int i = 0; i<4; i++){

        int newX = position.x + direction.x + newBlocks[i].x;
        int newY = position.y + direction.y + newBlocks[i].y;
        std::cout << "Checando posição: " << newX << ", " << newY << std::endl;

        if(newY < 0 || newX >= pointerToTetris->getWidth()){
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
    }
    return true;
}

void Piece::draw(){
    
    for(int i = 0; i < 4; i++){
        DrawRectangle(
            (position.x + blocks[i].x) * pointerToTetris->getCellSize() + pointerToTetris->getOffsetX(),
            (position.y + blocks[i].y) * pointerToTetris->getCellSize() + 7,
            pointerToTetris->getCellSize() - (pointerToTetris->getSpaceBetweenCells()),
            pointerToTetris->getCellSize() - (pointerToTetris->getSpaceBetweenCells()),
            color);
    }
}

