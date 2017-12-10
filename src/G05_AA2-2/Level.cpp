#include "Level.h"




Level::Level()
{

	Renderer::Instance()->LoadTexture(BACKGROUND, "../../res/img/bgGame.jpg");
	casillasAncho = 11;
	casillasAlto = 13;
	Indestructible_wall = Wall();
	Indestructible_wall.Wall_ID = INDESTRUCTIBLE_WALL;
	Renderer::Instance()->LoadTexture(Indestructible_wall.Wall_ID, Indestructible_wall.WallPath);
	Renderer::Instance()->GetTextureSize(Indestructible_wall.Wall_ID);
	Indestructible_wall.frameWidth = (Indestructible_wall.textWidth / 3);
	Indestructible_wall.frameHeight = (Indestructible_wall.textHeight / 2);
	Indestructible_wall.Wall_Position.x = 0;
	Indestructible_wall.Wall_Position.y = 0;
	Indestructible_wall.Wall_Rect.x = 0;
	Indestructible_wall.Wall_Rect.y = 0;
	Indestructible_wall.Wall_Position.h = LADO_CASILLA;
	Indestructible_wall.Wall_Rect.h = Indestructible_wall.frameHeight;
	Indestructible_wall.Wall_Position.w = LADO_CASILLA;
	Indestructible_wall.Wall_Rect.w = Indestructible_wall.frameWidth;

	Destructible_wall = Wall();
	Destructible_wall.Wall_ID = INDESTRUCTIBLE_WALL;
	Renderer::Instance()->LoadTexture(Destructible_wall.Wall_ID, Destructible_wall.WallPath);
	Renderer::Instance()->GetTextureSize(Destructible_wall.Wall_ID);
	Destructible_wall.frameWidth = (Destructible_wall.textWidth / 3);
	Destructible_wall.frameHeight = (Destructible_wall.textHeight / 2);
	Destructible_wall.Wall_Position.x = 0;
	Destructible_wall.Wall_Position.y = 0;
	Destructible_wall.Wall_Rect.x = Destructible_wall.frameWidth;
	Destructible_wall.Wall_Rect.y = 0;
	Destructible_wall.Wall_Position.h = LADO_CASILLA;
	Destructible_wall.Wall_Rect.h = Destructible_wall.frameHeight;
	Destructible_wall.Wall_Position.w = LADO_CASILLA;
	Destructible_wall.Wall_Rect.w = Destructible_wall.frameWidth;

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
				Indestructible_wall.draw(Indestructible_wall.Wall_ID, coordenadas.x, coordenadas.y);
			}
			else if (tablero[i][j] == casillas::DESTRUCTIBLE_WALL) {
				Vector2 coordenadas = CasillaACoordenada(i, j);
				Destructible_wall.draw(Destructible_wall.Wall_ID, coordenadas.x, coordenadas.y);
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