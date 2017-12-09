#pragma once
#include "Player.h"
#include <iostream>
#include <ctime>
#include "Renderer.h"
#include "Types.h"
class HUD {

public:
	bool findeljuego = false;
	//variable para la FINAL COUNTODOWN TIRORIO TIRORITOTI
	clock_t lastTime = clock();
	float timeDown = 80;
	float deltaTime = 0;
	//Vidas i score font y rect
	Font font;
	Color color;
	Text P1lifes;
	SDL_Rect P1lifes_Rect;
	Text P2lifes;
	SDL_Rect P2lifes_Rect;
	Text P1score;
	SDL_Rect P1score_Rect;
	Text P2score;
	SDL_Rect P2score_Rect;
	//Time font y rect
	Text Time;
	SDL_Rect Time_Rect;
	//int position vidas y score
	int P1lifesXpositionText;
	int P1lifesYpositionText;
	int P2lifesXpositionText;
	int P2lifesYpositionText;
	int P1scoreXpositionText;
	int P1scoreYpositionText;
	int P2scoreXpositionText;
	int P2scoreYpositionText;
	//int position Time
	int TimeXpositionText;
	int TimeYpositionText;



	HUD();
	~HUD();

	void Update();
	void Draw();
};