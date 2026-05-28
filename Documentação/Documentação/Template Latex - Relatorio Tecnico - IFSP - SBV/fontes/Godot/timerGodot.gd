func _ready() -> void:
	
	main_script = get_node("/root/Tetris")
	
	var timer := $"../Timer"

	timer.timeout.connect(fall)
	timer.autostart = true
	timer.wait_time = 0.5
	timer.start(1)