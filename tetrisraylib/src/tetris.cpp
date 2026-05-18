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

int Tetris::getScore(){
    return score;
}

int Tetris::getLines(){
    return lines;
}

void Tetris::spawnPiece(){
    if (piece != nullptr) {
        delete piece;
        piece = nullptr;
    }

    Vector2 spawnPosition = {4,0};
    if(bagPieces.empty()){
        refillBag();
    }
    // for(int i = 0; i < bagPieces.size(); i++){
    //     std::cout << "Bag contains: " << bagPieces[i] << std::endl;
    // }

    
    int num = bagPieces.back();
    bagPieces.pop_back();

    Piece newPiece(this, num, spawnPosition);
    if(isSpawnBlocked(&newPiece, spawnPosition)){
        std::cout << "Game Over!" << std::endl;
        gameover = true;
        piece = nullptr;
    } else {
            piece = new Piece(this, num, spawnPosition);
    }
}

void Tetris::draw(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Color color;

            switch(grid[i][j]){
                case 0:
                    color = WHITE;
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
                case 8:
                    color = DARKGRAY;
                    break;
            }
                DrawRectangle((j*cellSize) + offsetX, (i*cellSize) + 7,
                 (cellSize - (spaceBetweenCells)),
                  cellSize - (spaceBetweenCells),
                  color);
        }
    }

    DrawText(TextFormat("Score: %d", getScore()), 10, 10, 20, WHITE);
    DrawText(TextFormat("Lines: %d", getLines()), 10, 40, 20, WHITE);

    drawBox(20, 450);

    if(piece != nullptr){
            piece->draw();
            piece->drawGhost();
    }
}

void Tetris::lockPiece(){
    if(piece == nullptr) return;

    for(int i = 0; i < 4; i++){
        int x = piece->position.x + piece->blocks[i].x;
        int y = piece->position.y + piece->blocks[i].y;
        if (x >= 0 && x < getWidth() && y >= 0 && y < getHeight()) {
            grid[y][x] = piece->num;
        }
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
    int linesCleared = 0;
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
            linesCleared++;
            lines++;
        }
    }
    addScore(linesCleared);
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

void Tetris::gravity(){
    if(gameover || piece == nullptr) return;

    fallTimer++;
    if(fallTimer >= fallDelay){
        fallTimer = 0;
        lockTimer = 0;
        piece->canFall();
    }
}

void Tetris::checkLock(){
    if(gameover || piece == nullptr) return;

    if(!piece->isValidMove({0,1}, piece->blocks)){
        lockTimer++;
        if(lockTimer >= lockDelay){
            lockTimer = 0;
            lockPiece();
            spawnPiece();
        }
    }
}

bool Tetris::isSpawnBlocked(Piece* newPiece, Vector2 spawnPosition){
    for(int i = 0; i < 4; i++){
        int x = spawnPosition.x + newPiece->blocks[i].x;
        int y = spawnPosition.y + newPiece->blocks[i].y;
        if(x < 0 || x >= getWidth()){
            std::cout << "Spawn blocked: piece is out of horizontal bounds." << std::endl;
                return true;
        }
        if(y >= 0 && y <= getHeight()){
             if(grid[y][x] > 0){
            std::cout << "Spawn blocked: cell (" << x << ", " << y << ") is already occupied." << std::endl;
            return true;
            }
        }
       
    }
    return false;
}

void Tetris::gameOver(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(grid[i][j] > 0){
                grid[i][j] = 8;
            }
        }
    }
}

void Tetris::addScore(int points){
    switch(points){
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        case 4:
            score += 800;
            break;
    }

    //std::cout << "Score: " << score << std::endl;
}

void Tetris::drawBox(int x, int y){
    DrawRectangle(x, y, 150, 150, GRAY);
    DrawRectangleLines(x, y, 150, 150, WHITE);

    Vector2 boxBlocks[4];

    if(piece == nullptr) return;
    if(gameover) return;
    if(piece->num == 1){
        for(int i = 0; i < 4; i++){
            boxBlocks[0] = {-1, 0};
            boxBlocks[1] = {0, 0};
            boxBlocks[2] = {0, -1};
            boxBlocks[3] = {1, -1};
            DrawRectangle(x + 60 + (boxBlocks[i].x * cellSize), y + 75 + (boxBlocks[i].y * cellSize), cellSize - spaceBetweenCells, cellSize - spaceBetweenCells, RED);
        }
    } else if(piece->num == 2){
        for(int i = 0; i < 4; i++){
            boxBlocks[0] = {-1, 0};
            boxBlocks[1] = {0, 0};
            boxBlocks[2] = {0, -1};
            boxBlocks[3] = {1, -1};
            DrawRectangle(x + 60 + (boxBlocks[i].x * cellSize), y + 75 + (boxBlocks[i].y * cellSize), cellSize - spaceBetweenCells, cellSize - spaceBetweenCells, GREEN);
        }
    } else if(piece->num == 3){
        for(int i = 0; i < 4; i++){
            boxBlocks[0] = {0, 1};
            boxBlocks[1] = {0, 0};
            boxBlocks[2] = {0, -1};
            boxBlocks[3] = {-1, -1};
            DrawRectangle(x + 75 + (boxBlocks[i].x * cellSize), y + 60 + (boxBlocks[i].y * cellSize), cellSize - spaceBetweenCells, cellSize - spaceBetweenCells, BLUE);
        }
    } else if(piece->num == 4){
        for(int i = 0; i < 4; i++){
            boxBlocks[0] = {0, 0};
            boxBlocks[1] = {1, 0};
            boxBlocks[2] = {0, -1};
            boxBlocks[3] = {1, -1};
            DrawRectangle(x + 45 + (boxBlocks[i].x * cellSize), y + 80 + (boxBlocks[i].y * cellSize), cellSize - spaceBetweenCells, cellSize - spaceBetweenCells, YELLOW);
        }
    } else if(piece->num == 5){
        for(int i = 0; i < 4; i++){
            boxBlocks[0] = {0, 1};
            boxBlocks[1] = {0, 0};
            boxBlocks[2] = {0, -1};
            boxBlocks[3] = {1, -1};
            DrawRectangle(x + 50 + (boxBlocks[i].x * cellSize), y + 60 + (boxBlocks[i].y * cellSize), cellSize - spaceBetweenCells, cellSize - spaceBetweenCells, ORANGE);
        }
    } else if(piece->num == 6){
        for(int i = 0; i < 4; i++){
            boxBlocks[0] = {0, 1};
            boxBlocks[1] = {0, 0};
            boxBlocks[2] = {-1, 0};
            boxBlocks[3] = {1, 0};
            DrawRectangle(x + 60 + (boxBlocks[i].x * cellSize), y + 45 + (boxBlocks[i].y * cellSize), cellSize - spaceBetweenCells, cellSize - spaceBetweenCells, PURPLE);
        }
    } else if(piece->num == 7){
        for(int i = 0; i < 4; i++){
            boxBlocks[0] = {-1, 0};
            boxBlocks[1] = {0, 0};
            boxBlocks[2] = {1, 0};
            boxBlocks[3] = {2, 0};
            DrawRectangle(x + 45 + (boxBlocks[i].x * cellSize), y + 60 + (boxBlocks[i].y * cellSize), cellSize - spaceBetweenCells, cellSize - spaceBetweenCells, PINK);
        }
    }
    
}