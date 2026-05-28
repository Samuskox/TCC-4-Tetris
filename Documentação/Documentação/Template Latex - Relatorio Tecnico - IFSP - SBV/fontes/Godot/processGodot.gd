func _process(delta: float) -> void:
	if piece == null:
		return 
	if Input.is_action_just_pressed("direita"):
		piece.move(Vector2(1,0))
	if Input.is_action_just_pressed("esquerda"):
		piece.move(Vector2(-1,0))
	if(Input.is_action_just_pressed("baixo")):
		piece.move(Vector2(0,1))
	if(Input.is_action_just_pressed("ColocarPeca")):
		goingdown = true
		while goingdown:
			if piece.move(Vector2(0,1)):
				pass
			else:
				piece.lockPiece(piece)
				cleanLine()
				queue_redraw()
				piece.queue_free()
				spawnPiece()
				goingdown = false
	if(Input.is_action_just_pressed("cima")):
		piece.rotate_piece()