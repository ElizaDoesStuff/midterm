#include "../../Source/midterm.cpp"
#include <iostream>

bool shouldExit = false;

void onkey(actions action, keys key) {
	if (action == actions::REPEAT) return;

	std::cout << key << "\n";
	std::cout << (action == actions::PRESS ? "Key was pressed." : "Key was released.") << "\n";
};

int main() {
	set_raw_mode();
	keyCallback = &onkey;

	while (!shouldExit) process_input();

	return 0;
}