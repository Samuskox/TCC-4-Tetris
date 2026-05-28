
func isValidmove(target_position: Vector2, target_blocks: Array[Vector2] = blocks) -> bool:
	if not main_script:
		return true

	for block in target_blocks: 
		var absolute_pos = block + target_position
		var x = int(absolute_pos.x)
		var y = int(absolute_pos.y)
		
		# Checar Limites Horizontais e Verticais
		if x < 0 or x >= main_script.GridWidth:
			return false
		if y < 0 or y >= main_script.GridHeight:
			return false
		
		# Checar se a célula já está ocupada
		if main_script.grid[x][y] != 0:
			return false
	return true