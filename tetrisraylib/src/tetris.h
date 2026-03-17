#ifndef TETRIS_H
#define TETRIS_H

#include <vector>
#include "raylib.h"
#include "piece.h"

class Piece;

class Tetris{
    public:
        Tetris();
        void draw();
        void cleanLines();
        void removeLine();
        void spawnPiece();
        
        int grid[20][10];
        int getWidth();
        int getHeight();
        int getCellSize();
        float getOffsetX();
        Piece* piece = nullptr;
    private:
        int width = 20;
        int height = 10;
        int cellSize = 32;
        float offsetX = GetScreenWidth()/2 - (width*cellSize)/2;
        int spaceBetweenCells = 1;
};

#endif