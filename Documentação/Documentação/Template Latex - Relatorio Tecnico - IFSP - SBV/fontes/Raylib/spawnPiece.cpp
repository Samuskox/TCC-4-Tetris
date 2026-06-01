void Tetris::spawnPiece(){
    if (piece != nullptr) {
        delete piece;
        piece = nullptr;
    }

    Vector2 spawnPosition = {4,0};
    if(bagPieces.empty()){
        refillBag();
    }
    
    int num = bagPieces.back();
    bagPieces.pop_back();

    Piece newPiece(this, num, spawnPosition);
    if(isSpawnBlocked(&newPiece, spawnPosition)){
        gameover = true;
        piece = nullptr;
    } else {
            piece = new Piece(this, num, spawnPosition);
    }
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