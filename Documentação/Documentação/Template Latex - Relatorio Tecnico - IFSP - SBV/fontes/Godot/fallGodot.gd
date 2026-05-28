func fall():

	if not move(Vector2(0,1)):
		checkFall += 1
		if checkFall >= 2:
			lockPiece(self)
			main_script.cleanLine()
			main_script.queue_redraw()
			main_script.spawnPiece()
			queue_free()
			checkFall = 0