#pragma once
#include "Player.h"


Player::Player(){
	PlayerPath = "../../res/img/player1.png";
	Player_ID = PLAYER1_SPRITE;
	Renderer::Instance()->LoadTexture(Player_ID, PlayerPath);
	Renderer::Instance()->GetTextureSize(Player_ID);
	tmpPosXY = lvl.CasillaACoordenada(0, 0);
	frameWidth = textWidth / 3;
	frameHeight = textHeight / 4;
	Player_Position.x = tmpPosXY.x;
	Player_Position.y = tmpPosXY.y;
	Player_Rect.x = 0;
	Player_Rect.y = 0;
	Player_Position.h = LADO_CASILLA;
	Player_Rect.h = frameHeight;
	Player_Position.w = LADO_CASILLA;
	Player_Rect.w = frameWidth;
	frameTime = 0;
	lifes = 3;
	score = 0;
	bomba = Bombas();
	lvl = Level();

	lvl.limiteIJ = lvl.CasillaACoordenada(lvl.limiteIJ.x, lvl.limiteIJ.y);
	lvl.limiteWH = lvl.CasillaACoordenada(lvl.limiteWH.x, lvl.limiteWH.y);
}


Player::~Player()
{
}

void Player::EventHandler(SDL_Event evento) {
	switch (evento.type) {
	default:
		break;
	}
}

void Player::Update(SDL_Scancode UP, SDL_Scancode DOWN, SDL_Scancode LEFT, SDL_Scancode RIGHT, SDL_Scancode DropBomb) {
	tmpPosXY = lvl.CoordenadaACasilla(Player_Position.x, Player_Position.y);
	frameTime++;
	if (FPS / frameTime <= 5) {
		frameTime = 0;
		//player 1
		if (Player_Rect.x == 48 * 2)
			cambiop = -1;
		else if (Player_Rect.x == 0)
			cambiop = 1;
		Player_Rect.x += 48*cambiop;

	}
	//std::cout << "el player " << Player_ID << " esta en la casilla " << tmpPosXY.x << " " << tmpPosXY.y << std::endl;

	const Uint8 *keyboardstate = SDL_GetKeyboardState(NULL);
	//Player Multiusos
	if (keyboardstate[UP] && Player_Position.y > lvl.limiteIJ.y) {
		Player_Rect.y = 0;
		Player_Position.y -= 5;
	}
	else if (keyboardstate[DOWN] && Player_Position.y + Player_Position.h < lvl.limiteWH.y) {
		Player_Rect.y = 48 * 2;
		Player_Position.y += 5;
	}
	else if (keyboardstate[LEFT] && Player_Position.x > lvl.limiteIJ.x && lvl.tablero[tmpPosXY.x][tmpPosXY.y] == casillas::EMPTY) {
		Player_Rect.y = 48;
		Player_Position.x -= 5;
	}
	else if (keyboardstate[RIGHT] && Player_Position.x + Player_Position.w < lvl.limiteWH.x && lvl.tablero[tmpPosXY.x][tmpPosXY.y+1]==casillas::EMPTY) {
		Player_Rect.y = 48 * 3;
		Player_Position.x += 5;
	}
	if (!dropbomb) {
		if (keyboardstate[DropBomb]) {
			bomba.lastTime = clock();
			bomba.timeDown = 3.;
			bomba.deltaTime = 0;
			std::cout << "drop bomb" << std::endl;
			dropX = Player_Position.x;
			dropY = Player_Position.y;
			dropbomb = true;
		}
	}
}
void Player::Draw() {
	if (dropbomb) {
		Player::SpawnBomba(dropX, dropY);
	}
	if (bomba.explosion) {
		bomba.lastTime = clock();
		bomba.timeDown = 3.;
		bomba.deltaTime = 0;
		dropbomb = false;
		bomba.explosion = false;
	}
	Renderer::Instance()->PushSprite(Player_ID, Player_Rect, Player_Position);
}

void Player::SpawnBomba(int i, int j) {
	bomba.Draw(i, j);
	bomba.Update();
}