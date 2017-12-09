#pragma once
#include "GameObject.h"

class Wall : public GameObject
{
public:
	std::string Wall_ID, WallPath;
	SDL_Rect Wall_Rect, Wall_Position;
	int frameWidth, frameHeight;
	int textWidth = 144;
	int textHeight = 96;

	Wall();
	~Wall();

	void setup() override;
	void draw() override;
	void update() override;
};