#include "Game.h"



Game::Game()
{
	gamestate = MENU;
	currentscene = new MENU;
}


Game::~Game()
{
}


void Game::Run() {
	while (gamestate!=EXIT) {
		switch (currentscene->getSceneState()) {
		case RUNNING: 
			currentscene->HandleEvent();
			currentscene->Update();

		}
	}
}
