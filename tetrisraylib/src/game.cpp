#include "game.h"
#include <random>
#include <cstdlib>  // Para rand() e srand()
#include <ctime>    // Para time()

Game::Game(){
    tetris = Tetris();
    gameOver = false;
    score = 0;
    tetris.spawnPiece();
    test();
}

Game::~Game(){

}

void Game::inputs(){
    
}

void Game::update(){
    if(!gameOver){
        
    }
}

void Game::draw(){
    tetris.draw();
}

void Game::test(){
    tetris.grid[9][18] = 3;
    tetris.grid[5][15] = 1;
}