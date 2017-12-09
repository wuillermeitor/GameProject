#pragma once
#include <iostream>
#include "Renderer.h"
#include "Level.h"
#include "Bombas.h"
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
	bool dropbomb = false;
	int dropX, dropY;
	int lifes;
	bool IsPoweredUp;
	int score;
	Vector2 tmpPosXY;
	Bombas bomba;
	Level lvl;

	//M�todos
	Player();
	~Player();
	void EventHandler(SDL_Event evento);
	void Update(SDL_Scancode UP, SDL_Scancode DOWN, SDL_Scancode LEFT, SDL_Scancode RIGHT, SDL_Scancode DropBomb);
	void Draw();
	void SpawnBomba(int, int);

};

