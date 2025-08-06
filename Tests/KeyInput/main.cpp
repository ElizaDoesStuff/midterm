#include "../../Source/midterm.cpp"
#include <iostream>

bool shouldExit = false;

void onkey(KeyActions action, Keys key, KeyFlags flags) {
	if (action != KeyActions::PRESS) return;
	shouldExit = (action == KeyActions::PRESS) && ( (key == Keys::ESC) || (key == Keys::C && flags == KeyFlagBits::CTRL) );

	std::cout << "Ctrl key was " + std::string((flags & KeyFlagBits::CTRL) != 0 ? "down." : "up.") << std::endl;
	std::cout << "Alt key was " + std::string((flags & KeyFlagBits::ALT) != 0 ? "down." : "up.") << std::endl;
	std::cout << "Shift key was " + std::string((flags & KeyFlagBits::SHIFT) != 0 ? "down." : "up.") << std::endl;
	std::cout << "Caps Lock was " + std::string((flags & KeyFlagBits::CAPSLOCK) != 0 ? "on." : "off.") << std::endl;
	std::cout << "Num Lock was " + std::string((flags & KeyFlagBits::NUMLOCK) != 0 ? "on." : "off.") << std::endl;
	std::cout << "Insert Mode was " + std::string((flags & KeyFlagBits::INSERT) != 0 ? "on." : "off.") << std::endl;
	if ((flags & KeyFlagBits::SIDED) != 0) {
		std::cout << "Key was on " + std::string((flags & KeyFlagBits::SIDE) != 0 ? "left side." : "right side.") << std::endl;
	}
	std::cout << "\n";
};

int main() {
	set_raw_mode();
	set_key_callback(&onkey);

	while (!shouldExit) process_input();

	return 0;
}