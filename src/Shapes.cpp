#include "Shapes.hpp"

Square::Square() {}
Square::Square(const IVec2& position, const IVec2& size, const Color& color) : IDrawable(position, size) {
	this->fillColor = color;
}
void Square::draw(DeviceContext dc) {
	dc.fillRectangle(position, position + size, fillColor);
}

Circle::Circle() {}
Circle::Circle(const IVec2& position, const IVec2& size, const Color& color) : IDrawable(position, size) {
	this->fillColor = color;
}
void Circle::draw(DeviceContext dc) {
	dc.fillEllipse(position, position + size, fillColor);
}

Text::Text() {}
Text::Text(const wchar_t* content, const IVec2& position, const IVec2& size, const Color& color) : IDrawable(position, size) {
	this->fillColor = color;
	this->content = content;
}
void Text::setText(const wchar_t* content) {
	this->content = content;
}
std::wstring Text::getText() const {
	return content;
}
void Text::draw(DeviceContext dc) {
	dc.drawText(content, position, position + size, fillColor);
}
