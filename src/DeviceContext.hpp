#pragma once

#include "Vector2D.hpp"
#include "Color.hpp"

#include <windows.h>
#include <string>

class DeviceContext {

private:
	HDC hDC;

public:
	DeviceContext(HDC hDC);

	void fillEllipse(const IVec2& position, const IVec2& size, const Color& fillColor);
	void fillRectangle(const IVec2& position, const IVec2& size, const Color& fillColor);

	void drawText(const std::wstring& content, const IVec2& position, const IVec2& size, const Color& fillColor);

};
