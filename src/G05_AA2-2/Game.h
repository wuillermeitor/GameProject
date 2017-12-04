#pragma once
#include <iostream>
#include "Renderer.h"

enum CurrentScene { EXIT, MENU, PLAY, RANKING };

class Game
{
public:
	Game();
	~Game();
	void LoopGame();
};

