#ifdef _WIN32
#	define WIN32_LEAN_AND_MEAN
#	include <windows.h>
#endif /* Windows */

#include <iostream>
#include <unordered_map>
#include <string>

enum class Keys;
enum class KeyActions;
typedef unsigned char KeyFlags;
typedef void (*KeyCallback)(KeyActions,Keys,KeyFlags);

void set_raw_mode();
void process_input();