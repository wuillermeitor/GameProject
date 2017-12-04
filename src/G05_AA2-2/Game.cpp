#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::LoopGame() {
	CurrentScene currentscene;
	CurrentState currentstate;
	while (currentscene != EXIT) {
		switch(currentstate){
		case RUNNING:
			break;

		}
	}
}