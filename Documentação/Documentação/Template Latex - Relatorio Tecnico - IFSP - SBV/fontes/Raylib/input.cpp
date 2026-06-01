void Game::inputs(){
    
    if(tetris.piece == nullptr) return;
    if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)){
        tetris.piece->move({-1, 0});
        tetris.lockTimer = 0;
    }
    if(IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)){
        tetris.piece->move({1, 0});
        tetris.lockTimer = 0;
    }
    if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)){
        tetris.piece->move({0, 1});
        tetris.lockTimer = 0;
    }
    if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)){
        tetris.piece->rotate();
        tetris.lockTimer = 0;
    }
    if(IsKeyPressed(KEY_SPACE)){
        tetris.piece->hardDrop();
        tetris.lockPiece();
        tetris.piece->~Piece();
        tetris.spawnPiece();
    }
}