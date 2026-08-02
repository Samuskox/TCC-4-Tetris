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