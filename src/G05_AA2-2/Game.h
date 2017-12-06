#pragma once
#include <iostream>
#include "Renderer.h"
#include "Menu.h"
#include "Play.h"


enum CurrentScene { EXIT, MENU, PLAY, RANKING };
enum CurrentState { RUNNING, GOTO };

class Game
{
private:
	GameState gmst;
	Scene *currentscene;

	CurrentState currentstate;
public:
	Game();
	~Game();

	void LoopGame();

};

