extends BeehaveNode


func _before_run(actor: Node, blackboard: Blackboard) -> void:
	print(actor, blackboard)
