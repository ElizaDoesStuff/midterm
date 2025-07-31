#include "../Include/midterm.h"

enum class Keys {
	BACKSPACE, SPACE, CLEAR, ENTER, TAB, 
	SHIFT, 
	CTRL, 
	ALT, 
	CTRLC, BREAK, ESC, 
	PGUP, PGDOWN, END, HOME, 
	LEFT, RIGHT, UP, DOWN, 
	SELECT, PRINT, 
	_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, 
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, 
	WINDOWS, APPS, POWER, 
	NUMPAD0, NUMPAD1, NUMPAD2, NUMPAD3, NUMPAD4, NUMPAD5, NUMPAD6, NUMPAD7, NUMPAD8, NUMPAD9, 
	MULTIPLY, ADD, SUBTRACT, DIVIDE, DECIMALPOINT, 
	NUMLOCK, SCROLLLOCK, CAPSLOCK, 
	F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24, 
	MUTE, VOLUMEUP, VOLUMEDOWN, 
	MEDIANEXT, MEDIAPREV, MEDIASTOP, MEDIAPLAYPAUSE, 
	SEMICOLON, EQUALS, COMMA, PERIOD, SLASH, BACKTICK, LBRACKET, RBRACKET, BACKSLASH, APOSTROPHE, 
};

enum class KeyActions {
	PRESS,
	RELEASE,
	REPEAT
};

enum class MouseButtons {
	NA,
	LEFT,
	RIGHT,
	MIDDLE
};

enum class MouseActions {
	CLICK,
	RELEASE,
	SCROLL,
	MOVE
};

#ifdef _WIN32

std::unordered_map<WORD, Keys> keyCodeMap = {
	{VK_BACK, Keys::BACKSPACE}, {VK_SPACE, Keys::SPACE}, {VK_CLEAR, Keys::CLEAR}, {VK_RETURN, Keys::ENTER}, {VK_TAB, Keys::TAB}, 
	{VK_SHIFT, Keys::SHIFT}, {VK_LSHIFT, Keys::SHIFT}, {VK_RSHIFT, Keys::SHIFT}, 
	{VK_CONTROL, Keys::CTRL}, {VK_LCONTROL, Keys::CTRL}, {VK_RCONTROL, Keys::CTRL}, 
	{VK_MENU, Keys::ALT}, {VK_LMENU, Keys::ALT}, {VK_RMENU, Keys::ALT}, 
	{VK_CANCEL, Keys::CTRLC}, {VK_PAUSE, Keys::BREAK}, {VK_ESCAPE, Keys::ESC}, 
	{VK_PRIOR, Keys::PGUP}, {VK_NEXT, Keys::PGDOWN}, {VK_END, Keys::END}, {VK_HOME, Keys::HOME}, 
	{VK_LEFT, Keys::LEFT}, {VK_RIGHT, Keys::RIGHT}, {VK_UP, Keys::UP}, {VK_DOWN, Keys::DOWN}, 
	{VK_SELECT, Keys::SELECT}, {VK_PRINT, Keys::PRINT}, 
	{48, Keys::_0}, {49, Keys::_1}, {50, Keys::_2}, {51, Keys::_3}, {52, Keys::_4}, {53, Keys::_5}, {54, Keys::_6}, {55, Keys::_7}, {56, Keys::_8}, {57, Keys::_9}, 
	{65, Keys::A}, {66, Keys::B}, {67, Keys::C}, {68, Keys::D}, {69, Keys::E}, {70, Keys::F}, {71, Keys::G}, {72, Keys::H}, {73, Keys::I}, {74, Keys::J}, {75, Keys::K}, {76, Keys::L}, {77, Keys::M}, {78, Keys::N}, {79, Keys::O}, {80, Keys::P}, {81, Keys::Q}, {82, Keys::R}, {83, Keys::S}, {84, Keys::T}, {85, Keys::U}, {86, Keys::V}, {87, Keys::W}, {88, Keys::X}, {89, Keys::Y}, {90, Keys::Z}, 
	{VK_LWIN, Keys::WINDOWS}, {VK_RWIN, Keys::WINDOWS}, {VK_APPS, Keys::APPS}, {VK_SLEEP, Keys::POWER}, 
	{VK_NUMPAD0, Keys::NUMPAD0}, {VK_NUMPAD1, Keys::NUMPAD1}, {VK_NUMPAD2, Keys::NUMPAD2}, {VK_NUMPAD3, Keys::NUMPAD3}, {VK_NUMPAD4, Keys::NUMPAD4}, {VK_NUMPAD5, Keys::NUMPAD5}, {VK_NUMPAD6, Keys::NUMPAD6}, {VK_NUMPAD7, Keys::NUMPAD7}, {VK_NUMPAD8, Keys::NUMPAD8}, {VK_NUMPAD9, Keys::NUMPAD9}, 
	{VK_MULTIPLY, Keys::MULTIPLY}, {VK_ADD, Keys::ADD}, {VK_SUBTRACT, Keys::SUBTRACT}, {VK_DIVIDE, Keys::DIVIDE}, {VK_DECIMAL, Keys::DECIMALPOINT}, 
	{VK_NUMLOCK, Keys::NUMLOCK}, {VK_SCROLL, Keys::SCROLLLOCK}, {VK_CAPITAL, Keys::CAPSLOCK}, 
	{VK_F1, Keys::F1}, {VK_F2, Keys::F2}, {VK_F3, Keys::F3}, {VK_F4, Keys::F4}, {VK_F5, Keys::F5}, {VK_F6, Keys::F6}, {VK_F7, Keys::F7}, {VK_F8, Keys::F8}, {VK_F9, Keys::F9}, {VK_F10, Keys::F10}, {VK_F11, Keys::F11}, {VK_F12, Keys::F12}, {VK_F13, Keys::F13}, {VK_F14, Keys::F14}, {VK_F15, Keys::F15}, {VK_F16, Keys::F16}, {VK_F17, Keys::F17}, {VK_F18, Keys::F18}, {VK_F19, Keys::F19}, {VK_F20, Keys::F20}, {VK_F21, Keys::F21}, {VK_F22, Keys::F22}, {VK_F23, Keys::F23}, {VK_F24, Keys::F24}, 
	{VK_VOLUME_MUTE, Keys::MUTE}, {VK_VOLUME_DOWN, Keys::VOLUMEUP}, {VK_VOLUME_UP, Keys::VOLUMEDOWN}, 
	{VK_MEDIA_NEXT_TRACK, Keys::MEDIANEXT}, {VK_MEDIA_PREV_TRACK, Keys::MEDIAPREV}, {VK_MEDIA_STOP, Keys::MEDIASTOP}, {VK_MEDIA_PLAY_PAUSE, Keys::MEDIAPLAYPAUSE}, 
	{VK_OEM_1, Keys::SEMICOLON}, {VK_OEM_PLUS, Keys::EQUALS}, {VK_OEM_COMMA, Keys::COMMA}, {VK_OEM_PERIOD, Keys::PERIOD}, {VK_OEM_2, Keys::SLASH}, {VK_OEM_3, Keys::BACKTICK}, {VK_OEM_4, Keys::LBRACKET}, {VK_OEM_6, Keys::RBRACKET}, {VK_OEM_5, Keys::BACKSLASH}, {VK_OEM_7, Keys::APOSTROPHE}, 
};

void* stdinHandle = GetStdHandle(STD_INPUT_HANDLE);
void* stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

void set_raw_mode() {
	SetConsoleMode(stdinHandle, ENABLE_VIRTUAL_TERMINAL_PROCESSING | ENABLE_PROCESSED_INPUT); 
}

void handle_key_event(KEY_EVENT_RECORD event) {
	if (keyCallback == nullptr) return;
	KeyActions action;
	if (event.wRepeatCount > 1) {
		action = KeyActions::REPEAT;
	} else if (event.bKeyDown) {
		action = KeyActions::PRESS;
	} else {
		action = KeyActions::RELEASE;
	}
	keyCallback(action, keyCodeMap[event.wVirtualKeyCode]);
}

void handle_mouse_event(MOUSE_EVENT_RECORD event) {
	if (keyCallback == nullptr) return;
	MouseActions action;
}

void process_input() {
	unsigned long eventCount;
	INPUT_RECORD eventBuffer[128];
	ReadConsoleInput(stdinHandle, eventBuffer, 128, &eventCount);

	for (int i = 0; i < eventCount; i++) {
		INPUT_RECORD event = eventBuffer[i];
		switch (event.EventType) {
			case KEY_EVENT: handle_key_event(event.Event.KeyEvent); break;
			case MOUSE_EVENT: handle_mouse_event(event.Event.MouseEvent);
		}
	}
}

#endif /* Windows */