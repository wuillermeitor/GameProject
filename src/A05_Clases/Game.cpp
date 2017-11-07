#include "Game.h"



Game::Game()
{
	gamestate = MENU;
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
