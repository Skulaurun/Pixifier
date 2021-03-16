#include "IDrawable.hpp"

IDrawable::IDrawable() : position(0), size(0) {}
IDrawable::IDrawable(const IVec2& position, const IVec2& size) : position(position), size(size) {}
void IDrawable::setSize(const IVec2& size) {
	this->size = size;
}
void IDrawable::setPosition(const IVec2& position) {
	this->position = position;
}
void IDrawable::setFillColor(const Color& color) {
	fillColor = color;
}
IVec2 IDrawable::getSize() const {
	return size;
}
IVec2 IDrawable::getPosition() const {
	return position;
}
Color IDrawable::getFillColor() const {
	return fillColor;
}
