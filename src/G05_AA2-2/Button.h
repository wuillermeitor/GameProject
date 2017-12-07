#pragma once
#include <iostream>
#include "Types.h"

class Button
{
public:
	Button();
	~Button();
	void eventHandler(SDL_Event buttonevent);
	bool isClicked();
	bool isHovered();
	void update();
	void draw();

public:
	TextB message;

private:
	bool leftClick;
};
