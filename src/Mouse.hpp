#pragma once
#pragma warning(disable: 26812)

#include "Vector2D.hpp"

class Window;

class Mouse {

public:
	enum Button {
		Null,
		Left, Right, Middle
	};

public:
	static Button convertCodeToButton(const unsigned int code);
	static unsigned int convertButtonToCode(const Button key);

	static bool isButtonPressed(const Button button);
	static IVec2 getCursorPosition(const Window* window = nullptr);

};
