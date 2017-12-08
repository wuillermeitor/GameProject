#pragma once
#include "Player.h"
#include <iostream>


Player::Player()
{
	PlayerPath = "../../res/img/player1.png";
	Player_ID = PLAYER1_SPRITE;
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
	Renderer::Instance()->LoadTexture(Player_ID, PlayerPath);
	Renderer::Instance()->GetTextureSize(Player_ID);
}


Player::~Player()
{
}

void Player::EventHandler(SDL_Event evento) {
	/*switch (evento.type) {
	default:
		break;
	}*/
}

void Player::Update() {
	const Uint8 *keyboardstate = SDL_GetKeyboardState(NULL);
	//Player 1
	if (keyboardstate[SDL_SCANCODE_D] && Player_Position.x + Player_Position.w < SCREEN_WIDTH) {
		Player_Rect.y = frameHeight * 2;
		Player_Position.x += 10;
		std::cout << "Se mueve a la derecha" << std::endl;
	}
	else if (keyboardstate[SDL_SCANCODE_A] && Player_Position.x > 0) {
		Player_Rect.y = frameHeight;
		Player_Position.x -= 10;
		std::cout << "Se mueve a la izquierda" << std::endl;
	}
	else if (keyboardstate[SDL_SCANCODE_W] && Player_Position.y > 130) {
		Player_Rect.y = frameHeight * 3;
		Player_Position.y -= 10;
		std::cout << "Se mueve hacia arriba" << std::endl;
	}
	else if (keyboardstate[SDL_SCANCODE_S] && Player_Position.y + Player_Position.h < SCREEN_HEIGHT) {
		Player_Rect.y = frameHeight * 0;
		Player_Position.y += 10;
		std::cout << "Se mueve hacia abajo" << std::endl;
	}
	////Player 2
	//if (keyboardstate[SDL_SCANCODE_RIGHT] && Player_Position.x + Player_Position.w < SCREEN_WIDTH) {
	//	Player_Rect.y = frameHeight * 6;
	//	Player_Position.x += 10;
	//}
	//else if (keyboardstate[SDL_SCANCODE_LEFT] && Player_Position.x > 0) {
	//	Player_Rect.y = frameHeight * 5;
	//	Player_Position.x -= 10;
	//}
	//else if (keyboardstate[SDL_SCANCODE_UP] && Player_Position.y > 130) {
	//	Player_Rect.y = frameHeight * 7;
	//	Player_Position.y -= 10;
	//}
	//else if (keyboardstate[SDL_SCANCODE_DOWN] && Player_Position.y + Player_Position.h < SCREEN_HEIGHT) {
	//	Player_Rect.y = frameHeight * 4;
	//	Player_Position.y += 10;
	//}
}
void Player::Draw() {
	Renderer::Instance()->PushImage(Player_ID, Player_Rect);
}