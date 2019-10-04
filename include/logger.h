#ifndef INCLUDE_LOGGER_H_
#define INCLUDE_LOGGER_H_

#include <iostream>
#include <string>
#include <sstream>
#include <map>

#ifdef _WIN32
#include <Windows.h>
typedef enum {
	CONSOLE_COLOUR_FG_BLACK = 0,
	CONSOLE_COLOUR_FG_BLUE = FOREGROUND_BLUE,
	CONSOLE_COLOUR_FG_GREEN = FOREGROUND_GREEN,
	CONSOLE_COLOUR_FG_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
	CONSOLE_COLOUR_FG_RED = FOREGROUND_RED,
	CONSOLE_COLOUR_FG_MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
	CONSOLE_COLOUR_FG_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
	CONSOLE_COLOUR_FG_GRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	CONSOLE_COLOUR_FG_LIGHT_GRAY = FOREGROUND_INTENSITY,
	CONSOLE_COLOUR_FG_LIGHT_BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
	CONSOLE_COLOUR_FG_LIGHT_GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
	CONSOLE_COLOUR_FG_LIGHT_CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
	CONSOLE_COLOUR_FG_LIGHT_RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	CONSOLE_COLOUR_FG_LIGHT_MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
	CONSOLE_COLOUR_FG_LIGHT_YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	CONSOLE_COLOUR_FG_WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	CONSOLE_COLOUR_FG_DEFAULT = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	CONSOLE_COLOUR_BG_DEFAULT = 0
} ConsoleColour;

#ifdef _WIN32
	static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	static WORD wOldColorAttrs;
	static CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
#endif

#else
typedef enum {
	CONSOLE_COLOUR_FG_DEFAULT = 39,
	CONSOLE_COLOUR_FG_BLACK = 30,
	CONSOLE_COLOUR_FG_RED = 31,
	CONSOLE_COLOUR_FG_GREEN = 32,
	CONSOLE_COLOUR_FG_YELLOW = 33,
	CONSOLE_COLOUR_FG_BLUE = 34,
	CONSOLE_COLOUR_FG_MAGENTA = 35,
	CONSOLE_COLOUR_FG_CYAN = 36,
	CONSOLE_COLOUR_FG_LIGHT_GRAY = 37,
	CONSOLE_COLOUR_FG_DARK_GRAY = 90,
	CONSOLE_COLOUR_FG_LIGHT_RED = 91,
	CONSOLE_COLOUR_FG_LIGHT_GREEN = 92,
	CONSOLE_COLOUR_FG_LIGHT_YELLOW = 93,
	CONSOLE_COLOUR_FG_LIGHT_BLUE = 94,
	CONSOLE_COLOUR_FG_LIGHT_MAGENTA = 95,
	CONSOLE_COLOUR_FG_LIGHT_CYAN = 96,
	CONSOLE_COLOUR_FG_WHITE = 97,
	CONSOLE_COLOUR_BG_RED = 41,
	CONSOLE_COLOUR_BG_GREEN = 42,
	CONSOLE_COLOUR_BG_BLUE = 44,
	CONSOLE_COLOUR_BG_DEFAULT = 49
} ConsoleColour;
#endif

class Colour {
public:
	static void resetColour();

	template<typename T>
	static void consoleColour(T colour) {
	#ifdef _WIN32
		SetConsoleTextAttribute(h, colour);
	#else
		std::cout << "\033[" << colour << "m";
	#endif
	}
};

typedef enum {
	LOGGER_INFO = CONSOLE_COLOUR_FG_GREEN,
	LOGGER_WARN = CONSOLE_COLOUR_FG_YELLOW,
	LOGGER_ERROR = CONSOLE_COLOUR_FG_LIGHT_RED,
	LOGGER_PANIC = CONSOLE_COLOUR_FG_RED,
	LOGGER_DEBUG = CONSOLE_COLOUR_FG_BLUE
} LogType;

typedef enum {
	LOGGER_EXIT,
	LOGGER_ENDL
} LogAction;

class Logger {
public:
	Logger();

	Logger& operator<< (const LogType type) {
		std::cout << "[";
		Colour::consoleColour(type);
		std::cout << lookupTable[type];
		Colour::consoleColour(CONSOLE_COLOUR_FG_DEFAULT);
		std::cout << "] ";
		return *this;
	}

	Logger& operator<< (const LogAction action) {
		if (action == LOGGER_ENDL) {
			std::cout << outStream.str() << std::endl;
			outStream.str(std::string());;
			outStream.flush();
		}
		if (action == LOGGER_EXIT)
			exit(0);
		return *this;
	}

	template<typename T>
	Logger& operator<< (const T& data) {
		outStream << data;
		return *this;
	}

	std::stringstream outStream;
	std::map<LogType, std::string> lookupTable;
};

#endif

#ifdef LOGGER_DEFINITION
#undef LOGGER_DEFINITION

void Colour::resetColour() {
#ifdef _WIN32
	SetConsoleTextAttribute(h, CONSOLE_COLOUR_BG_DEFAULT);
	SetConsoleTextAttribute(h, CONSOLE_COLOUR_FG_DEFAULT);
#else
	std::cout
		<< "\033[" << CONSOLE_COLOUR_BG_DEFAULT << "m"
		<< "\033[" << CONSOLE_COLOUR_FG_DEFAULT << "m";
#endif
}

Logger::Logger() {

#ifdef _WIN32
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
#endif

	lookupTable[LOGGER_INFO] = "INFO";
	lookupTable[LOGGER_WARN] = "WARN";
	lookupTable[LOGGER_ERROR] = "ERROR";
	lookupTable[LOGGER_PANIC] = "PANIC";
	lookupTable[LOGGER_DEBUG] = "DEBUG";
}

#endif
