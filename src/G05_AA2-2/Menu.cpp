#pragma once
#include "Menu.h"



Menu::Menu()
{
	scenestate = SceneState::RUNNING;
	BG_ID = "BackGround";
	std::string BGPath = "../../res/img/bgGame.jpg";
	std::cout << BGPath << std::endl;
	Renderer::Instance()->LoadTexture(BG_ID, BGPath);
	Renderer::Instance()->PushImage(BG_ID, BG_Rect);
	Renderer::Instance()->Render();
	Renderer::Instance()->Clear();
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

	}
}

void Menu::Update() {
	Renderer::Instance()->PushImage(BG_ID, BG_Rect);
}

void Menu::Draw() {
}