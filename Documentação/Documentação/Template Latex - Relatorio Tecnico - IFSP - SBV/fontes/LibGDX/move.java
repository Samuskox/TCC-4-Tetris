public void move(Vector2 direction) {
    Vector2 newPosition = new Vector2(position.x + direction.x, position.y + direction.y);
    if (!isValidMove(newPosition, blocks)) {
        return;
    }
    position.x += direction.x;
    position.y += direction.y;
    tetris.lockTimer = 0;
}
