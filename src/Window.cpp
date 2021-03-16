#include "Window.hpp"

#include "windowsx.h"

Window::Window(const wchar_t* title, const IVec2& position, const IVec2& size) {

	this->type.lpszClassName = L"MYWINDOW";
	this->type.lpfnWndProc = this->_windowProcedure;
	this->type.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	this->type.hCursor = LoadCursor(NULL, IDC_ARROW);
	RegisterClass(&this->type);

	unsigned int style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
	this->hWindow = CreateWindowEx(
		0,								// OPTIONAL WINDOW STYLES
		this->type.lpszClassName,		// WINDOW CLASS
		title,							// WINDOW TITLE
		style,							// STYLE
		position.x, position.y,			// POSTION
		size.x, size.y,					// SIZE
		NULL,							// PARENT
		NULL,							// MENU
		NULL,							// INSTANCE HANDLE
		NULL							// ADDITIONAL APPLICATION DATA
	);
	
	if (hWindow == NULL) {
		throw "Window failed to create!";
	}

	SetWindowLongPtr(hWindow, GWLP_USERDATA, (LONG_PTR)this);

	this->framerateLimit = 0;
	this->backColor = Color::Black;

	this->mainBuffer = {};
	this->backBuffer = {};
	
}
Window::~Window() {
	DestroyWindow(hWindow);
	DeleteDC(mainBuffer);
	DeleteDC(backBuffer);
}
LRESULT CALLBACK Window::_windowProcedure(HWND hWindow, UINT message, WPARAM wParam, LPARAM lParam) {

	Window* me = (Window*)GetWindowLongPtr(hWindow, GWLP_USERDATA);
	if (me) {
		return me->windowProcedure(message, wParam, lParam);
	}

	return DefWindowProc(hWindow, message, wParam, lParam);

}
LRESULT CALLBACK Window::windowProcedure(UINT message, WPARAM wParam, LPARAM lParam) {

	if (wParam == SC_KEYMENU && (lParam >> 16) <= 0) {
		return 0;
	}

	switch (message) {

	case WM_ERASEBKGND:
		return 1;

	case WM_PAINT:
		onPaint();
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_CLOSE:
		lastEvent.type = Event::Closed;
		return 0;

	case WM_SIZE:
		lastEvent.type = Event::Resized;
		onResize(lParam);
		return 0;

	case WM_LBUTTONDOWN:
		lastEvent.type = Event::ButtonPressed;
		onMouseInteract(VK_LBUTTON, lParam);
		return 0;
	case WM_RBUTTONDOWN:
		lastEvent.type = Event::ButtonPressed;
		onMouseInteract(VK_RBUTTON, lParam);
		return 0;
	case WM_MBUTTONDOWN:
		lastEvent.type = Event::ButtonPressed;
		onMouseInteract(VK_MBUTTON, lParam);
		return 0;
	case WM_LBUTTONUP:
		lastEvent.type = Event::ButtonReleased;
		onMouseInteract(VK_LBUTTON, lParam);
		return 0;
	case WM_RBUTTONUP:
		lastEvent.type = Event::ButtonReleased;
		onMouseInteract(VK_RBUTTON, lParam);
		return 0;
	case WM_MBUTTONUP:
		lastEvent.type = Event::ButtonReleased;
		onMouseInteract(VK_MBUTTON, lParam);
		return 0;

	case WM_KEYDOWN: case WM_SYSKEYDOWN:
		onKeyboardInteract(wParam, lParam);
		return 0;
	case WM_KEYUP: case WM_SYSKEYUP:
		onKeyboardInteract(wParam, lParam);
		return 0;

	default:
		return DefWindowProc(hWindow, message, wParam, lParam);

	}

}
void Window::onPaint() {
	
	PAINTSTRUCT ps;
	mainBuffer = BeginPaint(hWindow, &ps);

	RECT clientArea;
	GetClientRect(hWindow, &clientArea);

	BitBlt(
		mainBuffer,
		clientArea.left, clientArea.top,
		clientArea.right - clientArea.left, clientArea.bottom - clientArea.top,
		backBuffer,
		0, 0,
		SRCCOPY
	);

	EndPaint(hWindow, &ps);
	DeleteDC(backBuffer);

}
void Window::onResize(LPARAM size) {

	lastEvent.size.width = GET_X_LPARAM(size);
	lastEvent.size.height = GET_Y_LPARAM(size);

}
void Window::onMouseInteract(WPARAM code, LPARAM position) {

	lastEvent.mouse.x = GET_X_LPARAM(position);
	lastEvent.mouse.y = GET_Y_LPARAM(position);

	lastEvent.mouse.button = Mouse::convertCodeToButton(code);

}
void Window::onKeyboardInteract(WPARAM code, LPARAM info) {

	int previousState = (info >> 0x1E) & 1;
	int currentState = (info >> 0x1F) & 1;

	if (currentState == 0) {
		if (previousState == 0 || Keyboard::getAutoRepeat() == true) {
			lastEvent.type = Event::KeyPressed;
		}
	}
	else {
		lastEvent.type = Event::KeyReleased;
	}
	
	lastEvent.keyboard.key = Keyboard::convertCodeToKey(code);

}
bool Window::pollEvent(Event& e) {

	MSG message;
	if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE) != 0) {

		TranslateMessage(&message);
		DispatchMessage(&message);

		if (lastEvent) {
			e = lastEvent.pop();
			return true;
		}

	}

	return false;

}
void Window::draw(IDrawable& drawable) {
	drawable.draw(backBuffer);
}
bool Window::isVisible() const {
	return IsWindowVisible(hWindow);
}
bool Window::isOpen() const {
	return IsWindow(hWindow);
}
bool Window::hasFocus() const {
	return GetFocus() == hWindow;
}
void Window::show() {
	ShowWindow(hWindow, SW_SHOW);
}
void Window::hide() {
	ShowWindow(hWindow, SW_HIDE);
}
void Window::clear() {

	mainBuffer = GetDC(hWindow);
	backBuffer = CreateCompatibleDC(mainBuffer);

	RECT clientArea;
	GetClientRect(hWindow, &clientArea);

	HBITMAP hBitmap = CreateCompatibleBitmap(mainBuffer, clientArea.right - clientArea.left, clientArea.bottom - clientArea.top);
	SelectObject(backBuffer, hBitmap);
	DeleteObject(hBitmap);

	HBRUSH hBrush = CreateSolidBrush(BGR(backColor));
	FillRect(backBuffer, &clientArea, hBrush);
	DeleteObject(hBrush);

	ReleaseDC(hWindow, mainBuffer);

}
void Window::update() {

	if (framerateLimit > 0) {

		int frameTime = (int)clock.getElapsedTime();
		float maxFrameTime = 1000.0f / framerateLimit;
		
		if (maxFrameTime > frameTime) {
			sleep((int)maxFrameTime - frameTime);
		}

		clock.reset();

	}

	RedrawWindow(hWindow, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);

}
void Window::close() {
	this->~Window();
}
void Window::setTitle(const wchar_t* title) {
	SetWindowText(hWindow, title);
}
void Window::setPosition(const IVec2& position) {
	SetWindowPos(hWindow, NULL, position.x, position.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
}
void Window::setSize(const IVec2& size) {
	SetWindowPos(hWindow, NULL, 0, 0, size.x, size.y, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
}
void Window::setBackgroundColor(const Color& color) {
	this->backColor = color;
	RedrawWindow(hWindow, NULL, NULL, NULL);
}
void Window::setFramerateLimit(const unsigned int limit) {
	this->framerateLimit = limit;
}
std::wstring Window::getTitle() const {
	std::wstring title;
	int size = GetWindowTextLength(hWindow) + 1;
	title.resize(size);
	GetWindowText(hWindow, &title[0], size);
	return title;
}
IVec2 Window::getPosition() const {
	RECT r;
	GetWindowRect(hWindow, &r);
	return IVec2(r.left, r.top);
}
IVec2 Window::getSize() const {
	RECT r;
	GetWindowRect(hWindow, &r);
	return IVec2(r.right - r.left, r.bottom - r.top);
}
Color Window::getBackgroundColor() const {
	return backColor;
}
unsigned int Window::getFramerateLimit() const {
	return framerateLimit;
}
