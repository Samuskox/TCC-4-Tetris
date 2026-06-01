def spawnPiece(self):
        nextPiece = Piece(self.getNextPiece(), Vector2(5,1))
        if self.isSpawnBlocked(nextPiece):
            self.gameOver()
            return
        else:
            self.piece = nextPiece

def getNextPiece(self):
    if len(self.bag) == 0:
        self.refillBag()
    return self.bag.pop()

def refillBag(self):
    self.bag = [1,2,3,4,5,6,7]
    random.shuffle(self.bag)