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