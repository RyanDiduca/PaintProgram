#pragma once
#include "EasyGraphics.h"
#include "Button.h"
#include "DrawLine.h"
#include "DrawCircle.h"
#include "DrawRect.h"
#include "Information.h"
#include <iterator>
#include <algorithm>
#include <math.h>
#include <fstream>
class DrawingTool : public EasyGraphics
{
public:
	DrawingTool(HINSTANCE hInstance);
	~DrawingTool();
	virtual void onMouseMove(UINT nFlags, int x, int y);
	virtual void onLButtonDown(UINT nFlags, int x, int y);
	virtual void onLButtonUp(UINT nFlags, int x, int y);
	Information* instance;
private:
	std::vector<ObjectControl*> objects;
	DrawLine * curLine;
	DrawRect * curRect;
	DrawCircle * curCircle;
	int startX, startY, count, currentType, currentPenColour, currentBackColour, currentStartX, currentStartY, currentEndX, currentEndY, pen, back;
	bool found, selected;
	void checkIfMovable(ObjectControl* object);
	float distanceBetween(int x1, int x0, int y1, int y0);
	void onDraw();
	void onCreate();
};