#include "DeviceContext.hpp"

DeviceContext::DeviceContext(HDC hDC) : hDC(hDC) {}
void DeviceContext::fillRectangle(const IVec2& position, const IVec2& size, const Color& fillColor) {

	RECT area = { position.x, position.y, size.x, size.y };
	HBRUSH hBrush = CreateSolidBrush(BGR(fillColor));

	FillRect(hDC, &area, hBrush);
	DeleteObject(hBrush);

}
void DeviceContext::fillEllipse(const IVec2& position, const IVec2& size, const Color& fillColor) {

	HBRUSH hNewBrush = CreateSolidBrush(BGR(fillColor)), hOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);
	HPEN hNewPen = CreatePen(PS_INSIDEFRAME, 1, BGR(fillColor)), hOldPen = (HPEN)SelectObject(hDC, hNewPen);
	Ellipse(hDC, position.x, position.y, size.x, size.y);
	SelectObject(hDC, hOldBrush);
	SelectObject(hDC, hOldPen);
	DeleteObject(hNewBrush);
	DeleteObject(hNewPen);

}
