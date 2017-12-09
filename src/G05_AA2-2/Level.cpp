#include "Level.h"




Level::Level()
{
	Renderer::Instance()->LoadTexture(BACKGROUND, "../../res/img/bgGame.jpg");

	wall = Wall();
	tablero = new casillas*[13];
	for (int i = 0; i < 13; i++) {
		tablero[i] = new casillas[15];
		for (int j = 0; j < 15; j++) {
			if ((i == 1 || i == 3 || i == 5 || i == 7 || i == 9) && (j == 1 || j == 3 || j == 5 || j == 7 || j == 9 || j == 11)) {
				tablero[i][j] = casillas::INDESTRUCTIBLE_WALL;
			}
			else {
				tablero[i][j] = casillas::EMPTY;
			}
		}
	}
}


Level::~Level()
{

}

Vector2 Level::CoordenadaACasilla(int x, int y)
{
	int xCasilla = x / LADO_CASILLA;
	int yCasilla = y / LADO_CASILLA;
	Vector2 casilla{ xCasilla, yCasilla };
	return casilla;
}

Vector2 Level::CasillaACoordenada(int i, int j)
{
	int iCasilla;
	int jCasilla;
	iCasilla = HUD_HEIGHT + LADO_CASILLA + (i * LADO_CASILLA);
	jCasilla = LADO_CASILLA + (j * LADO_CASILLA);
	Vector2 coordenada{ iCasilla, jCasilla };
	return coordenada;
}

void Level::Draw()
{

	for (int i = 0; i < 13; ++i) {
		for (int j = 0; j < 15; ++j) {
			if (tablero[i][j] != casillas::EMPTY) {
				Vector2 coordenadas = CasillaACoordenada(i, j);
				wall.draw(wall.Wall_ID, coordenadas.x, coordenadas.y);
			}
		}
	}
}

void Level::Update()
{

}

void Level::InputHandler()
{

}

void Level::SpawnObject()
{

}

void Level::DestroyObject()
{

}