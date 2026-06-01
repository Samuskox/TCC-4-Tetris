def isValidMove(self, direction, blocks=None):

    if blocks is None:
        blocks = self.blocks

    for block in blocks:
        gridX = int(self.position.x + block.x + direction.x)
        gridY = int(self.position.y + block.y +  direction.y)
        
        if gridX < 0 or gridX >= width or gridY >= height:
            return False
        
        if grid.grid[gridY][gridX] != 0:
            return False
    
    return True