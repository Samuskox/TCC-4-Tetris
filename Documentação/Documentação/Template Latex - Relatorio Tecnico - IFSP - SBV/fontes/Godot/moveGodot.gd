func move(direction: Vector2):
	var new_position = gridPosition + direction
	if isValidmove(new_position):
		gridPosition = new_position
		queue_redraw()
		return true
	else:
		return false