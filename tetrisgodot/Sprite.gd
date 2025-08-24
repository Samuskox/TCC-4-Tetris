extends Sprite2D

const TILE_SIZE: Vector2 = Vector2(64,64)

#func _physics_process(delta: float) -> void:
		#global_position = get_global_mouse_position()
		#global_position = global_position.snapped(TILE_SIZE)  + TILE_SIZE/2.0
