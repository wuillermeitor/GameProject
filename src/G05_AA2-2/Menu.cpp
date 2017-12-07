#pragma once
#include "Menu.h"



Menu::Menu()
{
	scenestate = SceneState::RUNNING;
	BG_ID = "BackGround";
	std::string BGPath = "../../res/img/bgGame.jpg";
	Renderer::Instance()->LoadTexture(BG_ID, BGPath);

	playButton = new Button();
	playButton->texto.h = 50;
	playButton->texto.w = 100;
	playButton->XpositionText = SCREEN_WIDTH / 2 - playButton->texto.w / 2;
	playButton->YpositionText = SCREEN_HEIGHT / 2 - playButton->texto.h / 2;
}


Menu::~Menu()
{
}

void Menu::EventHandler() {
	SDL_Event evento;
	while (SDL_PollEvent(&evento)) {
		switch (evento.type) {
		case SDL_QUIT:
			break;
		}
		playButton->eventHandler(evento);
	}
}

void Menu::Update() {
	playButton->update();
	Renderer::Instance()->Render();
	Renderer::Instance()->Clear();
}

void Menu::Draw() {
	Renderer::Instance()->PushImage(BG_ID, BG_Rect);
	playButton->draw();
}