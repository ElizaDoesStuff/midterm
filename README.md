# Midterm

A thin, soon-to-be-cross-platform abstraction layer written in C++ for console stuff such as keyboard and mouse events, ANSI, and more.

## Cross-Platform Support Progress:

Windows: 🟩

Linux: 🟥

MacOS: 🟥

## Documentation

### Initialization

Before you can do anything, you have to put the terminal into raw mode. This enables the handling of input events without waiting for the enter key.

With Midterm, you can simply call the `set_raw_mode()` function.
