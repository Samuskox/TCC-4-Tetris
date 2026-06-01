
public void spawnPiece() {

    int num = getNextPieceNum();
    Vector2 spawnPosition = new Vector2(4, 19);
    Piece protPiece = new Piece(num, this, spawnPosition);
    if (isSpawnBlocked(protPiece, spawnPosition)) {
        gameOver = true;
    } else {
        piece = new Piece(num, this, spawnPosition);
    }
}
