#pragma once
#pragma warning(disable: 26812)

class Keyboard {

public:
	enum Key {
		Null,
		F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24,
		Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
		A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		Numpad0, Numpad1, Numpad2, Numpad3, Numpad4, Numpad5, Numpad6, Numpad7, Numpad8, Numpad9,
		Left, Up, Right, Down,
		Semicolon, Comma, Period, Quote, Slash, Backslash, Tilde, Equal, Hyphen, LBracket, RBracket,
		Escape, Space, Enter, Backspace, Tab, PageUp, PageDown, End, Home, Insert, Delete, Pause, Menu,
		LControl, RControl, LShift, RShift, LAlt, RAlt, LSystem, RSystem,
		Add, Subtract, Multiply, Divide
	};

private:
	static bool autoRepeat;

public:
	static Key convertCodeToKey(const unsigned int code);
	static unsigned int convertKeyToCode(const Key key);

	static bool isKeyPressed(const Key key);

	static void setAutoRepeat(const bool autoRepeat);

	static bool getAutoRepeat();

};
