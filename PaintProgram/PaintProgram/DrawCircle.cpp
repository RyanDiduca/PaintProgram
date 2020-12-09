#include "DrawCircle.h"

DrawCircle::~DrawCircle()
{
}

void DrawCircle::draw(EasyGraphics* canvas)
{
	canvas->setPenColour(getPenColour(), 5);
	canvas->selectBackColour(getBackColour());
	canvas->drawCircle(getX(), getY(), radius, fill);
}