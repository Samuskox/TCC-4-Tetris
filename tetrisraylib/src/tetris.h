#ifndef TETRIS_H
#define TETRIS_H

#include <vector>
#include <algorithm>
#include <random>
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
        int getSpaceBetweenCells();
        void lockPiece();

        Piece* piece = nullptr;
        std::vector<int> bagPieces;
        std::mt19937 generator;
        void shuffleBag();
        void refillBag();
        void cleanLine();
        void removeLine(int line);
    private:
        int width = 10;
        int height = 20;
        int cellSize = 32;
        float offsetX = GetScreenWidth()/2 - (width*cellSize)/2;
        int spaceBetweenCells = 1;
};

#endif