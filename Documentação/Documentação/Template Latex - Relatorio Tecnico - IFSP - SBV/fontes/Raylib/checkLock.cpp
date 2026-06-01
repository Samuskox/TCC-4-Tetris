void Tetris::checkLock(){
    if(gameover || piece == nullptr) return;

    if(!piece->isValidMove({0,1}, piece->blocks)){
        lockTimer++;
        if(lockTimer >= lockDelay){
            lockTimer = 0;
            lockPiece();
            spawnPiece();
        }
    }
}