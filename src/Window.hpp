#pragma once

#ifndef UNICODE
	#define UNICODE
#endif

#include "Vector2D.hpp"
#include "Utility.hpp"
#include "Event.hpp"
#include "Color.hpp"
#include "Clock.hpp"
#include "IDrawable.hpp"

#include <windows.h>

#include <string>

class Window {

private:
	WNDCLASS type;
	HWND hWindow;
	HDC mainBuffer;
	HDC backBuffer;

	Event lastEvent;
	Color backColor;
	Clock clock;

	unsigned int framerateLimit;

private:
	static LRESULT CALLBACK _windowProcedure(HWND hWindow, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK windowProcedure(UINT message, WPARAM wParam, LPARAM lParam);

	void onPaint();
	void onResize(LPARAM size);
	void onMouseInteract(WPARAM code, LPARAM position);
	void onKeyboardInteract(WPARAM code, LPARAM info);

public:
	Window(const wchar_t* title, const IVec2& position, const IVec2& size);
	~Window();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	bool pollEvent(Event& e);
	void draw(IDrawable& drawable);

	bool isVisible() const;
	bool isOpen() const;

	bool hasFocus() const;

	void show();
	void hide();
	void clear();
	void update();
	void close();

	void setTitle(const wchar_t* title);
	void setPosition(const IVec2& position);
	void setSize(const IVec2& size);
	void setBackgroundColor(const Color& color);
	void setFramerateLimit(const unsigned int limit);

	std::wstring getTitle() const;
	IVec2 getPosition() const;
	IVec2 getSize() const;
	Color getBackgroundColor() const;
	unsigned int getFramerateLimit() const;

};
