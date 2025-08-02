def gen_map(name,values1,values2,type1,type2,prefix1,prefix2):
	if not type(values1) is list: print(type(values1)); print("Ërror: You cannot map one value to multiple values."); exit(1)
	print("std::unordered_map<" + type1 + "," + type2 + "> " + name + " {")
	out = ""
	for i in range(len(values1)):
		if values1[i] == "": out += "\n\t"; continue
		out += ("{" + prefix1 + values1[i] + ", " + prefix2 + (values2[i] if isinstance(values2,list) else values2) + "}, ")
	print(out)
	print("};")

keysfile = open("./Keys.enum")
keys = keysfile.readlines()
for i in range(len(keys)):
	keys[i] = keys[i].strip()
gen_map("key_states",keys,"false","Keys","bool","Keys::","")
keysfile.close()