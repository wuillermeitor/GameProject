#pragma once
#include <iostream>
#include "Renderer.h"
#include "Menu.h"
#include "Play.h"



class Game {

private:
	GameState gmst;
	Scene *currentScene;

<<<<<<< HEAD
=======
enum CurrentScene { EXIT, MENU, PLAY, RANKING };
enum CurrentState { RUNNING, GOTO};
class Game
{
private:
	CurrentScene currentscene;
	CurrentState currentstate;
>>>>>>> 81776c7cd0ea89bb3324666f2dd95d4744610e92
public:
	Game();
	~Game();

	void LoopGame();

};

