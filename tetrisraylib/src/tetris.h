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
        void drawBox(int x, int y);
        void cleanLines();
        void removeLine();
        void spawnPiece();
        
        int grid[20][10];
        int getWidth();
        int getHeight();
        int getCellSize();
        float getOffsetX();
        int getSpaceBetweenCells();
        int getScore();
        int getLines();
        void addScore(int points);
        void lockPiece();
        bool isSpawnBlocked(Piece* newPiece, Vector2 spawnPosition);
        void gameOver();
        

        Piece* piece = nullptr;
        std::vector<int> bagPieces;
        std::mt19937 generator;
        void shuffleBag();
        void refillBag();
        void cleanLine();
        void removeLine(int line);
        void gravity();
        void checkLock();
        int fallTimer = 0;
        int fallDelay = 30;
        int lockTimer = 0;
        int lockDelay = 30;
        bool gameover = false;
    private:
        int width = 10;
        int height = 20;
        int cellSize = 32;
        float offsetX = GetScreenWidth()/2 - (width*cellSize)/2;
        int spaceBetweenCells = 1;
        int score = 0;
        int lines = 0;
};

#endif