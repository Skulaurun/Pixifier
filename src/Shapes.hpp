#pragma once

#include "IDrawable.hpp"
#include "Vector2D.hpp"

#include <string>

class Square : public IDrawable {

public:
	Square();
	Square(const IVec2& position, const IVec2& size, const Color& color = Color::White);

	void draw(DeviceContext dc) override;

};

class Circle : public IDrawable {

public:
	Circle();
	Circle(const IVec2& position, const IVec2& size, const Color& color = Color::White);

	void draw(DeviceContext dc) override;

};

class Text : public IDrawable {

private:
	std::wstring content;

public:
	Text();
	Text(const wchar_t* content, const IVec2& position, const IVec2& size, const Color& color = Color::White);

	void setText(const wchar_t* content);
	std::wstring getText() const;

	void draw(DeviceContext dc) override;

};
