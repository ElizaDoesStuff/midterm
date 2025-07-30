#ifdef _WIN32
#	define WIN32_LEAN_AND_MEAN
#	include <windows.h>
#endif /* Windows */
#include <iostream>
#include <unordered_map>

enum keys;
enum actions;

std::unordered_map<keys,bool> key_states;

void set_raw_mode();
void process_input();

void (*keyCallback)(unsigned int,unsigned int);