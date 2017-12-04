#pragma once
#include <iostream>
#include "Renderer.h"

enum CurrentScene { EXIT, MENU, PLAY, RANKING };
enum CurrentState { RUNNING, GOTO};
class Game
{
private:
	CurrentScene currentscene;
	CurrentState currentstate;
public:
	Game();
	~Game();
	void LoopGame();
};

