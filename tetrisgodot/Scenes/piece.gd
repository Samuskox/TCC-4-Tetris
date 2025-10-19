extends Node2D
class_name Piece

var color: Color
var blocks: Array[Vector2]
var gridPosition: Vector2 

var main_script: Node2D

const cellSize = 32

var checkFall = 0

func _init(iblock: Array[Vector2], igridPosition : Vector2, iColor: Color):
	blocks = iblock
	gridPosition = igridPosition
	color = iColor

func _ready() -> void:
	
	main_script = get_node("/root/Tetris")
	
	var timer := Timer.new()
	add_child(timer)
	timer.timeout.connect(fall)
	timer.autostart = true
	timer.wait_time = 1.0
	timer.start(1)

func _draw() -> void:
	for block in blocks:
		draw_rect(Rect2((block + gridPosition) * cellSize, Vector2(cellSize - 2, cellSize - 2)), color, true)
	
func move(direction: Vector2):
	var new_position = gridPosition + direction
	if isValidmove(new_position):
		gridPosition = new_position
		queue_redraw()


func fall():
	#var fall = gridPosition + Vector2(0,1)
	print("checkfall: ", checkFall)
	if not move(Vector2(0,1)):
		checkFall += 1
		if checkFall == 1:
			#lockPiece(self)
			
			checkFall = 0
		else:
			pass
	else:
		gridPosition.y += 1
		checkFall = 0
	
	#if isValidmove(fall):
		#gridPosition.y += 1;
	#queue_redraw()
	
func _process(delta: float) -> void:
	pass
	
#func isValidmove(target_position: Vector2) -> bool:
	#if not main_script:
		#return true # Se não tiver referência ao grid, assume que é válido
#
	#for block in blocks:
		#var absolute_pos = block + target_position
		##print("Bloco: ",block)
		##print("posição que vai: ", target_position)
		##print("Posição das duas: ",absolute_pos)
		#var x = int(absolute_pos.x)
		#var y = int(absolute_pos.y)
		## Checar Limites Horizontais e Verticais
		#if x < 0 or x >= main_script.GridWidth:
			##print("tavindo aq e é falso")
			#return false
		#if y < 0 or y >= main_script.GridHeight:
			#return false # Colisão com o chão
		#if main_script.grid[x][y] != 0:
			#return false
	#return true

func lockPiece(piece: Piece):
	for block in piece.blocks:
		var x = int(piece.gridPosition.x + block.x)
		var y = int(piece.gridPosition.y + block.y)
		if x >= 0 and x < main_script.GridWidth and y >= 0 and y < main_script.GridHeight:
			main_script.grid[x][y] = 1
			
func rotate_piece() -> Array[Vector2]:
	var rotated_blocks: Array[Vector2] = []
	#var angle = 90
	##var center := Vector2(0, 0)
	##for block in blocks:
		##center += block
	##center /= blocks.size()
	#print("Bloco rotacionado e depois arredondado")
	#for block in blocks: 
		#var rotatedBlock := block.rotated(angle)
		##var new_block = rotatedBlock
		#rotatedBlock.x = snappedf(rotatedBlock.x, 0.001)
		#rotatedBlock.y = snappedf(rotatedBlock.y, 0.001)
		#print(rotatedBlock)
		#var new_block := rotatedBlock.snapped(Vector2.ONE)  # substitui round()
		#print(new_block)
		#var rounded_block: Vector2 = Vector2((new_block.x), (new_block.y))
		#rotated_blocks.append(rounded_block)
		#print(rounded_block)
		#ESSE METODO NAO FUNFA POR QUE OS FLOATS FODEM TUDO
	
	for block in blocks:
		var new_block: Vector2
		new_block = Vector2(block.y, -block.x)   
		rotated_blocks.append(new_block)

	#print("BLOCO ROTACIONADO")
	#for block in rotated_blocks:
		#
		#print(block)
	if isValidmove(gridPosition, rotated_blocks):
		blocks = rotated_blocks
		queue_redraw()
	return rotated_blocks

func isValidmove(target_position: Vector2, target_blocks: Array[Vector2] = blocks) -> bool:
	if not main_script:
		return true

	# Agora iteramos sobre target_blocks, que pode ser a nova rotação.
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
