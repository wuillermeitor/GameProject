#pragma once
#include <iostream>
#include <string>
#include "Scene.h"
#include "Renderer.h"
#include "Types.h"
#include "Constants.h"
#include "Button.h"
#include "Player.h"
#include "Button.h"
#include "Level.h"
#include "Renderer.h"
#include "HUD.h"

class Play : public Scene {

private:
	//variables
	std::string BG_ID;
	SDL_Rect BG_Rect{ 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	Player player1;
	Player player2;
	Level lvl1;
	Button ButtonPlay;
	HUD hud;

public:
	Play();
	~Play();

	void EventHandler();
	void Update();
	void Draw();
};
