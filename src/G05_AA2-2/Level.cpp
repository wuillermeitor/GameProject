#include "Level.h"




Level::Level()
{

	Renderer::Instance()->LoadTexture(BACKGROUND, "../../res/img/bgGame.jpg");
	casillasAncho = 11;
	casillasAlto = 13;
	wall = Wall();
	tablero = new casillas*[casillasAncho];
	for (int i = 0; i < casillasAncho; i++) {
		tablero[i] = new casillas[casillasAlto];
		for (int j = 0; j < casillasAlto; j++) {
			if ((i == 1 || i == 3 || i == 5 || i == 7 || i == 9) && (j == 1 || j == 3 || j == 5 || j == 7 || j == 9 || j == 11)) {
				tablero[i][j] = casillas::INDESTRUCTIBLE_WALL;
			}
			else {
				tablero[i][j] = casillas::EMPTY;
			}
		}
	}
	limiteIJ = { 0, 0 };
	limiteWH = { casillasAncho, casillasAlto };

}


Level::~Level()
{

}

Vector2 Level::CoordenadaACasilla(int x, int y)
{
	int iCoordenada;
	int jCoordenada;
	iCoordenada = (x / LADO_CASILLA) - 1;
	jCoordenada = (y / LADO_CASILLA) - (HUD_HEIGHT / LADO_CASILLA) - 1;
	Vector2 casilla{ jCoordenada, iCoordenada };
	return casilla;
}

Vector2 Level::CasillaACoordenada(int i, int j)
{
	int iCasilla;
	int jCasilla;
	iCasilla = HUD_HEIGHT + LADO_CASILLA + (i * LADO_CASILLA);
	jCasilla = LADO_CASILLA + (j * LADO_CASILLA);
	Vector2 coordenada{ jCasilla, iCasilla };
	return coordenada;
}

void Level::Draw()
{
	
	for (int i = 0; i < casillasAncho; ++i) {
		for (int j = 0; j < casillasAlto; ++j) {
			if (tablero[i][j] == casillas::INDESTRUCTIBLE_WALL) {
				Vector2 coordenadas = CasillaACoordenada(i, j);
				wall.Wall_ID = INDESTRUCTIBLE_WALL;
				wall.draw(wall.Wall_ID, coordenadas.x, coordenadas.y);
			}
			else if (tablero[i][j] == casillas::DESTRUCTIBLE_WALL) {
				Vector2 coordenadas = CasillaACoordenada(i, j);
				wall.Wall_ID = DESTRUCTIBLE_WALL;
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