#pragma once

#include "Vector2D.hpp"
#include "Color.hpp"
#include "DeviceContext.hpp"

class IDrawable {

protected:
	IVec2 position, size;
	Color fillColor;

public:
	IDrawable();
	IDrawable(const IVec2& position, const IVec2& size);

	virtual void draw(DeviceContext dc) = 0;

	void setSize(const IVec2& size);
	void setPosition(const IVec2& position);
	void setFillColor(const Color& color);

	IVec2 getSize() const;
	IVec2 getPosition() const;
	Color getFillColor() const;

};
