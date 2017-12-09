#pragma once
#include "GameObject.h"
class Limit : public GameObject
{
public:

	std::string Limit_ID, LimitPath;
	SDL_Rect Limit_Rect, Limit_Position;
	int frameWidth, frameHeight;
	int textWidth = 144;
	int textHeight = 96;

	Limit();
	~Limit();

	void setup();
	void draw();
	void update();
};
