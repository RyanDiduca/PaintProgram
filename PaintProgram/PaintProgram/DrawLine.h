#pragma once
#include "ObjectControl.h"
class DrawLine : public ObjectControl
{
public:
	DrawLine(int penColour, int backColour, int startx, int starty, int endx, int endy);
	~DrawLine();

	void draw(EasyGraphics* canvas);
};

inline DrawLine::DrawLine(int penColour, int backColour, int startx, int starty, int endx, int endy) : ObjectControl(penColour, backColour, startx, starty, endx, endy){}