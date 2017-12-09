#pragma once
#include "Scene.h"
#include "Constants.h"
#include "Wall.h"
#include "Menu.h"
#include "Button.h"

class Level {
public:
	Level * map[SCREEN_WIDTH / SCRIPT_SIZE][(SCREEN_HEIGHT - HUD_HEIGHT) / SCRIPT_SIZE]; 
	Wall **wall;
	int time;
	std::string BG_ID;
	SDL_Rect BG_Rect{ 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	GameState gamestate;

	Level();
	~Level();

private:
	void Setup();
	void Draw(); 
	void Update(); 
	void InputHandler(); 
	void SpawnObject();
	void DestroyObject();

};

