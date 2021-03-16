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
