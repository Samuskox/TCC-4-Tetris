extends Node2D
class_name Piece

var color: Color
var blocks: Array[Vector2]
var gridPosition: Vector2 

var main_script: Node2D

const cellSize = 32

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
		draw_rect(Rect2((block + gridPosition) * cellSize, Vector2(cellSize, cellSize)), Color.CYAN, true)
	
func move(direction: Vector2):
	var new_position = gridPosition + direction
	if is_valid_move(new_position):
		gridPosition = new_position
		queue_redraw()


func fall():
	
	gridPosition.y += 1
	queue_redraw()
	
func _process(delta: float) -> void:
	pass
	
func is_valid_move(target_position: Vector2) -> bool:
	if not main_script:
		return true # Se não tiver referência ao grid, assume que é válido

	for block in blocks:
		var absolute_pos = block + target_position
		var x = int(absolute_pos.x)
		var y = int(absolute_pos.y)
		# Checar Limites Horizontais e Verticais
		if x < 0 or x >= main_script.GridWidth:
			print("tavindo aq e é falso")
			return false
		if y < 0 or y >= main_script.GridHeight:
			return false # Colisão com o chão
		if main_script.grid[x][y] != 0:
			return false
	return true
