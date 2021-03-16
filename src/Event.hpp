#pragma once
#pragma warning(disable: 26812)

#include "Mouse.hpp"
#include "Keyboard.hpp"

class Event {

public:
	enum Type {
		Null,
		Closed, Resized,
		ButtonPressed, ButtonReleased,
		KeyPressed, KeyReleased
	};
	struct SizeData {
		unsigned int width, height;
	};
	struct MouseData {
		Mouse::Button button;
		unsigned int x, y;
	};
	struct KeyboardData {
		Keyboard::Key key;
	};

public:
	Type type;
	union {
		SizeData size;
		MouseData mouse;
		KeyboardData keyboard;
	};

public:
	Event();

	Event pop();
	operator bool();

};
