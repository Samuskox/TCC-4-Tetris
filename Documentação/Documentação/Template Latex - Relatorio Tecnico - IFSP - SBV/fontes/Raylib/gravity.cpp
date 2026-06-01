void Tetris::gravity(){
    if(gameover || piece == nullptr) return;

    fallTimer++;
    if(fallTimer >= fallDelay){
        fallTimer = 0;
        lockTimer = 0;
        piece->canFall();
    }
}