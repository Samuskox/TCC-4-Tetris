#include "piece.h"
#include "tetris.h"

Piece::Piece(Tetris* _pointerToTetris, int _num, Vector2 _position){
    this->pointerToTetris = _pointerToTetris;
    this->num = _num;
    this->position = _position;

    switch(num){
        case 1:
            color = RED;
            break;
        case 2:
            color = GREEN;
            break;
        case 3:
            color = BLUE;
            break;
        case 4:
            color = YELLOW;
            break;
        case 5:
            color = ORANGE;
            break;
        case 6:
            color = PURPLE;
            break;
        default:
            color = WHITE;
            break;
    }

    setBlocks();
}

void Piece::setBlocks(){
    switch(num){
        case 1:
            blocks[0] = {0, 0};
            blocks[1] = {0, 1};
            blocks[2] = {0, 2};
            blocks[3] = {0, 3};
            break;
        case 2:
            blocks[0] = {0, 0};
            blocks[1] = {1, 0};
            blocks[2] = {2, 0};
            blocks[3] = {3, 0};
            break;
        case 3:
            blocks[0] = {0, 0};
            blocks[1] = {1, 0};
            blocks[2] = {1, 1};
            blocks[3] = {2, 1};
            break;
        case 4:
            blocks[0] = {0, 1};
            blocks[1] = {1, 1};
            blocks[2] = {1, 0};
            blocks[3] = {2, 0};
            break;
        case 5:
            blocks[0] = {0, 0};
            blocks[1] = {1, 0};
            blocks[2] = {1, 1};
            blocks[3] = {2, 0};
            break;
        case 6:
            blocks[0] = {0, 1};
            blocks[1] = {1, 1};
            blocks[2] = {1, 0};
            blocks[3] = {2, 1};
            break;
    }
}

Piece::~Piece(){

}

void Piece::rotate(){

}

void Piece::move(){

}

void Piece::draw(){
    
    for(int i = 0; i < 4; i++){
        DrawRectangle(
            (position.x + blocks[i].x) * pointerToTetris->getCellSize() + pointerToTetris->getOffsetX(),
            (position.y + blocks[i].y) * pointerToTetris->getCellSize() + 7,
            pointerToTetris->getCellSize(),
            pointerToTetris->getCellSize(), 
            color);
    }
}

