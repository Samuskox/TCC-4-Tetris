extends Node2D

const GridWidth := 10
const GridHeight := 20
const cellSize := 32
var grid := []

var xPlayer := 3.0
var yPlayer := 3.0

const iP: Array[Vector2] = [
	Vector2(0,0), 
	Vector2(0,1),
	Vector2(0,2),
	Vector2(0,3)
]

var piece := Piece.new(iP,Vector2(xPlayer, yPlayer), Color.CYAN)

func _ready() -> void:
	piece.main_script = self
	grid.resize(GridWidth)
	for x in range(GridWidth):
		grid[x] = []
		grid[x].resize(GridHeight)
		for y in range(GridHeight):
			grid[x][y] = 0
			
	add_child(piece)
	

func _process(delta: float) -> void:

	
	if Input.is_action_just_pressed("direita"):
		piece.move(Vector2(1,0))
	if Input.is_action_just_pressed("esquerda"):
		piece.move(Vector2(-1,0))
	if(Input.is_action_just_pressed("baixo")):
		piece.move(Vector2(0,1))
		#print("semata kk")
	
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
	
