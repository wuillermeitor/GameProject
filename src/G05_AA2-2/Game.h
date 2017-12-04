#pragma once
#include <iostream>
#include "Renderer.h"
#include "Menu.h"
#include "Play.h"



class Game {

private:
	GameState gmst;
	Scene *currentScene;

public:
	Game();
	~Game();

	void LoopGame();

};

