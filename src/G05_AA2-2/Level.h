#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Constants.h"
#include "GameObject.h"
#include "Wall.h"
#include "Menu.h"
#include "Button.h"

class Level :
	public Scene
{
public:
	GameObject * map[SCREEN_WIDTH / SCRIPT_SIZE][(SCREEN_HEIGHT - HUD_HEIGHT) / SCRIPT_SIZE]; 
	int time;
	std::string BG_ID;
	SDL_Rect BG_Rect{ 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };


	Level();
	~Level();

private:
	void setup();
	void draw(); 
	void update(); 
	void inputHandler(); 
	void spawnObject();
	void destroyObject();

};

