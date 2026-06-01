void Piece::move(Vector2 direction){
    if(pointerToTetris == nullptr){
        return;
    }
    Vector2 newPosition = {position.x + direction.x, position.y + direction.y};
    if(isValidMove(direction, blocks)){
        position = newPosition;
    }
}