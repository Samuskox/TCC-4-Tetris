extends Node2D

const GridWidth := 10
const GridHeight := 20
const cellSize := 32
var grid := []

var xPlayer := 3.0
var yPlayer := 3.0

#var peca := [[Vector2(0, 0), Vector2(1, 0), Vector2(0,1), Vector2(1,1)]] # perguntar isso pro yago, eu entendi mais ou menos
const peca: Array[Vector2] = [
	Vector2(0,0), 
	Vector2(0,1),
	Vector2(0,2),
	Vector2(0,3)
]

func _ready() -> void:
	grid.resize(GridWidth)
	for x in range(GridWidth):
		grid[x] = []
		grid[x].resize(GridHeight)
		for y in range(GridHeight):
			grid[x][y] = 0
			

func _process(delta: float) -> void:
	
	queue_redraw()
	
	
	
	if Input.is_action_just_pressed("direita"):
		xPlayer = clamp(xPlayer + 1, 0, 8) # num funfa
		print("direita bozonaro klmds" + str(xPlayer))
	if Input.is_action_just_pressed("esquerda"):
		xPlayer = clamp(xPlayer - 1, 0, 8)
		#print("esquerda lula ksksk")./
	if(Input.is_action_just_pressed("baixo")):
		yPlayer += 1
		#print("semata kk")
	
func _draw() -> void:
	for x in range(GridWidth + 1):
		draw_line(Vector2(x * cellSize,0), Vector2(x * cellSize, GridHeight * cellSize),Color.WHITE, 1.5)
	
	for y in range(GridHeight +1):
		draw_line(Vector2(0, y * cellSize), Vector2(GridWidth * cellSize, y * cellSize), Color.GRAY, 1.5)
		
	for x in range(GridWidth):
		for y in range(GridHeight):
			#var position = Vector2(x,y) * cellSize
			
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
	#moviment(xPlayer, yPlayer)
	drawPiece(peca,Vector2(xPlayer, yPlayer))

func moviment(x,y):
	var block_pos = Vector2(x, y) * cellSize
	draw_rect(Rect2(block_pos, Vector2(cellSize, cellSize)), Color.CORAL, true)
	
	


func _on_timer_timeout() -> void:
	yPlayer += 1
	
			

func drawPiece(peca, pos):
	for block in peca:
		draw_rect(Rect2((block + pos) * cellSize, Vector2(cellSize, cellSize)), Color.CYAN, true)
	
