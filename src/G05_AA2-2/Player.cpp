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

	const Uint8 *keyboardstate = SDL_GetKeyboardState(NULL);

	if (keyboardstate[UP] && Player_Position.y > lvl.limiteIJ.y) {
		tmpPosXY = lvl.CoordenadaACasilla(Player_Position.x + LADO_CASILLA / 2, Player_Position.y + LADO_CASILLA*2);
		if (lvl.tablero[tmpPosXY.x][tmpPosXY.y - 1] != casillas::INDESTRUCTIBLE_WALL && lvl.tablero[tmpPosXY.x][tmpPosXY.y - 1] != casillas::DESTRUCTIBLE_WALL && lvl.tablero[tmpPosXY.x][tmpPosXY.y - 1] != casillas::BOMB) {
			lvl.tablero[tmpPosXY.x][tmpPosXY.y - 1] = casillas::PLAYER;
			Player_Rect.y = 0;
			if (Rollers) {
				Player_Position.y -= speed * RollersBoost;
			}
			else {
				Player_Position.y -= speed;
			}
		}
	}
	else if (keyboardstate[DOWN] && Player_Position.y + Player_Position.h < lvl.limiteWH.y) {
		tmpPosXY = lvl.CoordenadaACasilla(Player_Position.x + LADO_CASILLA / 2, Player_Position.y + LADO_CASILLA*1.3);
		if (lvl.tablero[tmpPosXY.x][tmpPosXY.y + 1] != casillas::INDESTRUCTIBLE_WALL && lvl.tablero[tmpPosXY.x][tmpPosXY.y + 1] != casillas::DESTRUCTIBLE_WALL && lvl.tablero[tmpPosXY.x][tmpPosXY.y + 1] != casillas::BOMB) {
			lvl.tablero[tmpPosXY.x][tmpPosXY.y + 1] = casillas::PLAYER;
			Player_Rect.y = 48 * 2;
			if (Rollers) {
				Player_Position.y += speed * RollersBoost;
			}
			else {
				Player_Position.y += speed;
			}
		}
	}
	else if (keyboardstate[LEFT] && Player_Position.x > lvl.limiteIJ.x) {
		tmpPosXY = lvl.CoordenadaACasilla(Player_Position.x + Player_Position.w, Player_Position.y);
		if (lvl.tablero[tmpPosXY.x - 1][tmpPosXY.y] != casillas::INDESTRUCTIBLE_WALL && lvl.tablero[tmpPosXY.x - 1][tmpPosXY.y] != casillas::DESTRUCTIBLE_WALL && lvl.tablero[tmpPosXY.x - 1][tmpPosXY.y] != casillas::BOMB) {
			lvl.tablero[tmpPosXY.x - 1][tmpPosXY.y] = casillas::PLAYER;
			Player_Rect.y = 48;
			if (Rollers) {
				Player_Position.x -= speed * RollersBoost;
			}
			else {
				Player_Position.x -= speed;
			}
		}
	}
	else if (keyboardstate[RIGHT] && Player_Position.x + Player_Position.w < lvl.limiteWH.x) {
		tmpPosXY = lvl.CoordenadaACasilla(Player_Position.x, Player_Position.y);
		if (lvl.tablero[tmpPosXY.x + 1][tmpPosXY.y] != casillas::INDESTRUCTIBLE_WALL && lvl.tablero[tmpPosXY.x + 1][tmpPosXY.y] != casillas::DESTRUCTIBLE_WALL && lvl.tablero[tmpPosXY.x + 1][tmpPosXY.y] != casillas::BOMB) {
			lvl.tablero[tmpPosXY.x + 1][tmpPosXY.y] = casillas::PLAYER;
			Player_Rect.y = 48 * 3;
			if (Rollers) {
				Player_Position.x += speed * RollersBoost;
			}
			else {
				Player_Position.x += speed;
			}
		}
	}
	if (!dropbomb) {
		if (keyboardstate[DropBomb]) {
			tmpPosXY = lvl.CoordenadaACasilla(Player_Position.x, Player_Position.y);
			tmpPosXY = lvl.CasillaACoordenada(tmpPosXY.x, tmpPosXY.y);
			bomba.lastTime = clock();
			bomba.timeDown = 3.;
			bomba.deltaTime = 0;
			std::cout << "drop bomb" << std::endl;			
			posicionBomba = tmpPosXY;
			dropbomb = true;
		}
	}
}
void Player::Draw() {
	if (dropbomb) {
		if (lvl.tablero[posicionBomba.x][posicionBomba.y + 1] != casillas::INDESTRUCTIBLE_WALL || lvl.tablero[posicionBomba.x][posicionBomba.y + 1] != casillas::DESTRUCTIBLE_WALL) { down = false; }
		else { down = true; }
		if (lvl.tablero[posicionBomba.x][posicionBomba.y + 2] != casillas::INDESTRUCTIBLE_WALL || lvl.tablero[posicionBomba.x][posicionBomba.y + 2] != casillas::DESTRUCTIBLE_WALL) { down2 = false; }
		else { down2 = true; }
		if (lvl.tablero[posicionBomba.x][posicionBomba.y - 1] != casillas::INDESTRUCTIBLE_WALL || lvl.tablero[posicionBomba.x][posicionBomba.y - 1] != casillas::DESTRUCTIBLE_WALL) { up = false; }
		else { up = true; }
		if (lvl.tablero[posicionBomba.x][posicionBomba.y - 2] != casillas::INDESTRUCTIBLE_WALL || lvl.tablero[posicionBomba.x][posicionBomba.y - 2] != casillas::DESTRUCTIBLE_WALL) { up2 = false; }
		else { up2 = true; }
		if (lvl.tablero[posicionBomba.x][posicionBomba.x + 1] != casillas::INDESTRUCTIBLE_WALL || lvl.tablero[posicionBomba.x][posicionBomba.x + 1] != casillas::DESTRUCTIBLE_WALL) { right = false; }
		else { right = true; }
		if (lvl.tablero[posicionBomba.x][posicionBomba.x + 2] != casillas::INDESTRUCTIBLE_WALL || lvl.tablero[posicionBomba.x][posicionBomba.x + 2] != casillas::DESTRUCTIBLE_WALL) { right2 = false; }
		else { right2 = true; }
		if (lvl.tablero[posicionBomba.x][posicionBomba.x - 1] != casillas::INDESTRUCTIBLE_WALL || lvl.tablero[posicionBomba.x][posicionBomba.x - 1] != casillas::DESTRUCTIBLE_WALL) { left = false; }
		else { left = true; }
		if (lvl.tablero[posicionBomba.x][posicionBomba.x - 2] != casillas::INDESTRUCTIBLE_WALL || lvl.tablero[posicionBomba.x][posicionBomba.x - 2] != casillas::DESTRUCTIBLE_WALL) { left2 = false; }
		else { left2 = true; }



		Player::SpawnBomba(posicionBomba.x, posicionBomba.y, up, up2, down, down2, left, left2, right, right2);
		std::cout << posicionBomba.x <<" "<< posicionBomba.y  << std::endl;

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

void Player::SpawnBomba(int i, int j, bool up, bool up2, bool down, bool down2, bool left, bool left2, bool right, bool right2) {
	bomba.Draw(i,  j,  up,  up2,  down,  down2,  left,  left2,  right,  right2);
	bomba.Update();
}