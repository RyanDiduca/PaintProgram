#include "Button.h"

void Button::draw(EasyGraphics* canvas)
{
	canvas->setPenColour(getPenColour(), 5);
	canvas->selectBackColour(getBackColour());
	canvas->drawRectangle(getX(), getY(), getW(), getH(), fill);
	canvas->drawBitmap(filename, getX()+3, getY()+3, getW()-6, getH()-6, -1);
}
bool Button::hitbox(int checkx, int checky)
{
	return (checkx > getX() && checkx < (getX() + getW()) && checky > getY() && checky < (getY() + getH()));
}
Button::~Button()
{
}