#pragma once
#include "ObjectControl.h"
#include <cwchar>
class Button : public ObjectControl
{
public:
	Button(int penColour, int backColour, int x, int y, int w, int h, bool fill, const wchar_t* filename, int mode);
	~Button();

	void draw(EasyGraphics* canvas);
	bool hitbox(int checkx, int checky);
	int getMode();
	std::string getFilename();

private:
	int mode;
	bool fill;
	const wchar_t* filename;
};

inline Button::Button(int penColour, int backColour, int x, int y, int w, int h, bool fill, const wchar_t* filename, int mode) : ObjectControl(penColour, backColour, x, y, w, h), fill(fill), filename(filename), mode(mode){}
inline int Button::getMode() { return mode; }
inline std::string Button::getFilename() { std::wstring ws(filename); std::string str(ws.begin(), ws.end()); return str; }