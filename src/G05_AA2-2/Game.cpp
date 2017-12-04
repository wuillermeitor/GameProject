#pragma once
#include "Game.h"


Game::Game() {

	gmst = GameState::MENU;
	currentScene = new Menu();

<<<<<<< HEAD
=======
Game::Game()
{
	currentscene = MENU;
>>>>>>> 81776c7cd0ea89bb3324666f2dd95d4744610e92
}


Game::~Game()
{
}

void Game::LoopGame() {
<<<<<<< HEAD
	while (gmst != GameState::EXIT) {

		switch (currentScene->getState()) {

		case SceneState::RUNNING:
			currentScene->EventHandler();
			currentScene->Update();
			currentScene->Draw();
=======
	while (currentscene != EXIT) {
		switch(currentstate){
		case RUNNING:
>>>>>>> 81776c7cd0ea89bb3324666f2dd95d4744610e92
			break;

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


}