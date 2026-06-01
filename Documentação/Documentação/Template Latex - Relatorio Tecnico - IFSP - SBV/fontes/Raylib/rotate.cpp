void Piece::rotate(){
    if(num == 4){
        return;
    }
    Vector2 newBlocks[4];
    for(int i = 0; i < 4; i++){
        newBlocks[i].x = -blocks[i].y;
        newBlocks[i].y = blocks[i].x;
    }
    if(isValidMove({0,0}, newBlocks)){
        for(int i = 0; i < 4; i++){
            blocks[i] = newBlocks[i];
        }
        return ;
    }
    if(isValidMove({1,0}, newBlocks)){
        for(int i = 0; i < 4; i++){
            blocks[i] = newBlocks[i];
        }
        position.x += 1;
        return ;
    } 
    if(isValidMove({-1,0}, newBlocks)){
        for(int i = 0; i < 4; i++){
            blocks[i] = newBlocks[i];
        }
        position.x -= 1;
        return;
    } 
    if(isValidMove({0,1}, newBlocks)){
        for(int i = 0; i < 4; i++){
            blocks[i] = newBlocks[i];
        }
        position.y += 1;
        return;
    }
}