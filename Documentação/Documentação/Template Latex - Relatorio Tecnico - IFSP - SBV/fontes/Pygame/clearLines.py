def clearLines(self):
    linesCleared = 0
    for y in range(len(self.grid)):
        if 0 not in self.grid[y]:
            del self.grid[y]
            self.grid.insert(0, [0 for x in range(self.width)])
            linesCleared += 1
        
    if linesCleared > 0:
        self.updateScore(linesCleared)