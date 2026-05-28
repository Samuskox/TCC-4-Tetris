func spawnPiece():
	var num = (randi() % 7 + 1)

	var startPos = Vector2(GridWidth / 2 - 1, 1)
    
	piece = Piece.new(startPos, num)
	
	if isSpawnBlocked(piece.blocks, startPos):
		triggerGameOver()
		piece.queue_free
		return
	else:
		add_child(piece)
	return piece