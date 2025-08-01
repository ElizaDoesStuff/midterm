*Note: Midterm is still very much a work in progress and is in no way complete in its current state. All features are subject to change.*

# About Midterm
A thin, soon-to-be-cross-platform abstraction layer written in C++ for console stuff such as keyboard and window events, ANSI, and more.

## Cross-Platform Support Progress:

Windows: 🟩

Linux: 🟥

MacOS: 🟥

## Installation

1. Download the latest release off of Github
2. Extract the "Midterm" folder
3. Place it in the dependencies folder of your project
5. [Build using CMake](#building-with-cmake) or use some other method

### Building with CMake
Since CMake is weirdly confusing for beginners, I'll also explain how you can use it to compile Midterm and use it in your project.
In your CMakeLists.txt, add the following line, somewhere between your `project()` call and your `add_executable()` call:

`add_subdirectory(<your dependencies folder>/Midterm)`

Then, after your call to `add_executable()`, add this line:

`target_link_libraries(<your executable name> midterm)`

## How to use Midterm

### Initialization

Before you can do anything, you have to put the terminal into raw mode. 
This means that the terminal will not preprocess any input or output and instead simply does exactly what the program tells it.

With Midterm, you can simply call the `set_raw_mode()` function. This will cause the terminal to send input events immediately instead of waiting for the "enter" key to be pressed.

### Handling Events

In order to handle events, you need to process input from the terminal. 
This should be done in your program's **main loop**. 

You can do this by calling `process_input()` inside your main loop.
This will cause Midterm to read all the events from the input buffer, and call the appropriate callbacks.

### Binding Callbacks

Midterm currently only includes support for keyboard events.
These are controlled using the key callback function, which is defined by the user and acts as the main event handler for all key events.
To set the key callback to your own function, you must define your function with the proper signature (see below) and call `set_key_callback(&callback)` with a pointer to your function.

The necessary signature for key callback functions is `void callback(KeyActions,Keys,KeyFlags)`.
The first two parameters report what action was performed and on which key, respectively.
The third parameter is a collection of bits representing which of the control keys were held down at the time that the key event occurred. See `KeyFlags`.

# Documentation

### Table of Contents
- [Functions](#functions)
- [Callback Types](#callback-types)
- [Flagsets](#flagsets)
- [Enums](#enums)

## Functions

#### set_raw_mode
`void set_raw_mode();` - 
Sets the terminal to raw mode. 
This means that the program must process all input and output manually.
This function should be called before anything else in order to tell the terminal to send events to stdin immediately instead of waiting for the user to press the enter key.

#### process_inputs
`void process_inputs()` - 
Read the terminal input buffer and handle all events. Should be called inside the program's main loop.

#### set_key_callback
`void set_key_callback(KeyCallback callback)` - 
Set the key callback function to a function of your choice. See [KeyCallback](#keycallback). 

## Callback Types

#### KeyCallback
`void callback(KeyActions,Keys,KeyFlags);` - 
a key callback function handles key events and is defined by the user.
You can set a key callback function to be used with [set_key_callback](#set_key_callback).

## Flagsets

#### KeyFlags
`typedef unsigned char KeyFlags` - 
a key flags object is a collection of bits that communicates which of the control keys were pressed when a key event occurred.
They are stored in the following order, from most to least significant:
1. **Left Control** key state
2. **Right Control** key state
3. **Left Alt** key state
4. **Right Alt** key state
5. **Shift** key state
6. **Caps Lock** state
7. **Num Lock** state
8. **Scroll Lock** state

## Enums

#### KeyActions
The KeyActions enum contains contains enumerators for different type of keyboard input events.

**Contents**
`PRESS` - Key has been pressed.
`REPEAT` - Key is being held down and has started generating key repeat events (mostly used for typing)
`RELEASE` - Key has been released.

#### Keys
The Keys enum contains all of the different keys that can be pressed. When a key callback is called, it is provided with the name of the key that was pressed as one of these values.

**Contents**
`SPACE` - Spacebar

`CLEAR` - "Clear" key

`ENTER` - Enter/Return

`TAB` - Tab/Indent key

`SHIFT` - Shift key

`CTRL` - Ctrl key

`ALT` - Alt/Menu key

`EXIT` - Exit program key

`BREAK` - Break/pause program key

`ESC` - Escape key

`PGUP` - Page up key

`PGDOWN` - Page down key

`END` - End key

`HOME` - Home key

`LEFT` - Left arrow key

`RIGHT` - Right arrow key

`UP` - Up arrow key

`DOWN` - Down arrow key

`SELECT` - Select key

`PRINT` - Print key

`_0`-`_9` - 0 through 9 keys

`A`-`Z` - A through Z keys

`WINDOWS` - Windows key

`APPS` - Apps key

`POWER` - Power or On/Off key

`NUMPAD0`-`NUMPAD9` - Numpad keys 0-9

`MULTIPLY` - Numpad multiply key

`ADD` - Numpad plus key

`SUBTRACT` - Numpad minus key

`DIVIDE` - Numpad divide key

`DECIMALPOINT` - Numpad "." key

`NUMLOCK` - Num Lock key

`SCROLLLOCK` - Scroll lock key

`CAPSLOCK` - Caps lock key

`F1`-`F24` - F1-F24 keys

`MUTE` - Volume mute key

`VOLUMEUP` - Volume up key

`VOLUMEDOWN` - Volume down key

`MEDIANEXT` - Media next track key

`MEDIAPREV` - Media previous track key

`MEDIASTOP` - Media stop key

`MEDIAPLAYPAUSE` - Media play/pause key

`SEMICOLON` - Semicolon/colon key (";:")

`EQUALS` - Equals/plus key ("=+")

`COMMA` - Comma/left angle bracket key (",<")

`PERIOD` - Period/right angle bracket key (".>")

`SLASH` - Slash/question mark key ("/?")

`BACKTICK` - Backtick/tilde key ("\`~")

`LBRACKET` - Left bracket/brace key ("\[{")

`RBRACKET` - Right bracket/brace key ("\]}")

`BACKSLASH` - Backslash/pipe key ("\\|")

`APOSTROPHE` - Apostrophe/double quote key ("'\"")
