#include "../Include/midterm.h"

enum class Keys { 
	BACKSPACE, SPACE, CLEAR, ENTER, TAB, 
	SHIFT, LSHIFT, RSHIFT, 
	CTRL, LCTRL, RCTRL, 
	ALT, LALT, RALT,
	EXIT, BREAK, ESC, 
	PGUP, PGDOWN, END, HOME, 
	LEFT, RIGHT, UP, DOWN, 
	SELECT, PRINT, 
	_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, 
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, 
	WINDOWS, APPS, POWER, 
	NUMPAD0, NUMPAD1, NUMPAD2, NUMPAD3, NUMPAD4, NUMPAD5, NUMPAD6, NUMPAD7, NUMPAD8, NUMPAD9, 
	MULTIPLY, ADD, SUBTRACT, DIVIDE, DECIMALPOINT, 
	NUMLOCK, SCROLLLOCK, CAPSLOCK, INSERT,
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

// Because enums are stupid and both of them use :: so nobody will know the difference :3
namespace KeyFlagBits {
	constexpr unsigned char CTRL = 0b10000000;
	constexpr unsigned char SHIFT = 0b01000000;
	constexpr unsigned char ALT = 0b00100000;
	constexpr unsigned char CAPSLOCK = 0b00010000;
	constexpr unsigned char NUMLOCK = 0b00001000;
	constexpr unsigned char INSERT = 0b00000100;
	constexpr unsigned char SIDE = 0b00000010;
	constexpr unsigned char SIDED = 0b00000001;
}

static KeyCallback keyCallback;

std::unordered_map<Keys,bool> key_states {
	{Keys::BACKSPACE, false}, {Keys::SPACE, false}, {Keys::CLEAR, false}, {Keys::ENTER, false}, {Keys::TAB, false},
        {Keys::SHIFT, false}, {Keys::LSHIFT, false}, {Keys::RSHIFT, false},
        {Keys::CTRL, false}, {Keys::LCTRL, false}, {Keys::RCTRL, false},
        {Keys::ALT, false}, {Keys::LALT, false}, {Keys::RALT, false},
        {Keys::EXIT, false}, {Keys::BREAK, false}, {Keys::ESC, false},
        {Keys::PGUP, false}, {Keys::PGDOWN, false}, {Keys::END, false}, {Keys::HOME, false},
        {Keys::LEFT, false}, {Keys::RIGHT, false}, {Keys::UP, false}, {Keys::DOWN, false},
        {Keys::SELECT, false}, {Keys::PRINT, false},
        {Keys::_0, false}, {Keys::_1, false}, {Keys::_2, false}, {Keys::_3, false}, {Keys::_4, false}, {Keys::_5, false}, {Keys::_6, false}, {Keys::_7, false}, {Keys::_8, false}, {Keys::_9, false},
        {Keys::A, false}, {Keys::B, false}, {Keys::C, false}, {Keys::D, false}, {Keys::E, false}, {Keys::F, false}, {Keys::G, false}, {Keys::H, false}, {Keys::I, false}, {Keys::J, false}, {Keys::K, false}, {Keys::L, false}, {Keys::M, false}, {Keys::N, false}, {Keys::O, false}, {Keys::P, false}, {Keys::Q, false}, {Keys::R, false}, {Keys::S, false}, {Keys::T, false}, {Keys::U, false}, {Keys::V, false}, {Keys::W, false}, {Keys::X, false}, {Keys::Y, false}, {Keys::Z, false},
        {Keys::WINDOWS, false}, {Keys::APPS, false}, {Keys::POWER, false},
        {Keys::NUMPAD0, false}, {Keys::NUMPAD1, false}, {Keys::NUMPAD2, false}, {Keys::NUMPAD3, false}, {Keys::NUMPAD4, false}, {Keys::NUMPAD5, false}, {Keys::NUMPAD6, false}, {Keys::NUMPAD7, false}, {Keys::NUMPAD8, false}, {Keys::NUMPAD9, false},
        {Keys::MULTIPLY, false}, {Keys::ADD, false}, {Keys::SUBTRACT, false}, {Keys::DIVIDE, false}, {Keys::DECIMALPOINT, false},
        {Keys::NUMLOCK, false}, {Keys::SCROLLLOCK, false}, {Keys::CAPSLOCK, false}, {Keys::INSERT, false},
        {Keys::F1, false}, {Keys::F2, false}, {Keys::F3, false}, {Keys::F4, false}, {Keys::F5, false}, {Keys::F6, false}, {Keys::F7, false}, {Keys::F8, false}, {Keys::F9, false}, {Keys::F10, false}, {Keys::F11, false}, {Keys::F12, false}, {Keys::F13, false}, {Keys::F14, false}, {Keys::F15, false}, {Keys::F16, false}, {Keys::F17, false}, {Keys::F18, false}, {Keys::F19, false}, {Keys::F20, false}, {Keys::F21, false}, {Keys::F22, false}, {Keys::F23, false}, {Keys::F24, false},
        {Keys::MUTE, false}, {Keys::VOLUMEUP, false}, {Keys::VOLUMEDOWN, false},
        {Keys::MEDIANEXT, false}, {Keys::MEDIAPREV, false}, {Keys::MEDIASTOP, false}, {Keys::MEDIAPLAYPAUSE, false},
        {Keys::SEMICOLON, false}, {Keys::EQUALS, false}, {Keys::COMMA, false}, {Keys::PERIOD, false}, {Keys::SLASH, false}, {Keys::BACKTICK, false}, {Keys::LBRACKET, false}, {Keys::RBRACKET, false}, {Keys::BACKSLASH, false}, {Keys::APOSTROPHE, false},
};

#ifdef _WIN32

static std::unordered_map<WORD, Keys> keyCodeMap = {
	{VK_BACK, Keys::BACKSPACE}, {VK_SPACE, Keys::SPACE}, {VK_CLEAR, Keys::CLEAR}, {VK_RETURN, Keys::ENTER}, {VK_TAB, Keys::TAB}, 
	{VK_SHIFT, Keys::SHIFT}, {VK_LSHIFT, Keys::LSHIFT}, {VK_RSHIFT, Keys::RSHIFT}, 
	{VK_CONTROL, Keys::CTRL}, {VK_LCONTROL, Keys::LCTRL}, {VK_RCONTROL, Keys::RCTRL}, 
	{VK_MENU, Keys::ALT}, {VK_LMENU, Keys::LALT}, {VK_RMENU, Keys::RALT}, 
	{VK_CANCEL, Keys::EXIT}, {VK_PAUSE, Keys::BREAK}, {VK_ESCAPE, Keys::ESC}, 
	{VK_PRIOR, Keys::PGUP}, {VK_NEXT, Keys::PGDOWN}, {VK_END, Keys::END}, {VK_HOME, Keys::HOME}, 
	{VK_LEFT, Keys::LEFT}, {VK_RIGHT, Keys::RIGHT}, {VK_UP, Keys::UP}, {VK_DOWN, Keys::DOWN}, 
	{VK_SELECT, Keys::SELECT}, {VK_PRINT, Keys::PRINT}, 
	{48, Keys::_0}, {49, Keys::_1}, {50, Keys::_2}, {51, Keys::_3}, {52, Keys::_4}, {53, Keys::_5}, {54, Keys::_6}, {55, Keys::_7}, {56, Keys::_8}, {57, Keys::_9}, 
	{65, Keys::A}, {66, Keys::B}, {67, Keys::C}, {68, Keys::D}, {69, Keys::E}, {70, Keys::F}, {71, Keys::G}, {72, Keys::H}, {73, Keys::I}, {74, Keys::J}, {75, Keys::K}, {76, Keys::L}, {77, Keys::M}, {78, Keys::N}, {79, Keys::O}, {80, Keys::P}, {81, Keys::Q}, {82, Keys::R}, {83, Keys::S}, {84, Keys::T}, {85, Keys::U}, {86, Keys::V}, {87, Keys::W}, {88, Keys::X}, {89, Keys::Y}, {90, Keys::Z}, 
	{VK_LWIN, Keys::WINDOWS}, {VK_RWIN, Keys::WINDOWS}, {VK_APPS, Keys::APPS}, {VK_SLEEP, Keys::POWER}, 
	{VK_NUMPAD0, Keys::NUMPAD0}, {VK_NUMPAD1, Keys::NUMPAD1}, {VK_NUMPAD2, Keys::NUMPAD2}, {VK_NUMPAD3, Keys::NUMPAD3}, {VK_NUMPAD4, Keys::NUMPAD4}, {VK_NUMPAD5, Keys::NUMPAD5}, {VK_NUMPAD6, Keys::NUMPAD6}, {VK_NUMPAD7, Keys::NUMPAD7}, {VK_NUMPAD8, Keys::NUMPAD8}, {VK_NUMPAD9, Keys::NUMPAD9}, 
	{VK_MULTIPLY, Keys::MULTIPLY}, {VK_ADD, Keys::ADD}, {VK_SUBTRACT, Keys::SUBTRACT}, {VK_DIVIDE, Keys::DIVIDE}, {VK_DECIMAL, Keys::DECIMALPOINT}, 
	{VK_NUMLOCK, Keys::NUMLOCK}, {VK_SCROLL, Keys::SCROLLLOCK}, {VK_CAPITAL, Keys::CAPSLOCK}, {VK_INSERT, Keys::INSERT}, 
	{VK_F1, Keys::F1}, {VK_F2, Keys::F2}, {VK_F3, Keys::F3}, {VK_F4, Keys::F4}, {VK_F5, Keys::F5}, {VK_F6, Keys::F6}, {VK_F7, Keys::F7}, {VK_F8, Keys::F8}, {VK_F9, Keys::F9}, {VK_F10, Keys::F10}, {VK_F11, Keys::F11}, {VK_F12, Keys::F12}, {VK_F13, Keys::F13}, {VK_F14, Keys::F14}, {VK_F15, Keys::F15}, {VK_F16, Keys::F16}, {VK_F17, Keys::F17}, {VK_F18, Keys::F18}, {VK_F19, Keys::F19}, {VK_F20, Keys::F20}, {VK_F21, Keys::F21}, {VK_F22, Keys::F22}, {VK_F23, Keys::F23}, {VK_F24, Keys::F24}, 
	{VK_VOLUME_MUTE, Keys::MUTE}, {VK_VOLUME_DOWN, Keys::VOLUMEUP}, {VK_VOLUME_UP, Keys::VOLUMEDOWN}, 
	{VK_MEDIA_NEXT_TRACK, Keys::MEDIANEXT}, {VK_MEDIA_PREV_TRACK, Keys::MEDIAPREV}, {VK_MEDIA_STOP, Keys::MEDIASTOP}, {VK_MEDIA_PLAY_PAUSE, Keys::MEDIAPLAYPAUSE}, 
	{VK_OEM_1, Keys::SEMICOLON}, {VK_OEM_PLUS, Keys::EQUALS}, {VK_OEM_COMMA, Keys::COMMA}, {VK_OEM_PERIOD, Keys::PERIOD}, {VK_OEM_2, Keys::SLASH}, {VK_OEM_3, Keys::BACKTICK}, {VK_OEM_4, Keys::LBRACKET}, {VK_OEM_6, Keys::RBRACKET}, {VK_OEM_5, Keys::BACKSLASH}, {VK_OEM_7, Keys::APOSTROPHE}, 
};

static void* stdinHandle = GetStdHandle(STD_INPUT_HANDLE);
static void* stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

void set_raw_mode() {
	if ( !SetConsoleMode(stdinHandle, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT) ) {
		std::cerr << "MIDTERM: Could not set raw mode properly." << std::endl;
	};
}

void set_key_callback(KeyCallback callback) {
	keyCallback = callback;
}

static void handle_key_event(KEY_EVENT_RECORD event) {
	if (keyCallback == nullptr) return;
	
	if (keyCodeMap.find(event.wVirtualKeyCode) == keyCodeMap.end()) return;
	Keys key = keyCodeMap[event.wVirtualKeyCode];

	KeyActions action;
	if (key_states[key] && event.bKeyDown) {
		action = KeyActions::REPEAT;
	} else if (event.bKeyDown) {
		action = KeyActions::PRESS;
	} else {
		action = KeyActions::RELEASE;
	}

	switch(key) {
		case Keys::INSERT: case Keys::CAPSLOCK: case Keys::NUMLOCK: case Keys::SCROLLLOCK: 
			if (event.bKeyDown) key_states[key] = !key_states[key]; 
			break;
		default:
			key_states[keyCodeMap[event.wVirtualKeyCode]] = event.bKeyDown;
	}
	key_states[Keys::LCTRL] = GetKeyState(VK_LCONTROL);
	key_states[Keys::RCTRL] = GetKeyState(VK_RCONTROL);
	key_states[Keys::LSHIFT] = GetKeyState(VK_LSHIFT);
	key_states[Keys::RSHIFT] = GetKeyState(VK_RSHIFT);
	key_states[Keys::LALT] = GetKeyState(VK_LMENU);
	key_states[Keys::RALT] = GetKeyState(VK_RMENU);
	
	KeyFlags flags = KeyFlagBits::SIDED;
	flags |= KeyFlagBits::CTRL * key_states[Keys::CTRL];
	flags |= KeyFlagBits::ALT * key_states[Keys::ALT];
	flags |= KeyFlagBits::SHIFT * key_states[Keys::SHIFT];
	flags |= KeyFlagBits::CAPSLOCK * key_states[Keys::CAPSLOCK];
	flags |= KeyFlagBits::NUMLOCK * key_states[Keys::NUMLOCK];
	flags |= KeyFlagBits::INSERT * key_states[Keys::INSERT];
	switch (key) {
		case Keys::SHIFT:
			if (GetKeyState(VK_LSHIFT))  { flags &= !KeyFlagBits::SIDE; }
			else if (GetKeyState(VK_RSHIFT))  { flags |= KeyFlagBits::SIDE; }
			break;
		case Keys::CTRL: 
			flags |= KeyFlagBits::SIDE * GetKeyState(VK_RCONTROL);
			break;
		case Keys::ALT: 
			flags |= KeyFlagBits::SIDE * GetKeyState(VK_RMENU); break;
		default: 
			flags &= ~KeyFlagBits::SIDED;
	}

	keyCallback(action, key, flags);
}

void process_input() {
	unsigned long eventCount;
	INPUT_RECORD eventBuffer[128];
	if (! ReadConsoleInput(stdinHandle, eventBuffer, 128, &eventCount) ) std::cerr << "MIDTERM: Could not read input buffer." << std::endl;

	for (int i = 0; i < eventCount; i++) {
		INPUT_RECORD event = eventBuffer[i];
		switch (event.EventType) {
			case KEY_EVENT: handle_key_event(event.Event.KeyEvent); break;
			case MOUSE_EVENT: break;
		}
	}
}

#endif /* Windows */