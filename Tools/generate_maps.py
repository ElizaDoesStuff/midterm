with open("Keys.enum") as file:
	file = file.readlines()
	for line in file.tostring("").split(", "):
		line = line.split(", ")
	print(file.join("\n"))