#pragma once
#include <iostream>
#include <string>
#include "Scene.h"
#include "Renderer.h"
#include "Types.h"
#include "Constants.h"
#include "Button.h"


class Menu : public Scene {

private:
	//variables
	std::string BG_ID;
	SDL_Rect BG_Rect{ 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
public:
	Menu();
	~Menu();

	void EventHandler();
	void Update();
	void Draw();

	Button* playB;



};

