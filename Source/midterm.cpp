#include "../Include/midterm.h"

enum keys {
	BACKSPACE, SPACE, CLEAR, ENTER,
	SHIFT, CTRL, ALT,
	BREAK,
	CAPSLOCK,
	ESC,
	PGUP, PGDOWN, END, HOME,
	LEFT, RIGHT, UP, DOWN,
	SELECT,
	PRINT,
	_0, _1, _2, _3, _4, _5, _6, _7, _8, _9,
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	WINDOWS, APPS,
	POWER,
	NUMPAD0, NUMPAD1, NUMPAD2, NUMPAD3, NUMPAD4, NUMPAD5, NUMPAD6, NUMPAD7, NUMPAD8, NUMPAD9,
	MULTIPLY, ADD, SUBTRACT, DIVIDE, DECIMALPOINT,
	NUMLOCK, SCROLLLOCK,
	F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24,
	MUTE, VOLUMEUP, VOLUMEDOWN, MEDIANEXT, MEDIAPREV, MEDIASTOP, MEDIAPLAYPAUSE,
	SEMICOLON, EQUALS, COMMA, PERIOD, SLASH, BACKTICK, LBRACKET, RBRACKET, BACKSLASH, APOSTROPHE
};

enum actions {
	PRESS,
	RELEASE,
	REPEAT
};

#ifdef _WIN32

void* stdinHandle = GetStdHandle(STD_INPUT_HANDLE);
void* stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

void set_raw_mode() {
	SetConsoleMode(stdinHandle, ENABLE_VIRTUAL_TERMINAL_PROCESSING | ENABLE_PROCESSED_INPUT); 
}

void handle_key_event(KEY_EVENT_RECORD event) {
	if (keyCallback == nullptr) return;
	unsigned int action;
	if (event.wRepeatCount > 1) {
		action = actions::REPEAT;
	} else if (event.bKeyDown) {
		action = actions::PRESS;
	} else {
		action = actions::RELEASE;
	}
	keyCallback(action, event.wVirtualKeyCode);
}

void process_input() {
	unsigned long eventCount;
	INPUT_RECORD eventBuffer[128];
	ReadConsoleInput(stdinHandle, eventBuffer, 128, &eventCount);

	for (int i = 0; i < eventCount; i++) {
		INPUT_RECORD event = eventBuffer[i];
		switch (event.EventType) {
			case KEY_EVENT: handle_key_event(event.Event.KeyEvent); break;
			case MOUSE_EVENT: break; // TODO
		}
	}
}

#endif /* Windows */