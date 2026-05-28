func cleanLines():
	
	var y = GridHeight - 1
	var linesScores = 0

	while y >= 0: # de baixo pra cima

		var isFull = true

		for x in range(GridWidth):
			if grid[x][y] == 0:
				isFull = false
				break

		if isFull:
			
			removeLine(y)
			linesScores += 1
			
		else:
			y -= 1 #checa toda a linhas de baixo pra cima
			
	updateScore(linesScores)
	linesScores = 0