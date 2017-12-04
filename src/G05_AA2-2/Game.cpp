#include "Game.h"



Game::Game()
{
	currentscene = MENU;
}


Game::~Game()
{
}

void Game::LoopGame() {
	while (currentscene != EXIT) {
		switch(currentstate){
		case RUNNING:
			break;

		}
	}
}