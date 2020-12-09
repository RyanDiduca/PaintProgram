#pragma once
#include <vector>
#include "EasyGraphics.h"
using namespace std;

class Information
{
public:
	static Information* getInstance();
	static void DeleteInstance();
	int getMode();
	int getStartX();
	int getStartY();
	int getPenColour();
	int getBackColour();
	int getShapePos();
	void setMode(int mode);
	void setStartX(int startX);
	void setStartY(int startY);
	void setPenColour(int penColour);
	void setBackColour(int backColour);
	void setShapePos(int pos);

private:
	int mode, startX, startY, penColour, backColour, shapePos;
	static Information* instance;
	Information(int mode);
	~Information();
};

inline Information::Information(int mode) : mode(mode) {}
inline int Information::getMode() { return mode; }
inline int Information::getStartX() { return startX; }
inline int Information::getStartY() { return startY; }
inline int Information::getPenColour() { return penColour; }
inline int Information::getBackColour() { return backColour; }
inline int Information::getShapePos() { return shapePos; }