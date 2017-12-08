#pragma once
#include "Menu.h"



Menu::Menu()
{
	scenestate = SceneState::RUNNING;
	BG_ID = BACKGROUND;
	std::string BGPath = "../../res/img/bgGame.jpg";
	Renderer::Instance()->LoadTexture(BG_ID, BGPath);

	ButtonPlay = Button();
	ButtonPlay.font.id = "game_over";
	ButtonPlay.font.path = "../../res/ttf/game_over.ttf";
	ButtonPlay.font.size = 24;
	ButtonPlay.color = { 255, 0, 0, 0 };
	ButtonPlay.texto.color = ButtonPlay.color;
	ButtonPlay.texto.id = "texto1_ID";
	ButtonPlay.texto.text = "Play";
	ButtonPlay.texto.h = 50;
	ButtonPlay.texto.w = 100;
	ButtonPlay.XpositionText = SCREEN_WIDTH / 2 - ButtonPlay.texto.w / 2;
	ButtonPlay.YpositionText = SCREEN_HEIGHT / 2 - ButtonPlay.texto.h / 2;
	Renderer::Instance()->LoadFont(ButtonPlay.font);
	Renderer::Instance()->LoadTextureText(ButtonPlay.font.id, ButtonPlay.texto);
	ButtonPlay.Texto_Rect = { ButtonPlay.XpositionText, ButtonPlay.YpositionText, ButtonPlay.texto.w, ButtonPlay.texto.h };

	ButtonRanking = Button();
	ButtonRanking.font.id = "game_over";
	ButtonRanking.font.path = "../../res/ttf/game_over.ttf";
	ButtonRanking.font.size = 24;
	ButtonRanking.color = { 255, 0, 0, 0 };
	ButtonRanking.texto.color = ButtonRanking.color;
	ButtonRanking.texto.id = "texto2_ID";
	ButtonRanking.texto.text = "Ranking";
	ButtonRanking.texto.h = 50;
	ButtonRanking.texto.w = 100;
	ButtonRanking.XpositionText = SCREEN_WIDTH / 2 - ButtonRanking.texto.w / 2;
	ButtonRanking.YpositionText = SCREEN_HEIGHT / 2;
	Renderer::Instance()->LoadFont(ButtonRanking.font);
	Renderer::Instance()->LoadTextureText(ButtonRanking.font.id, ButtonRanking.texto);
	ButtonRanking.Texto_Rect = { ButtonRanking.XpositionText, ButtonRanking.YpositionText, ButtonRanking.texto.w, ButtonRanking.texto.h };
}


Menu::~Menu()
{
}

void Menu::EventHandler() {
	SDL_Event evento;
	while (SDL_PollEvent(&evento)) {
		ButtonPlay.eventHandler(evento);
		ButtonRanking.eventHandler(evento);
		if (ButtonPlay.isClicked()) {
			scenestate = SceneState::GOTOLVL1;
		}
	}
}

void Menu::Update() {
	ButtonPlay.update();
	ButtonRanking.update();
}

void Menu::Draw() {
	Renderer::Instance()->PushImage(BG_ID, BG_Rect);
	ButtonPlay.draw();
	ButtonRanking.draw();
	Renderer::Instance()->Render();
	Renderer::Instance()->Clear();
}