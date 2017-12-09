#pragma once
#include <iostream>
#include "Constants.h"
#include "Types.h"
#include "Renderer.h"

class Wall
{
public:
	//Atributos
	std::string Wall_ID, WallPath;
	SDL_Rect Wall_Rect, Wall_Position;
	int frameWidth, frameHeight;
	int textWidth = 144;
	int textHeight = 96;

	//Métodos
	Wall();
	~Wall();

	void Update();
	void Draw(int i, int j);
};

