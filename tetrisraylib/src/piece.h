#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "raylib.h"

class Tetris;

class Piece{
    public:
        Piece(Tetris* pointerToTetris, int num, Vector2 position);
        ~Piece();
        Tetris* pointerToTetris;
        void rotate();
        void move();
        void draw();
        Vector2 position;
        Vector2 blocks[4];
        Color color;

        int num;
    private:
        void setBlocks();
};

#endif