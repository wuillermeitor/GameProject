#pragma once
#include "Game.h"


Game::Game() {
	//puntero de tipo escena que controla menu y play y ranking
	gmst = GameState::MENU;
	currentscene = new Menu();
}

Game::~Game()
{
}

void Game::LoopGame() {
	while (gmst != GameState::EXIT) {
		switch (currentscene->getState()) {

		case SceneState::RUNNING:
			Renderer::Instance()->Clear();
			currentscene->EventHandler();
			currentscene->Update();
			currentscene->Draw();
			Renderer::Instance()->Render();

		case SceneState::GOTO:
			switch (gmst) {
			case GameState::PLAY:
				delete currentscene;
				currentscene = new Menu();
				gmst = GameState::MENU;


			case GameState::MENU:
				delete currentscene;
				currentscene = new Play();
				gmst = GameState::PLAY;

			case GameState::EXIT:
				gmst = GameState::EXIT;
				delete currentscene;

			default:
				break;
			}

			break;

		case SceneState::EXIT:
			gmst = GameState::EXIT;
			delete currentscene;
			break;

		default:
			break;
		}

	}
}