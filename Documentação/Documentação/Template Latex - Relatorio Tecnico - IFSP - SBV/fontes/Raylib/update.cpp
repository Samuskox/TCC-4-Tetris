void Game::update(){
    if(!tetris.gameover){
        tetris.gravity();
        tetris.checkLock();
    } else{
        tetris.gameOver();
    }
}