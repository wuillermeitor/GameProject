#pragma once
#include <ctime>
#include <iostream>
#include "Types.h"
#include "Renderer.h"



class Bombas 
{
public:
	std::string Bombas_ID, BombasPath;
	std::string Explosion_ID, ExplosionPath;
	SDL_Rect Bombas_Rect, Bombas_Position;
	SDL_Rect Explosion_Rect, Explosion_Position;
	int frameWidth, frameHeight;
	int textWidth = 144;
	int textHeight = 96;
	Bombas();
	~Bombas();
	void Update();
	void Draw(int i, int j);
	clock_t lastTime = clock();
	float timeDown = 3.;
	float deltaTime = 0;
	bool explosion = false;

private:
};

