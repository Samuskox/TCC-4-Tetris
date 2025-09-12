extends Node2D
class_name Piece

var color: Color
var blocks: Array[Vector2]
var gridPosition: Vector2 

const cellSize = 32

func _init(iblock: Array[Vector2], igridPosition : Vector2, iColor: Color):
	blocks = iblock
	gridPosition = igridPosition
	color = iColor

func _draw() -> void:
	for block in blocks:
		draw_rect(Rect2((block + gridPosition) * cellSize, Vector2(cellSize, cellSize)), Color.CYAN, true)
	
func move(direction: Vector2):
	if gridPosition.x + direction.x >= 10:
		pass
	else :
		gridPosition += direction
	queue_redraw()
	
