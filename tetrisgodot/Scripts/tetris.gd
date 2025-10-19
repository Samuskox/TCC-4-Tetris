extends Node2D

const GridWidth := 10
const GridHeight := 20
const cellSize := 32
var grid := []

var piece

var xPlayer := 3.0
var yPlayer := 3.0

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





func _ready() -> void:
	
	grid.resize(GridWidth)
	for x in range(GridWidth):
		grid[x] = []
		grid[x].resize(GridHeight)
		for y in range(GridHeight):
			grid[x][y] = 0
			
	grid[4][7] = 3
	grid[6][7] = 3
	grid[5][8] = 3
	spawnPiece()
	

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
		piece.lockPiece(piece)
		piece.queue_free() # remove a peça antiga
		spawnPiece()
		pass
	if(Input.is_action_just_pressed("cima")):
		piece.rotate_piece()
	
func _draw() -> void:
	for x in range(GridWidth + 1):
		draw_line(Vector2(x * cellSize,0), Vector2(x * cellSize, GridHeight * cellSize),Color.WHITE, 1.5)
	
	for y in range(GridHeight +1):
		draw_line(Vector2(0, y * cellSize), Vector2(GridWidth * cellSize, y * cellSize), Color.GRAY, 1.5)
		
	for x in range(GridWidth):
		for y in range(GridHeight):
			if grid[x][y] == 0:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 2,cellSize - 2)),Color(1, 0, 0, 0))
			elif grid[x][y] == 1:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.BLUE)
			elif grid[x][y] == 2:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.RED)
			elif grid[x][y] == 3:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.YELLOW)
			elif grid[x][y] == 4:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.DEEP_SKY_BLUE)
			elif grid[x][y] == 5:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.GREEN)
			elif grid[x][y] == 6:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.DEEP_PINK)
			elif grid[x][y] == 7:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.WEB_PURPLE)
				
func spawnPiece():
	var num = (randi() % 7)
	var shape : Array[Vector2] = allPieces.get(num)
	#const allPieces: Array = [iP, sP, zP, tP, oP, lP, jP]
	if(num == 0):
		piece = Piece.new(shape,Vector2(GridWidth / 2 - 2, 0), Color.CYAN)
	elif(num == 1):
		piece = Piece.new(shape,Vector2(GridWidth / 2 - 2, 0), Color.WEB_PURPLE)
	elif(num == 2):
		piece = Piece.new(shape,Vector2(GridWidth / 2 - 2, 0), Color.RED)
	elif(num == 3):
		piece = Piece.new(shape,Vector2(GridWidth / 2 - 2, 0), Color.WEB_PURPLE)
	elif(num == 4):
		piece = Piece.new(shape,Vector2(GridWidth / 2 - 2, 0), Color.YELLOW)
	elif(num == 5):
		piece = Piece.new(shape,Vector2(GridWidth / 2 - 2, 0), Color.ORANGE)
	elif(num == 6):
		piece = Piece.new(shape,Vector2(GridWidth / 2 - 2, 0), Color.DARK_BLUE)
	
	piece.main_script = self
	add_child(piece)
	# Cria uma instância da peça
	#var new_piece = piece.instantiate()
	
	# Passa os dados

	#new_piece.gridPosition = Vector2(GridWidth / 2 - 2, 0) # Centraliza no topo
	#new_piece.main_script = self
	
	# Adiciona à cena
	#add_child(new_piece)
	
	# Retorna a peça (caso precise guardar referência)
	return piece
	
	

	
