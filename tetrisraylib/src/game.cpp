#include "game.h"
#include <random>
#include <cstdlib>  // Para rand() e srand()
#include <ctime>    // Para time()
#include "raylib.h"



Game::Game(){
    tetris = Tetris();
    score = 0;
    tetris.spawnPiece();
    //test();
}

Game::~Game(){

}

void Game::inputs(){
    
    if(tetris.piece == nullptr) return;
    if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)){
        tetris.piece->move({-1, 0});
        tetris.lockTimer = 0;
    }
    if(IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)){
        tetris.piece->move({1, 0});
        tetris.lockTimer = 0;
    }
    if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)){
        tetris.piece->move({0, 1});
        tetris.lockTimer = 0;
    }
    if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)){
        tetris.piece->rotate();
        tetris.lockTimer = 0;
    }
    if(IsKeyPressed(KEY_SPACE)){
        // while(tetris.piece->isValidMove({0,1}, tetris.piece->blocks)){
        //     tetris.piece->move({0, 1});
        // }
        tetris.piece->hardDrop();
        tetris.lockPiece();
        tetris.piece->~Piece();
        tetris.spawnPiece();
    }
}

void Game::update(){
    if(!tetris.gameover){
        tetris.gravity();
        tetris.checkLock();
    } else{
        tetris.gameOver();
    }
}

void Game::draw(){
    tetris.draw();
}

void Game::test(){
    tetris.grid[18][3] = 3;
    tetris.grid[15][5] = 5;
}