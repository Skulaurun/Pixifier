#pragma once

#include "IDrawable.hpp"
#include "Vector2D.hpp"

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
