#include "../../Source/midterm.cpp"
#include <iostream>

bool shouldExit = false;

void onkey(KeyActions action, Keys key, KeyFlags flags) {
	if (action == KeyActions::REPEAT) return;
	if ((key == Keys::ESC) && action == KeyActions::PRESS) shouldExit = true;

	std::cout << static_cast<unsigned int>(key) << "\n";
	std::cout << (action == KeyActions::PRESS ? "Key was pressed." : "Key was released.") << "\n";
};

int main() {
	set_raw_mode();
	set_key_callback(&onkey);

	while (!shouldExit) process_input();

	return 0;
}