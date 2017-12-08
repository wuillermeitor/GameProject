#pragma once
#include <iostream>
#include "Renderer.h"
#include "Menu.h"
#include "Play.h"
#include "Ranking.h"



class Game
{
private:
	GameState gamestate;
	Scene *currentscene;
public:
	Game();
	~Game();

	void LoopGame();

};

