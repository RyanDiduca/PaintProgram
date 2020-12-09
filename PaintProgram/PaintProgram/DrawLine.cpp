#include "DrawLine.h"

DrawLine::~DrawLine()
{
}

void DrawLine::draw(EasyGraphics* canvas)
{
	canvas->setPenColour(getPenColour(), 5);
	canvas->selectBackColour(getBackColour());
	canvas->drawLine(getX(), getY(), getW(), getH());
}