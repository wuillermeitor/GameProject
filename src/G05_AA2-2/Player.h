#pragma once
#include "Renderer.h"
class Player
{
public:
	//Variables
	std::string Player_ID, PlayerPath;
	SDL_Rect Player_Rect, Player_Position;
	int textWidth, textHeight, frameWidth, frameHeight;
	int frameTime;
	//Métodos
	Player();
	~Player();
	void movement();

};

