extends Node2D
class_name Piece

var color: Color
var blocks: Array[Vector2]

const cellSize = 32

func _init(iblock: Array[Vector2], iPosition : Vector2, iColor: Color):
	blocks = iblock
	position = iPosition
	color = iColor

func _draw() -> void:
	for block in blocks:
		draw_rect(Rect2((block + position) * cellSize, Vector2(cellSize, cellSize)), Color.CYAN, true)
	
