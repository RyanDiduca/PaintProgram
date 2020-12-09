#include "DrawingTool.h"
#include <vector>
DrawingTool::DrawingTool(HINSTANCE hInstance)
{
	instance = Information::getInstance();
	instance->setBackColour(clRed);
	instance->setPenColour(clRed);
	instance->setStartX(NULL);
	instance->setStartY(NULL);
	currentType = 0;
	back = 0;
	pen = 0;
	selected = false;
	setImmediateDrawMode(false);
	create(hInstance, 1000, 900, 40, true);
}

DrawingTool::~DrawingTool()
{
	std::for_each(objects.begin(), objects.end(), [](ObjectControl* x){delete x;});
	delete curLine;
	delete curRect;
	delete curCircle;
}

void DrawingTool::onDraw()
{
	clrscr(clBlack);
	if(curLine != NULL)
		curLine->draw(this);
	if (curRect != NULL)
		curRect->draw(this);
	if (curCircle != NULL)
		curCircle->draw(this);
	for (std::vector<ObjectControl*>::reverse_iterator rit = objects.rbegin(); rit != objects.rend(); ++rit)
		(*rit)->draw(this);
	EasyGraphics::onDraw();
}

void DrawingTool::onLButtonDown(UINT nFlags, int x, int y)
{
	if (instance->getMode() == 13 && selected == true)
	{
		for (std::vector<ObjectControl*>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			Button* button = dynamic_cast<Button*>(*it);
			if (button)
			{
				if (button->hitbox(x, y))
				{
					if (button->getMode() == 1)
					{
						instance->setPenColour(clRed);
						pen = 1;
						std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 1); }});
						Button * button = dynamic_cast<Button*>(*it);
						if (button)
							button->setPenColour(clGrey);
						objects.at(instance->getShapePos())->setPenColour(clRed);
						onDraw();
					}
					if (button->getMode() == 2)
					{
						instance->setPenColour(clGreen);
						pen = 2;
						std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 2); }});
						Button * button = dynamic_cast<Button*>(*it);
						if (button)
							button->setPenColour(clGrey);
						objects.at(instance->getShapePos())->setPenColour(clGreen);
						onDraw();
					}
					if (button->getMode() == 3)
					{
						instance->setPenColour(clBlue);
						pen = 3;
						std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 3); }});
						Button * button = dynamic_cast<Button*>(*it);
						if (button)
							button->setPenColour(clGrey);
						objects.at(instance->getShapePos())->setPenColour(clBlue);
						onDraw();
					}
					if (button->getMode() == 4)
					{
						instance->setBackColour(clRed);
						back = 4;
						std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 4); }});
						Button * button = dynamic_cast<Button*>(*it);
						if (button)
							button->setPenColour(clGrey);
						objects.at(instance->getShapePos())->setBackColour(clRed);
						onDraw();
					}
					if (button->getMode() == 5)
					{
						instance->setBackColour(clGreen);
						back = 5;
						std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 5); }});
						Button * button = dynamic_cast<Button*>(*it);
						if (button)
							button->setPenColour(clGrey);
						objects.at(instance->getShapePos())->setBackColour(clGreen);
						onDraw();
					}
					if (button->getMode() == 6)
					{
						instance->setBackColour(clBlue);
						back = 6;
						std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 6); }});
						Button * button = dynamic_cast<Button*>(*it);
						if (button)
							button->setPenColour(clGrey);
						objects.at(instance->getShapePos())->setBackColour(clBlue);
						onDraw();
					}
				}
			}
		}
		std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 13); }});
		Button * button = dynamic_cast<Button*>(*it);
		if (button)
			button->setPenColour(clGrey);
		onDraw();
	}
	bool check = false;
	for (std::vector<ObjectControl*>::iterator it = objects.begin(); it != objects.end(); it++)
	{
		Button* button = dynamic_cast<Button*>(*it);
		if (button)
		{
			if (button->hitbox(x, y))
			{
				if (button->getMode() == 1)
				{
					instance->setPenColour(clRed);
					pen = 1;
					std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 1); }});
					Button * button = dynamic_cast<Button*>(*it);
					if(button)
						button->setPenColour(clGrey);
				}
				if (button->getMode() == 2)
				{
					instance->setPenColour(clGreen);
					pen = 2;
					std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 2); }});
					Button * button = dynamic_cast<Button*>(*it);
					if (button)
						button->setPenColour(clGrey);
				}
				if (button->getMode() == 3)
				{
					instance->setPenColour(clBlue);
					pen = 3;
					std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 3); }});
					Button * button = dynamic_cast<Button*>(*it);
					if (button)
						button->setPenColour(clGrey);
				}
				if (button->getMode() == 4)
				{
					instance->setBackColour(clRed);
					back = 4;
					std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 4); }});
					Button * button = dynamic_cast<Button*>(*it);
					if (button)
						button->setPenColour(clGrey);
				}
				if (button->getMode() == 5)
				{
					instance->setBackColour(clGreen);
					back = 5;
					std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 5); }});
					Button * button = dynamic_cast<Button*>(*it);
					if (button)
						button->setPenColour(clGrey);
				}
				if (button->getMode() == 6)
				{
					instance->setBackColour(clBlue);
					back = 6;
					std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 6); }});
					Button * button = dynamic_cast<Button*>(*it);
					if (button)
						button->setPenColour(clGrey);
				}
				if (button->getMode() > 6)
					selected = false;
				if (button->getMode() > 6 && button->getMode() < 14)
				{
					for (std::vector<ObjectControl*>::iterator zit = objects.begin() + 6; zit != objects.begin() + 13; zit++)
					{
						Button* shapes = dynamic_cast<Button*>(*zit);
						if (shapes)
							shapes->setPenColour(clDarkRed);
					}
					instance->setMode(button->getMode());
					switch (button->getMode())
					{
					case 7:
					{
						std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 7); }});
						Button * button = dynamic_cast<Button*>(*it);
						if (button)
							button->setPenColour(clGrey);
						break;
					}
					case 9:
					{
						std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 9); }});
						Button * button = dynamic_cast<Button*>(*it);
						if (button)
							button->setPenColour(clGrey);
						break;
					}
					case 10:
					{
						std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 10); }});
						Button * button = dynamic_cast<Button*>(*it);
						if (button)
							button->setPenColour(clGrey);
						break;
					}
					case 11:
					{
						std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 11); }});
						Button * button = dynamic_cast<Button*>(*it);
						if (button)
							button->setPenColour(clGrey);
						break;
					}
					case 12:
					{
						std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 12); }});
						Button * button = dynamic_cast<Button*>(*it);
						if (button)
							button->setPenColour(clGrey);
						break;
					}
					case 13:
					{
						std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 13); }});
						Button * button = dynamic_cast<Button*>(*it);
						if (button)
							button->setPenColour(clGrey);
						break;
					}
					}
					onDraw();
				}
				if (button->getMode() == 14)
				{
					std::ifstream file ("Save.txt");
					if (file.is_open())
					{
						char c;
						std::string str[10];
						std::string temp;
						int count;
						
						for (std::vector<ObjectControl*>::iterator it = objects.begin() + 14; it != objects.end(); it++)
							delete * it;
						objects.erase(objects.begin()+14, objects.end());

						c = file.get();
						while (c != '¬')
						{
							count = 0;
							temp = "";
							if(c == '#')
								c = file.get();
							while (c != '#')
							{
								if(c == ',')
									c = file.get();
								while (c != ',' && c != '#')
								{
									temp.push_back(c);
									c = file.get();
								}
								if(count < 10)
									str[count] = temp;
								temp = "";
								count++;
								if (c == '#')
									break;
							}
							if (str[0] == "line")
							{
								objects.push_back(new DrawLine(std::stoi(str[1]), std::stoi(str[2]), std::stoi(str[3]), std::stoi(str[4]), std::stoi(str[5]), std::stoi(str[6])));
							}
							if (str[0] == "circle")
							{
								objects.push_back(new DrawCircle(std::stoi(str[1]), std::stoi(str[2]), std::stoi(str[3]), std::stoi(str[4]), std::stoi(str[5]), true));
							}
							if (str[0] == "rectangle")
							{
								objects.push_back(new DrawRect(std::stoi(str[1]), std::stoi(str[2]), std::stoi(str[3]), std::stoi(str[4]), std::stoi(str[5]), std::stoi(str[6])));
							}
							if (c == '#')
								c = file.get();
						}
						onDraw();
					}
					file.close();
					it = objects.end()-1;
				}
				if (button->getMode() == 15)
				{
					std::ofstream file ("Save.txt");
					if (file.is_open())
					{
						for (std::vector<ObjectControl*>::iterator sit = objects.begin(); sit != objects.end(); sit++)
						{
							DrawLine* line = dynamic_cast<DrawLine*>(*sit);
							if (line)
							{
								file << "line," << line->getPenColour() << "," << line->getBackColour() << "," << line->getX() << "," << line->getY() << "," << line->getW() << "," << line->getH() << ",#";
							}
							DrawCircle* circ = dynamic_cast<DrawCircle*>(*sit);
							if (circ)
							{
								file << "circle," << circ->getPenColour() << "," << circ->getBackColour() << "," << circ->getX() << "," << circ->getY() << "," << circ->getRadius() << "," << "true,#";
							}
							DrawRect* rect = dynamic_cast<DrawRect*>(*sit);
							if (rect)
							{
								file << "rectangle," << rect->getPenColour() << "," << rect->getBackColour() << "," << rect->getX() << "," << rect->getY() << "," << rect->getW() << "," << rect->getH() << ",#";
							}
						}
						file << "¬";
					}
					file.close();
				}
				check = true;
			}
		}
	}
	onDraw();
	for (std::vector<ObjectControl*>::iterator it = objects.begin(); it != objects.end(); it++)
	{
		Button* button = dynamic_cast<Button*>(*it);
		if (button && button->getMode() > 0 && button->getMode() < 7)
		{
			switch (instance->getPenColour())
			{
			case clRed:
			{
				if (button->getMode() == 1)
					button->setPenColour(clGrey);
				if (button->getMode() == 2 || button->getMode() == 3)
					button->setPenColour(clDarkRed);
				break;
			}
			case clGreen:
			{
				if (button->getMode() == 2)
					button->setPenColour(clGrey);
				if (button->getMode() == 1 || button->getMode() == 3)
					button->setPenColour(clDarkRed);
				break;
			}
			case clBlue:
			{
				if (button->getMode() == 3)
					button->setPenColour(clGrey);
				if (button->getMode() == 1 || button->getMode() == 2)
					button->setPenColour(clDarkRed);
				break;
			}
			}
			switch (instance->getBackColour())
			{
			case clRed:
			{
				if (button->getMode() == 4)
					button->setPenColour(clGrey);
				if (button->getMode() == 5 || button->getMode() == 6)
					button->setPenColour(clDarkRed);
				break;
			}
			case clGreen:
			{
				if (button->getMode() == 5)
					button->setPenColour(clGrey);
				if (button->getMode() == 4 || button->getMode() == 6)
					button->setPenColour(clDarkRed);
				break;
			}
			case clBlue:
			{
				if (button->getMode() == 6)
					button->setPenColour(clGrey);
				if (button->getMode() == 4 || button->getMode() == 5)
					button->setPenColour(clDarkRed);
				break;
			}
			}
			onDraw();
		}
	}
	if (check == false)
	{
		instance->setStartX(x);
		instance->setStartY(y);
		if (instance->getMode() == 11)
		{
			found = false;
			count = 0;
			for (std::vector<ObjectControl*>::iterator it = objects.begin(); it != objects.end(); it++)
				if(found == false)
					checkIfMovable(*it);
			if (found == true)
			{
				delete objects.at(count-1);
				objects.erase(objects.begin() + (count-1));
			}
		}
		if (instance->getMode() == 12)
		{
			found = false;
			count = 0;
			for (std::vector<ObjectControl*>::iterator it = objects.begin(); it != objects.end(); it++)
				if (found == false)
					checkIfMovable(*it);
			if (found == true)
			{
				delete objects.at(count - 1);
				objects.erase(objects.begin() + (count - 1));
			}
		}
		if (instance->getMode() == 13)
		{
			found = false;
			count = 0;
			for (std::vector<ObjectControl*>::iterator it = objects.begin(); it != objects.end(); it++)
				if (found == false)
					checkIfMovable(*it);
			if (found == true)
			{
				for (std::vector<ObjectControl*>::iterator it = objects.begin(); it != objects.end(); it++)
				{
					Button* button = dynamic_cast<Button*>(*it);
					if (button)
					{
						button->setPenColour(clDarkRed);
						selected = true;
					}
				}
				if (currentPenColour == clRed)
				{
					std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 1); }});
					Button * button = dynamic_cast<Button*>(*it);
					if (button)
					{
						button->setPenColour(clGrey);
						selected = true;
					}
				}
				if (currentPenColour == clGreen)
				{
					std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 2); }});
					Button * button = dynamic_cast<Button*>(*it);
					if (button)
					{
						button->setPenColour(clGrey);
						selected = true;
					}
				}
				if (currentPenColour == clBlue)
				{
					std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 3); }});
					Button * button = dynamic_cast<Button*>(*it);
					if (button)
					{
						button->setPenColour(clGrey);
						selected = true;
					}
				}
				if (currentBackColour == clRed)
				{
					std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 4); }});
					Button * button = dynamic_cast<Button*>(*it);
					if (button)
					{
						button->setPenColour(clGrey);
						selected = true;
					}
				}
				if (currentBackColour == clGreen)
				{
					std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 5); }});
					Button * button = dynamic_cast<Button*>(*it);
					if (button)
					{
						button->setPenColour(clGrey);
						selected = true;
					}
				}
				if (currentBackColour == clBlue)
				{
					std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 6); }});
					Button * button = dynamic_cast<Button*>(*it);
					if (button)
					{
						button->setPenColour(clGrey);
						selected = true;
					}
				}
				instance->setShapePos(count-1);
			}
			if (found == false)
				selected = false;
		}
	}
}

void DrawingTool::checkIfMovable(ObjectControl* object)
{
	DrawLine* line = dynamic_cast<DrawLine*>(object);
	if (line)
	{
		for (int i = instance->getStartX()-1; i < instance->getStartX()+1; i++)
		{
			for (int j = instance->getStartY()-1; j < instance->getStartY()+1; j++)
			{
				if ((int)distanceBetween(i, line->getX(), j, line->getY()) + (int)distanceBetween(line->getW(), i, line->getH(), j) == (int)distanceBetween(line->getW(), line->getX(), line->getH(), line->getY()))
				{
					currentType = 1;
					currentPenColour = line->getPenColour();
					currentBackColour = line->getBackColour();
					currentStartX = line->getX();
					currentStartY = line->getY();
					currentEndX = line->getW();
					currentEndY = line->getH();
					found = true;
				}
			}
		}
	}
	DrawRect* rect = dynamic_cast<DrawRect*>(object);
	if (rect)
	{
		int x0 = rect->getX();
		int y0 = rect->getY();
		int x1 = rect->getX() + rect->getW();
		int y1 = rect->getY() + rect->getH();
		if (x0 < x1 && y0 < y1)
			if (((instance->getStartX() > x0) && (instance->getStartX() < x1)) && ((instance->getStartY() > y0) && (instance->getStartY() < y1)))
			{
				currentType = 2;
				currentPenColour = rect->getPenColour();
				currentBackColour = rect->getBackColour();
				currentStartX = rect->getX();
				currentStartY = rect->getY();
				currentEndX = rect->getW();
				currentEndY = rect->getH();
				found = true;
			}
		if (x0 < x1 && y0 > y1)
			if (((instance->getStartX() > x0) && (instance->getStartX() < x1)) && ((instance->getStartY() < y0) && (instance->getStartY() > y1)))
			{
				currentType = 2;
				currentPenColour = rect->getPenColour();
				currentBackColour = rect->getBackColour();
				currentStartX = rect->getX();
				currentStartY = rect->getY();
				currentEndX = rect->getW();
				currentEndY = rect->getH();
				found = true;
			}
		if (x0 > x1 && y0 < y1)
			if (((instance->getStartX() < x0) && (instance->getStartX() > x1)) && ((instance->getStartY() > y0) && (instance->getStartY() < y1)))
			{
				currentType = 2;
				currentPenColour = rect->getPenColour();
				currentBackColour = rect->getBackColour();
				currentStartX = rect->getX();
				currentStartY = rect->getY();
				currentEndX = rect->getW();
				currentEndY = rect->getH();
				found = true;
			}
		if (x0 > x1 && y0 > y1)
			if (((instance->getStartX() < x0) && (instance->getStartX() > x1)) && ((instance->getStartY() < y0) && (instance->getStartY() > y1)))
			{
				currentType = 2;
				currentPenColour = rect->getPenColour();
				currentBackColour = rect->getBackColour();
				currentStartX = rect->getX();
				currentStartY = rect->getY();
				currentEndX = rect->getW();
				currentEndY = rect->getH();
				found = true;
			}
	}
	DrawCircle* circ = dynamic_cast<DrawCircle*>(object);
	if (circ)
	{
		if (distanceBetween(instance->getStartX(), circ->getX(), instance->getStartY(), circ->getY()) <= circ->getRadius())
		{
			currentType = 3;
			currentPenColour = circ->getPenColour();
			currentBackColour = circ->getBackColour();
			currentStartX = circ->getX();
			currentStartY = circ->getY();
			currentEndX = circ->getRadius();
			found = true;
		}
	}
	count++;
}

float DrawingTool::distanceBetween(int x1, int x0, int y1, int y0)
{
	return sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0)));
}

void DrawingTool::onLButtonUp(UINT nFlags, int x, int y)
{
	if (instance->getStartX() != NULL && instance->getStartY() != NULL)
	{
		switch (instance->getMode())
		{
		case 7:
		{
			objects.push_back(new DrawLine(instance->getPenColour(), instance->getBackColour(), instance->getStartX(), instance->getStartY(), x, y));
			pen = 0, back = 0;
			delete curLine;
			curLine = NULL;
			break;
		}
		case 9:
		{
			int radius = sqrt(((x - instance->getStartX()) * (x - instance->getStartX())) + ((y - instance->getStartY()) * (y - instance->getStartY())));
			objects.push_back(new DrawCircle(instance->getPenColour(), instance->getBackColour(), instance->getStartX(), instance->getStartY(), radius, true));
			pen = 0, back = 0;
			delete curCircle;
			curCircle = NULL;
			break;
		}
		case 10:
		{
			int width = x - instance->getStartX();
			int height = y - instance->getStartY();
			objects.push_back(new DrawRect(instance->getPenColour(), instance->getBackColour(), instance->getStartX(), instance->getStartY(), width, height));
			pen = 0, back = 0;
			delete curRect;
			curRect = NULL;
			break;
		}
		case 11:
		{
			if (currentType == 1)
			{
				int newStartX = currentStartX - (instance->getStartX() - x);
				int newStartY = currentStartY - (instance->getStartY() - y);
				int newEndX = currentEndX - (instance->getStartX() - x);
				int newEndY = currentEndY - (instance->getStartY() - y);
				objects.push_back(new DrawLine(currentPenColour, currentBackColour, newStartX, newStartY, newEndX, newEndY));
				delete curLine;
				curLine = NULL;
			}
			if (currentType == 2)
			{
				int newStartX = currentStartX - (instance->getStartX() - x);
				int newStartY = currentStartY - (instance->getStartY() - y);
				int newEndX = currentEndX;
				int newEndY = currentEndY;
				objects.push_back(new DrawRect(currentPenColour, currentBackColour, newStartX, newStartY, newEndX, newEndY));
				delete curRect;
				curRect = NULL;
			}
			if (currentType == 3)
			{
				int newStartX = currentStartX - (instance->getStartX() - x);
				int newStartY = currentStartY - (instance->getStartY() - y);
				int newRadius = currentEndX;
				objects.push_back(new DrawCircle(currentPenColour, currentBackColour, newStartX, newStartY, newRadius, true));
				delete curCircle;
				curCircle = NULL;
			}
			currentType = 0;
			currentStartX = NULL;
			currentStartY = NULL;
			currentEndX = NULL;
			currentEndY = NULL;
			pen = 0, back = 0;
			break;
		}
		case 13:
		{
			std::vector<ObjectControl*>::iterator it = std::find_if(objects.begin(), objects.end(), [](ObjectControl * x) {Button* button = dynamic_cast<Button*>(x); if (button) { return (button->getMode() == 13); }});
			Button * button = dynamic_cast<Button*>(*it);
			if (button)
				button->setPenColour(clGrey);
		}
		}
		instance->setStartX(NULL);
		instance->setStartY(NULL);
		onDraw();
	}
}

void DrawingTool::onMouseMove(UINT nFlags, int x, int y)
{
	if (x > 0 && x < 1000 && y > 0 && y < 900)
	{
		if (instance->getMode() == 7 && instance->getStartX() != NULL && instance->getStartY() != NULL)
		{
			delete curLine;
			curLine = NULL;
			curLine = new DrawLine(instance->getPenColour(), instance->getBackColour(), instance->getStartX(), instance->getStartY(), x, y);
			onDraw();
		}
		if (instance->getMode() == 9 && instance->getStartX() != NULL && instance->getStartY() != NULL)
		{
			delete curCircle;
			curCircle = NULL;
			int radius = sqrt(((x - instance->getStartX()) * (x - instance->getStartX())) + ((y - instance->getStartY()) * (y - instance->getStartY())));
			curCircle = new DrawCircle(instance->getPenColour(), instance->getBackColour(), instance->getStartX(), instance->getStartY(), radius, true);
			onDraw();
		}
		if (instance->getMode() == 10 && instance->getStartX() != NULL && instance->getStartY() != NULL)
		{
			delete curRect;
			curRect = NULL;
			int width = x - instance->getStartX();
			int height = y - instance->getStartY();
			curRect = new DrawRect(instance->getPenColour(), instance->getBackColour(), instance->getStartX(), instance->getStartY(), width, height);
			onDraw();
		}
		if (instance->getMode() == 11 && instance->getStartX() != NULL && instance->getStartY() != NULL)
		{
			if (currentType == 1)
			{
				delete curLine;
				curLine = NULL;
				int newStartX = currentStartX - (instance->getStartX() - x);
				int newStartY = currentStartY - (instance->getStartY() - y);
				int newEndX = currentEndX - (instance->getStartX() - x);
				int newEndY = currentEndY - (instance->getStartY() - y);
				curLine = new DrawLine(currentPenColour, currentBackColour, newStartX, newStartY, newEndX, newEndY);
				onDraw();
			}
			if (currentType == 2)
			{
				delete curRect;
				curRect = NULL;
				int newStartX = currentStartX - (instance->getStartX() - x);
				int newStartY = currentStartY - (instance->getStartY() - y);
				int newEndX = currentEndX;
				int newEndY = currentEndY;
				curRect = new DrawRect(currentPenColour, currentBackColour, newStartX, newStartY, newEndX, newEndY);
				onDraw();
			}
			if (currentType == 3)
			{
				delete curCircle;
				curCircle = NULL;
				int newStartX = currentStartX - (instance->getStartX() - x);
				int newStartY = currentStartY - (instance->getStartY() - y);
				int newRadius = currentEndX;
				curCircle = new DrawCircle(currentPenColour, currentBackColour, newStartX, newStartY, newRadius, true);
				onDraw();
			}
		}
	}
}

void DrawingTool::onCreate()
{
	objects.push_back(new Button(clGrey, clDarkRed, 81, 3, 75, 75, true, L".\\artwork\\RedPen.bmp", 1));
	objects.push_back(new Button(clDarkRed, clDarkRed, 159, 3, 75, 75, true, L".\\artwork\\GreenPen.bmp", 2));
	objects.push_back(new Button(clDarkRed, clDarkRed, 237, 3, 75, 75, true, L".\\artwork\\BluePen.bmp", 3));
	objects.push_back(new Button(clGrey, clDarkRed, 465, 3, 75, 75, true, L".\\artwork\\RedFill.bmp", 4));
	objects.push_back(new Button(clDarkRed, clDarkRed, 543, 3, 75, 75, true, L".\\artwork\\GreenFill.bmp", 5));
	objects.push_back(new Button(clDarkRed, clDarkRed, 621, 3, 75, 75, true, L".\\artwork\\BlueFill.bmp", 6));
	objects.push_back(new Button(clDarkRed, clDarkRed, 3, 81, 75, 75, true, L".\\artwork\\Line.bmp", 7));
	objects.push_back(new Button(clDarkRed, clDarkRed, 3, 159, 75, 75, true, L".\\artwork\\Circle.bmp", 9));
	objects.push_back(new Button(clDarkRed, clDarkRed, 3, 237, 75, 75, true, L".\\artwork\\Rectangle.bmp", 10));
	objects.push_back(new Button(clDarkRed, clDarkRed, 3, 315, 75, 75, true, L".\\artwork\\Move.bmp", 11));
	objects.push_back(new Button(clDarkRed, clDarkRed, 3, 393, 75, 75, true, L".\\artwork\\Delete.bmp", 12));
	objects.push_back(new Button(clDarkRed, clDarkRed, 3, 471, 75, 75, true, L".\\artwork\\ColourChange.bmp", 13));
	objects.push_back(new Button(clDarkRed, clDarkRed, 3, 559, 75, 75, true, L".\\artwork\\Load.bmp", 14));
	objects.push_back(new Button(clDarkRed, clDarkRed, 3, 637, 75, 75, true, L".\\artwork\\Save.bmp", 15));
	EasyGraphics::onCreate();
	::SetWindowText(getHWND(), L"Drawing Tool");
}