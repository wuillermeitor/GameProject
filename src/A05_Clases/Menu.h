#pragma once
#include "Renderer.h"
#include "Constants.h"
#include "Types.h"



class Menu {

private:
	SDL_Event MenuEvent;
	Menu();
	Rect BG_Rect{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
public:
	void HandleEvent();
	void Update();
	void Draw();

	~Menu();
};