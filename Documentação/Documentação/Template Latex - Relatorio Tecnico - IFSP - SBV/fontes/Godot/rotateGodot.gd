func rotate_piece() -> Array[Vector2]:
	var rotated_blocks: Array[Vector2] = []
	
	for block in blocks:
		var new_block: Vector2
		new_block = Vector2(-block.y, block.x) #rotacionando bloco por bloco
		rotated_blocks.append(new_block) #Coloco em um conjunto novo de blocos
	if isValidmove(gridPosition, rotated_blocks):
		blocks = rotated_blocks
		queue_redraw()
	return rotated_blocks