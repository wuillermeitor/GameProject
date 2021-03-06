#pragma once
#include <iostream>
#include <string>
#include "Scene.h"
#include "Renderer.h"
#include "Types.h"
#include "Constants.h"
#include "Button.h"
#include "Ranking.h"


class Menu : public Scene {

private:
	//variables
	std::string BG_ID;
	SDL_Rect BG_Rect{ 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
public:
	Menu();
	~Menu();

	void EventHandler() override;
	void Update() override;
	void Draw() override;

	Button ButtonPlayLvl1;
	Button ButtonPlayLvl2;
	Button ButtonRanking;
	
	



};

