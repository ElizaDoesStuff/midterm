#include "../../Source/midterm.cpp"
#include <iostream>

bool shouldExit = false;

void onkey(KeyActions action, Keys key, KeyFlags flags) {
	if (action == KeyActions::REPEAT) return;
	shouldExit = (action == KeyActions::PRESS) && ( (key == Keys::ESC) || (key == Keys::C && (flags & 0b11000000 > 0)) );

	std::cout << "Key " + std::to_string( static_cast<int>(key) ) + (action == KeyActions::PRESS ? " was pressed." : " was released.") << std::endl;
	std::cout << "Ctrl key was " + std::string((flags & 0b10000000) != 0 ? "down." : "up.") << std::endl;
	std::cout << "Alt key was " + std::string((flags & 0b01000000) != 0 ? "down." : "up.") << std::endl;
	std::cout << "Shift key was " + std::string((flags & 0b00100000) != 0 ? "down." : "up.") << std::endl;
	std::cout << "Caps Lock was " + std::string((flags & 0b00010000) != 0 ? "on." : "off.") << std::endl;
	std::cout << "\n";
};

int main() {
	set_raw_mode();
	set_key_callback(&onkey);

	while (!shouldExit) process_input();

	return 0;
}