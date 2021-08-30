extends Control


func _ready():
	for i in range(TextServerManager.get_interface_count()):
		print(TextServerManager.get_interface(i).get_name())