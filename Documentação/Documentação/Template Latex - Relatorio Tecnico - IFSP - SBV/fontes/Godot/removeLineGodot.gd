func removeLine(lineY: int):
	for y in range(lineY, 0, -1):
		for x in range(GridWidth):
			grid[x][y] = grid[x][y - 1]

	for x in range(GridWidth):
		grid[x][0] = 0