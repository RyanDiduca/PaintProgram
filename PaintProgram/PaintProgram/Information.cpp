#include "Information.h"

Information* Information::instance = 0;

Information* Information::getInstance()
{
	if (!instance)
	{
		instance = new Information(0);
	}
	return instance;
}

void Information::DeleteInstance()
{
	delete instance;
	instance = NULL;
}

Information::~Information()
{
}

void Information::setMode(int mode)
{
	this->mode = mode;
}

void Information::setStartX(int startX)
{
	this->startX = startX;
}

void Information::setStartY(int startY)
{
	this->startY = startY;
}

void Information::setPenColour(int penColour)
{
	this->penColour = penColour;
}

void Information::setBackColour(int backColour)
{
	this->backColour = backColour;
}

void Information::setShapePos(int pos)
{
	this->shapePos = pos;
}