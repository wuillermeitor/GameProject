#pragma once
#include <iostream>
#include "Renderer.h"

enum CurrentScene { EXIT, MENU, PLAY, RANKING };
enum CurrentState { RUNNING, GOTO};
class Game
{
public:
	Game();
	~Game();
	void LoopGame();
};

