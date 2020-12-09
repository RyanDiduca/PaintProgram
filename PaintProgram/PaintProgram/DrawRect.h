#pragma once
#include "ObjectControl.h"
class DrawRect :
	public ObjectControl
{
public:
	DrawRect(int penColour, int backColour, int startx, int starty, int endx, int endy);
	~DrawRect();

	void draw(EasyGraphics* canvas);
};

inline DrawRect::DrawRect(int penColour, int backColour, int startx, int starty, int endx, int endy) : ObjectControl(penColour, backColour, startx, starty, endx, endy) {}