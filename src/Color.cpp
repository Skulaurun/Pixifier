#include "Color.hpp"

Color::Color() : r(255), g(255), b(255) {}
Color::Color(const Type type) {
	r = ((type >> 16) & 0xff);
	g = ((type >> 8) & 0xff);
	b = ((type) & 0xff);
}
Color::Color(const int r, const int g, const int b) : r(r), g(g), b(b) {}
Color::operator int() {
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}
