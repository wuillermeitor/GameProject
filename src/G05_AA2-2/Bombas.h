#pragma once
#include "Types.h"
#include "Renderer.h"
#include <ctime>



class Bombas 
{
public:
	std::string Bombas_ID, BombasPath;
	SDL_Rect Bombas_Rect, Bombas_Position;
	int frameWidth, frameHeight;
	int textWidth = 192;
	int textHeight = 94;
	Bombas(int i,int j);
	~Bombas();
	void Update();
	void Draw();

private:
	clock_t timer;
};

