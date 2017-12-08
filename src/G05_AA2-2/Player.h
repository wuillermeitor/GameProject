#pragma once
#include "Renderer.h"
class Player
{
public:
	//Variables
	std::string Player_ID, PlayerPath;
	SDL_Rect Player_Rect, Player_Position;
	int textWidth = 192;
	int textHeight = 94;
	int frameWidth, frameHeight;
	int frameTime;
	int cambiop = 1;
	//Métodos
	Player();
	~Player();
	void EventHandler(SDL_Event evento);
	void Update();
	void Draw();

};

