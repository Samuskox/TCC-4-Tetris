public Vector2[] rotate() {
    Vector2[] newBlocks = new Vector2[blocks.length];
    for (int i = 0; i < blocks.length; i++) {
        newBlocks[i] = new Vector2(blocks[i].y, -blocks[i].x);
    }
    if (isValidMove(position, newBlocks)) {
        tetris.lockTimer = 0;
        return newBlocks;
    }
    if (isValidMove(new Vector2(position.x + 1, position.y), newBlocks)) {
        position.x += 1;
        tetris.lockTimer = 0;
        return newBlocks;
    }
    if (isValidMove(new Vector2(position.x - 1, position.y), newBlocks)) {
        position.x -= 1;
        tetris.lockTimer = 0;
        return newBlocks;
    }
    if (isValidMove(new Vector2(position.x, position.y + 1), newBlocks)) {
        position.y += 1;
        tetris.lockTimer = 0;
        return newBlocks;
    }
    return blocks;
}