#include "DrawRect.h"

DrawRect::~DrawRect()
{
}

void DrawRect::draw(EasyGraphics* canvas)
{
	canvas->setPenColour(getPenColour(), 5);
	canvas->selectBackColour(getBackColour());
	canvas->drawRectangle(getX(), getY(), getW(), getH(), true);
}