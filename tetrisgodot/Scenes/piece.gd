extends Node2D
class_name Piece

var color: Color
var blocks: Array[Vector2]
var gridPosition: Vector2 
var num

var main_script: Node2D

const cellSize = 32

var checkFall = 0

const iP: Array[Vector2] = [
	Vector2(-1, 0),
	Vector2(0, 0),
	Vector2(1, 0),
	Vector2(2, 0)
]

const sP: Array[Vector2] = [
	Vector2(0, 0),
	Vector2(1, 0),
	Vector2(0, 1),
	Vector2(-1, 1)
]

const zP: Array[Vector2] = [
	Vector2(0,-1), 
	Vector2(0,0),
	Vector2(-1,0),
	Vector2(-1,1)
]

const tP: Array[Vector2] = [
	Vector2(0,-1),
	Vector2(0,0),
	Vector2(1,0),
	Vector2(0,1)
]

const oP: Array[Vector2] = [
	Vector2(0,0),
	Vector2(0,1),
	Vector2(1,0),
	Vector2(1,1),
]

const lP: Array[Vector2] = [
	Vector2(-1, 0),
	Vector2(0, 0),
	Vector2(1, 0),
	Vector2(1, 1)
]

const jP: Array[Vector2] = [
	Vector2(-1, 0),
	Vector2(0, 0),
	Vector2(1, 0),
	Vector2(-1, 1)
]

const allPieces: Array = [iP, sP, zP, tP, oP, lP, jP]

func _init(igridPosition : Vector2, iNumber):
	
	gridPosition = igridPosition
	num = iNumber
	
	if(num == 1):
		blocks = iP
		color = Color.CYAN
	elif(num == 2):
		blocks = tP
		color = Color.WEB_PURPLE
	elif(num == 3):
		blocks = zP
		color = Color.RED
	elif(num == 4):
		blocks = sP
		color = Color.LIGHT_GREEN
	elif(num == 5):
		blocks = oP
		color = Color.YELLOW
	elif(num == 6):
		blocks = lP
		color = Color.ORANGE
	elif(num == 7):
		blocks = jP
		color = Color.DARK_BLUE
		


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
	print("checkfall: ", checkFall)
	if not move(Vector2(0,1)):
		if checkFall == 1:
			lockPiece(self)
			main_script.spawnPiece()
			checkFall = 0
		else:
			pass
	else:
		gridPosition.y += 1
		checkFall = 0
	
	#if isValidmove(fall):
		#gridPosition.y += 1;
	#queue_redraw()
	
func _process(_delta: float) -> void:
	pass

func lockPiece(piece: Piece):
	for block in piece.blocks:
		var x = int(piece.gridPosition.x + block.x)
		var y = int(piece.gridPosition.y + block.y)
		if x >= 0 and x < main_script.GridWidth and y >= 0 and y < main_script.GridHeight:
			main_script.grid[x][y] = piece.num
		#elif x >= 0 and x < main_script.GridWidth and y >= 0 and y < main_script.GridHeight and num == 1:
			#main_script.grid[x][y] = 7
		queue_redraw()

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
