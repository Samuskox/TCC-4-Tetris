public void render() {
    tetris.fallTimer += Gdx.graphics.getDeltaTime();
    if (tetris.fallTimer >= tetris.fallInterval) {

        tetris.fallTimer = 0;
        tetris.lockTimer = 0;
        tetris.piece.canFall();
        
    }

    if (tetris.piece.isValidMove(new Vector2(tetris.piece.position.x, tetris.piece.position.y - 1),
            tetris.piece.blocks)) {

        tetris.lockTimer = 0;

    } else {

        tetris.lockTimer += Gdx.graphics.getDeltaTime();
        if (tetris.lockTimer >= tetris.lockDelay) {
            tetris.lockPiece();
            tetris.spawnPiece();
            tetris.lockTimer = 0;

        }
    }
}
