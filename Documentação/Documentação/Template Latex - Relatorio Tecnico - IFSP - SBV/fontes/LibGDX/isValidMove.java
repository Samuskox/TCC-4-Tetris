public boolean isValidMove(Vector2 targetPosition, Vector2[] targetBlocks) {
    for (Vector2 block : targetBlocks) {
        int newX = (int) (targetPosition.x + block.x);
        int newY = (int) (targetPosition.y + block.y);

        if (newX < 0 || newX >= tetris.gridWidth || newY < 0) {
            return false;
        }
        if (newY >= tetris.gridHeight) {
            continue;
        }

        if (tetris.grid[newX][newY] > 0) {
            return false;
        }
    }
    return true;
}
