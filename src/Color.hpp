#pragma once
#pragma warning(disable: 26812)

#define BGR(color) ((COLORREF)(((BYTE)(color.r)|((WORD)((BYTE)(color.g))<<8))|(((DWORD)(BYTE)(color.b))<<16)))

class Color {

public:
	enum Type {
		White = 0xffffff, Black = 0x000000,
		Red = 0xff0000, Green = 0x00ff00, Blue = 0x0000ff
	};

public:
	int r, g, b;

public:
	Color();
	Color(const Type type);
	Color(const int r, const int g, const int b);

	operator int();

};
