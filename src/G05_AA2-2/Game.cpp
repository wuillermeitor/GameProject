#pragma once
#include "Game.h"


Game::Game() {
	//puntero de tipo escena que controla menu y play y ranking
	gamestate = GameState::MENU;
	currentscene = new Menu();
}

Game::~Game()
{
}

void Game::LoopGame() {
	while (gamestate != GameState::EXIT) {
		if (currentscene->getState() == SceneState::RUNNING) {
			//std::cout << "estoy en estado running" << std::endl;
			currentscene->EventHandler();
			currentscene->Update();
			currentscene->Draw();
		}
		else if (currentscene->getState() == SceneState::GOTO) {
			//std::cout << "estoy en estado go to" << std::endl;
			if (gamestate == GameState::PLAY) {
				delete currentscene;
				currentscene = new Menu();
				gamestate = GameState::MENU;
			}
			else if (gamestate == GameState::MENU) {
				delete currentscene;
				currentscene = new Play();
				gamestate = GameState::PLAY;
			}
			else if (gamestate == GameState::RANKING) {
				delete currentscene;
				currentscene = new Play();
				gamestate = GameState::MENU;
			}
			//switch (gamestate) {
			//case GameState::PLAY:
			//	delete currentscene;
			//	currentscene = new Menu();
			//	gamestate = GameState::MENU;


			//case GameState::MENU:
			//	delete currentscene;
			//	currentscene = new Play();
			//	gamestate = GameState::PLAY;

			//case GameState::EXIT:
			//	gamestate = GameState::EXIT;
			//	delete currentscene;

			//default:
			//	break;
			//}
		}

		//switch (currentscene->getState()) {
		//case SceneState::RUNNING:
		//	currentscene->EventHandler();
		//	currentscene->Update();
		//	currentscene->Draw();

		//case SceneState::GOTO:
		//	std::cout << "estoy en estado go to" << std::endl;
		//	switch (gamestate) {
		//	case GameState::PLAY:
		//		delete currentscene;
		//		currentscene = new Menu();
		//		gamestate = GameState::MENU;


		//	case GameState::MENU:
		//		delete currentscene;
		//		currentscene = new Play();
		//		gamestate = GameState::PLAY;

		//	case GameState::EXIT:
		//		gamestate = GameState::EXIT;
		//		delete currentscene;

		//	default:
		//		break;
		//	}

		//	break;

		//case SceneState::EXIT:
		//	std::cout << "estoy en estado exit" << std::endl;
		//	gamestate = GameState::EXIT;
		//	delete currentscene;
		//	break;

		//default:
		//	break;
		//}

	}
}