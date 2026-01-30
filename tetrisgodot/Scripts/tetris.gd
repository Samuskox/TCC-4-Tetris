extends Node2D

const GridWidth := 10
const GridHeight := 20
const cellSize := 32
var grid := []

var piece

var xPlayer := 3.0
var yPlayer := 3.0
var goingdown = false

func _ready() -> void:
	
	grid.resize(GridWidth)
	for x in range(GridWidth):
		grid[x] = []
		grid[x].resize(GridHeight)
		for y in range(GridHeight):
			grid[x][y] = 0
			
	#grid[4][7] = 3
	#grid[6][7] = 3
	#grid[5][8] = 3
	for x in range(GridWidth - 1):
		grid[x][19] = (randi() % 7 + 1)
		
	for x in range(GridWidth - 1):
		grid[x][18] = (randi() % 7 + 1)
	
	for x in range(GridWidth - 1):
		grid[x][17] = (randi() % 7 + 1)
			
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
		goingdown = true
		while goingdown:
			#print("checando se pode ou nao pode: ")
			if piece.move(Vector2(0,1)):
				#print("pode")
				pass
			else:
				#print("nao pode")
				piece.lockPiece(piece)
				cleanLine()
				queue_redraw() # repinta tudo
				piece.queue_free() # remove a peça antiga
				spawnPiece()
				goingdown = false
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
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.CYAN)
			elif grid[x][y] == 2:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.WEB_PURPLE)
			elif grid[x][y] == 3:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.RED)
			elif grid[x][y] == 4:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.LIGHT_GREEN)
			elif grid[x][y] == 5:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.YELLOW)
			elif grid[x][y] == 6:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.ORANGE)
			elif grid[x][y] == 7:
				draw_rect(Rect2(Vector2(x,y) * cellSize, Vector2(cellSize - 1,cellSize - 1)),Color.DARK_BLUE)
				
func spawnPiece():
	var num = (randi() % 7 + 1)
	#print("numero da cor:", num)
	piece = Piece.new(Vector2(GridWidth / 2 - 2, 1), num)
	piece.main_script = self
	add_child(piece)
	return piece
	
func cleanLine():
	
	var y = GridHeight - 1
	
	while y >= 0: # de baixo pra cima
		var isFull = true
		for x in range(GridWidth):
			if grid[x][y] == 0:
				isFull = false
				break
		if isFull:
			removeLine(y)
		else:
			y -= 1 #checa toda a linhas de baixo pra cima

		

func removeLine(lineY: int):
	for y in range(lineY, 0, -1):
		for x in range(GridWidth):
			grid[x][y] = grid[x][y - 1]
	# limpa em cima
	for x in range(GridWidth):
		grid[x][0] = 0
	
	
	
	

	
