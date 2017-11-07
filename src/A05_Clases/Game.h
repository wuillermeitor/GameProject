#pragma once
#include "Scene.h"

enum GameState { MENU, PLAY, EXIT };

class Game {
private:
	GameState gamestate;
public:
	Game();
	void Run();
	~Game();
};

