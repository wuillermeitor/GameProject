#pragma once
#include "Play.h"
#include "Renderer.h"


Play::Play() {
	scenestate = SceneState::RUNNING;
	BG_ID = BACKGROUND;
	std::string BGPath = "../../res/img/bgGame.jpg";
	Renderer::Instance()->LoadTexture(BG_ID, BGPath);
	//Load player 1
	player1 = Player();
	player1.Player_ID = PLAYER1_SPRITE;
	player1.PlayerPath = "../../res/img/player1.png";
	player1.frameWidth = player1.textWidth / 3;
	player1.frameHeight = player1.textHeight / 4;
	player1.Player_Position.x = SCREEN_WIDTH / 2;
	player1.Player_Position.y = SCREEN_HEIGHT / 2;
	player1.Player_Rect.x = player1.frameWidth;
	player1.Player_Rect.y = 0;
	player1.Player_Position.h = 48;
	player1.Player_Rect.h = player1.frameHeight;
	player1.Player_Position.w = 48;
	player1.Player_Rect.w = player1.frameWidth;
	player1.frameTime = 0;
	Renderer::Instance()->LoadTexture(player1.Player_ID, player1.PlayerPath);
	Renderer::Instance()->GetTextureSize(player1.Player_ID);

	//Load player 2
	player2 = Player();
	player2.Player_ID = PLAYER2_SPRITE;
	player2.PlayerPath = "../../res/img/player2.png";
	player2.frameWidth = player2.textWidth / 3;
	player2.frameHeight = player2.textHeight / 4;
	player2.Player_Position.x = SCREEN_WIDTH / 3;
	player2.Player_Position.y = SCREEN_HEIGHT / 3;
	player2.Player_Rect.x = player2.frameWidth;
	player2.Player_Rect.y = 0;
	player2.Player_Position.h = 48;
	player2.Player_Rect.h = player2.frameHeight;
	player2.Player_Position.w = 48;
	player2.Player_Rect.w = player2.frameWidth;
	player2.frameTime = 0;
	Renderer::Instance()->LoadTexture(player2.Player_ID, player2.PlayerPath);
	Renderer::Instance()->GetTextureSize(player2.Player_ID);
}


Play::~Play() {

}


void Play::EventHandler() {
	SDL_Event evento;
	while (SDL_PollEvent(&evento)) {
		player1.EventHandler(evento);
		player2.EventHandler(evento);
	}
}

void Play::Update() {
	player1.Update();
	player2.Update();
	Renderer::Instance()->Render();
	Renderer::Instance()->Clear();
}

void Play::Draw() {
	Renderer::Instance()->PushImage(BG_ID, BG_Rect);
	player1.Draw();
	player2.Draw();
}