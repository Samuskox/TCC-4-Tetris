def move(self, direction):
    if self.isValidMove(direction):
        self.position.x += direction.x
        self.position.y += direction.y