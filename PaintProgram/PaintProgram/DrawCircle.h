#pragma once
#include "ObjectControl.h"
class DrawCircle : public ObjectControl
{
public:
	DrawCircle(int penColour, int backColour, int startx, int starty, int radius, bool fill);
	~DrawCircle();

	void draw(EasyGraphics* canvas);
	int getRadius();
private:
	int radius;
	bool fill;
};

inline DrawCircle::DrawCircle(int penColour, int backColour, int startx, int starty, int radius, bool fill) : ObjectControl(penColour, backColour, startx, starty), radius(radius), fill(fill) {}
inline int DrawCircle::getRadius() { return radius; }