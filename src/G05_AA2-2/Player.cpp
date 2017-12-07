#pragma once
#include "Player.h"



Player::Player()
{
	PlayerPath = "../../res/img/player1.png";
	Renderer::Instance()->LoadTexture(Player_ID, PlayerPath);
	Renderer::Instance()->GetTextureSize(Player_ID);
	frameWidth = textWidth / 3;
	frameHeight = textHeight / 4;
	Player_Position.x = 200;
	Player_Position.y = 300;
	Player_Rect.x = frameWidth * 3;
	Player_Rect.y = 0;
	Player_Position.h = 100;
	Player_Rect.h = frameHeight;
	Player_Position.w = 100;
	Player_Rect.w = frameWidth;
	frameTime = 0;
}


Player::~Player()
{
}

void Player::movement() {
	//const Uint8 *keyboardstate = SDL_GetKeyboardState(NULL);
	////Player 1
	//if (keyboardstate[SDL_SCANCODE_D] && PlayerPosition.x + PlayerPosition.w < SCREEN_WIDTH) {
	//	playerRect.y = frameHeight * 2;
	//	PlayerPosition.x += 10;
	//}
	//else if (keyboardstate[SDL_SCANCODE_A] && PlayerPosition.x > 0) {
	//	playerRect.y = frameHeight;
	//	PlayerPosition.x -= 10;
	//}
	//if (keyboardstate[SDL_SCANCODE_W] && PlayerPosition.y > 130) {
	//	playerRect.y = frameHeight * 3;
	//	PlayerPosition.y -= 10;
	//}
	//else if (keyboardstate[SDL_SCANCODE_S] && PlayerPosition.y + PlayerPosition.h < SCREEN_HEIGHT) {
	//	playerRect.y = frameHeight * 0;
	//	PlayerPosition.y += 10;
	//}
	////Player 2
	//if (keyboardstate[SDL_SCANCODE_RIGHT] && Player2Position.x + Player2Position.w < SCREEN_WIDTH) {
	//	player2Rect.y = frameHeight * 6;
	//	Player2Position.x += 10;
	//}
	//else if (keyboardstate[SDL_SCANCODE_LEFT] && Player2Position.x > 0) {
	//	player2Rect.y = frameHeight * 5;
	//	Player2Position.x -= 10;
	//}
	//if (keyboardstate[SDL_SCANCODE_UP] && Player2Position.y > 130) {
	//	player2Rect.y = frameHeight * 7;
	//	Player2Position.y -= 10;
	//}
	//else if (keyboardstate[SDL_SCANCODE_DOWN] && Player2Position.y + Player2Position.h < SCREEN_HEIGHT) {
	//	player2Rect.y = frameHeight * 4;
	//	Player2Position.y += 10;
	//}
}
