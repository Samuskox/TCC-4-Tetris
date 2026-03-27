#include "tetris.h"
#include <iostream>


Tetris::Tetris(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            grid[i][j] = 0;
        }
    }
    spawnPiece();
}

int Tetris::getWidth(){
    return width;
}

int Tetris::getHeight(){
    return height;
}

int Tetris::getCellSize(){
    return cellSize;
}

float Tetris::getOffsetX(){
    return offsetX;
}

int Tetris::getSpaceBetweenCells(){
    return spaceBetweenCells;
}

void Tetris::spawnPiece(){
    if (piece != nullptr) {
        delete piece;
    }

    Vector2 spawnPosition = {4,1};
    if(bagPieces.empty()){
        refillBag();
    }
    for(int i = 0; i < bagPieces.size(); i++){
        std::cout << "Bag contains: " << bagPieces[i] << std::endl;
    }

    
    int num = bagPieces.back();
    bagPieces.pop_back();
    piece = new Piece(this, num, spawnPosition);
}

void Tetris::draw(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Color color;

            switch(grid[i][j]){
                case 0:
                    color = GRAY;
                    break;
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
                case 7:
                    color = PINK;
                    break;
            }
                DrawRectangle((j*cellSize) + offsetX, (i*cellSize) + 7,
                 (cellSize - (spaceBetweenCells)),
                  cellSize - (spaceBetweenCells),
                  color);
        }
    }

    if(piece != nullptr){
            piece->draw();
    }
}

void Tetris::lockPiece(){
    for(int i = 0; i < 4; i++){
            int x = piece->position.x + piece->blocks[i].x;
            int y = piece->position.y + piece->blocks[i].y;
            grid[y][x] = piece->num;
    }

    for (int l = 0; l < 20; l++) {
    for (int c = 0; c < 10; c++) {
        std::cout << grid[l][c] << " ";
    }
        std::cout << std::endl;
    }

    cleanLine();
}

void Tetris::refillBag(){
    bagPieces.push_back(1);
    bagPieces.push_back(2);
    bagPieces.push_back(3);
    bagPieces.push_back(4);
    bagPieces.push_back(5);
    bagPieces.push_back(6);
    bagPieces.push_back(7);
    shuffleBag();
    
}

void Tetris::shuffleBag(){
    std::shuffle(bagPieces.begin(), bagPieces.end(), generator);
}

void Tetris::cleanLine(){
    for(int i = 0; i < height; i++){
        bool fullLine = true;
        for(int j = 0; j < width; j++){
            if(grid[i][j] == 0){
                fullLine = false;
                break;
            }
        }
        if(fullLine){
            removeLine(i);
        }
    }
}

void Tetris::removeLine(int line){
    for(int i = line; i > 0; i--){
        for(int j = 0; j < width; j++){
            grid[i][j] = grid[i-1][j];
        }
    }
    for(int j = 0; j < width; j++){
        grid[0][j] = 0;
    }
}
