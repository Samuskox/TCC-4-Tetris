#include "tetris.h"



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
    piece = new Piece(this, 2, spawnPosition);
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
}
