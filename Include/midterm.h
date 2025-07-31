#ifdef _WIN32
#	define WIN32_LEAN_AND_MEAN
#	include <windows.h>
#endif /* Windows */
#include <iostream>
#include <unordered_map>

enum class Keys;
enum class KeyActions;

enum class MouseButtons;
enum class MouseActions;

std::unordered_map<Keys,bool> key_states;

void set_raw_mode();
void process_input();

void (*keyCallback)(KeyActions,Keys);