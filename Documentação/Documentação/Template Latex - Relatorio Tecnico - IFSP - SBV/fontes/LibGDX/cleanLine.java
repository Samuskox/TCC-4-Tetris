public void cleanLine() {

    int linescore = 0;

    for (int i = 0; i <= gridHeight - 1; i++) {
        boolean lineFull = true;
        for (int j = 0; j < gridWidth; j++) {
            if (grid[j][i] == 0) {
                lineFull = false;
                break;
            }
        }
        if (lineFull) {
            removeline(i--);
            linescore++;
            lines++;
        }
    }

    updateScore(linescore);
}

public void removeline(int lineIndex) {
    for (int i = lineIndex; i < gridHeight - 1; i++) {
        for (int j = 0; j < gridWidth; j++) {
            grid[j][i] = grid[j][i + 1];
        }
    }
    for (int j = 0; j < gridWidth; j++) {
        grid[j][gridHeight - 1] = 0;
    }
}