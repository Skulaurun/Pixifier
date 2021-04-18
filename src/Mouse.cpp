#include "Mouse.hpp"
#include "Window.hpp"

#include <windows.h>

Mouse::Button Mouse::convertCodeToButton(const unsigned int code) {

	Mouse::Button button;

	switch (code) {
	case VK_LBUTTON:	button = GetSystemMetrics(SM_SWAPBUTTON) ? Mouse::Right : Mouse::Left;	break;
	case VK_RBUTTON:	button = GetSystemMetrics(SM_SWAPBUTTON) ? Mouse::Left : Mouse::Right;	break;
	case VK_MBUTTON:	button = Mouse::Middle;													break;
	default:			button = Mouse::Null;													break;
	}
	
	return button;

}
unsigned int Mouse::convertButtonToCode(const Button button) {

	unsigned int code;

	switch (button) {
	case Mouse::Left:	code = GetSystemMetrics(SM_SWAPBUTTON) ? VK_RBUTTON : VK_LBUTTON;	break;
	case Mouse::Right:	code = GetSystemMetrics(SM_SWAPBUTTON) ? VK_LBUTTON : VK_RBUTTON;	break;
	case Mouse::Middle:	code = VK_MBUTTON;													break;
	default:			code = 0;
	}

	return code;

}
IVec2 Mouse::getCursorPosition(const Window* window) {
	POINT point;
	if (GetCursorPos(&point)) {
		if (window != nullptr) {
			ScreenToClient((HWND)*window, &point);
		}
		return IVec2(point.x, point.y);
	}
	return IVec2(-1);
}
bool Mouse::isButtonPressed(const Button button) {
	return (GetAsyncKeyState(Mouse::convertButtonToCode(button)) & 0x8000) != 0;
}
