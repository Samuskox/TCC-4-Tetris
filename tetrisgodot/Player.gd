extends CharacterBody2D

var speed := 50
#var timer := Timer.new()	
#@onready var nodeTimer := $Timer

func _physics_process(delta: float) -> void:
	#$".".global_position.y += speed*delta
	
	if Input.is_action_pressed("direita"):
		global_position.x += 32;
	if Input.is_action_pressed("esquerda"):
		global_position.x -= 32;
	if Input.is_action_pressed("baixo"):
		global_position.y += 32

func _ready() -> void:
	#add_child(timer)
	#timer.start(1)
	#nodeTimer.timeout.connect(fall)
	
	pass


	
func fall():
	position.y += 32
	


func _on_timer_timeout() -> void:
	fall()
	pass # Replace with function body.
