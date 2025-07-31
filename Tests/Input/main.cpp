#include "../../Source/midterm.cpp"
#include <iostream>

bool shouldExit = false;

void onkey(KeyActions action, Keys key) {
	if (action == KeyActions::REPEAT) return;

	std::cout << static_cast<unsigned int>(key) << "\n";
	std::cout << (action == KeyActions::PRESS ? "Key was pressed." : "Key was released.") << "\n";
};

int main() {
	set_raw_mode();
	keyCallback = &onkey;

	while (!shouldExit) process_input();

	return 0;
}