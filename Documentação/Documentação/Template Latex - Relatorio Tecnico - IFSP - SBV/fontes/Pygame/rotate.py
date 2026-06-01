def rotate(self):
    if self.num == 7:
        return
    newBlocks = []
    for block in self.blocks:
        newX = -block.y
        newY = block.x
        newBlocks.append(Vector2(newX, newY))
        
    if self.isValidMove(Vector2(0,0), newBlocks):
        self.blocks = newBlocks
        return newBlocks
    elif self.isValidMove(Vector2(1,0), newBlocks):
        self.position.x += 1
        self.blocks = newBlocks
        return newBlocks
    elif self.isValidMove(Vector2(-1,0), newBlocks):
        self.position.x -= 1
        self.blocks = newBlocks
        return newBlocks
    elif self.isValidMove(Vector2(0,1), newBlocks):
        self.position.y += 1 
        self.blocks = newBlocks
        return newBlocks
    return self.blocks