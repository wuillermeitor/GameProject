#pragma once
#include "Game.h"


Game::Game() {
	//puntero de tipo escena que controla menu y play y ranking
	gmst = GameState::MENU;
	currentScene = new Menu();
}

Game::~Game()
{
}

void Game::LoopGame() {
	currentScene = new Menu();
	/*
	while (gmst != GameState::EXIT) {
		switch (currentScene->getState()) {

		case SceneState::RUNNING:
			currentScene->EventHandler();
			currentScene->Update();
			currentScene->Draw();

		case SceneState::GOTO:
			switch (gmst) {
			case GameState::PLAY:
				delete currentScene;
				currentScene = new Menu();
				gmst = GameState::MENU;


			case GameState::MENU:
				delete currentScene;
				currentScene = new Play();
				gmst = GameState::PLAY;

			case GameState::EXIT:
				gmst = GameState::EXIT;
				delete currentScene;

			default:
				break;
			}

			break;

		case SceneState::EXIT:
			gmst = GameState::EXIT;
			delete currentScene;
			break;

		default:
			break;
		}

	}
	*/


}