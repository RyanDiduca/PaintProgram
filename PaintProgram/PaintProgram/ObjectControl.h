#pragma once
#include "EasyGraphics.h"
class ObjectControl
{
public:
	ObjectControl(int penColour, int backColour, int x, int y, int w, int h);
	ObjectControl(int penColour, int backColour, int x, int y);
	virtual ~ObjectControl();
	virtual void draw(EasyGraphics* canvas) = 0;
	int getX();
	int getY();
	int getW();
	int getH();
	int getPenColour();
	int getBackColour();
	void setPenColour(int colour);
	void setBackColour(int colour);

private:
	int penColour, backColour, x, y, w, h;
};

inline ObjectControl::ObjectControl(int penColour, int backColour, int x, int y, int w, int h) : penColour(penColour), backColour(backColour), x(x), y(y), w(w), h(h) {}
inline ObjectControl::ObjectControl(int penColour, int backColour, int x, int y) : penColour(penColour), backColour(backColour), x(x), y(y) {}
inline ObjectControl::~ObjectControl(){}

inline int ObjectControl::getPenColour() { return penColour; }
inline int ObjectControl::getBackColour() { return backColour; }
inline int ObjectControl::getX() { return x; }
inline int ObjectControl::getY() { return y; }
inline int ObjectControl::getW() { return w; }
inline int ObjectControl::getH() { return h; }
inline void ObjectControl::setPenColour(int colour) { this->penColour = colour; }
inline void ObjectControl::setBackColour(int colour) { this->backColour = colour; }