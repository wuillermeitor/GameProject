#include "Level.h"




Level::Level()
{
	Renderer::Instance()->LoadTexture(BACKGROUND, "../../res/img/bgGame.jpg");

	if (gamestate == GameState::PLAY) {
		gamestate = GameState::PLAY;
	}

	tablero = new GameObject**[15];
	for (int i = 0; i < 15; i++) {
		tablero[i] = new GameObject*[13];
	}

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 13; j++) {
			if (i == 0 || i == 14 || j == 0 || j == 12) { ///Bloques limites
				tablero[i][j] = new Wall();
				tablero[i][j]->GameObject_Rect.x = i * 48; //48 de costat
				tablero[i][j]->GameObject_Rect.y = j * 48 + 80; //48 de cada costat + 80 de HUD
				//NO PRINTA NADA ME QUIERO MORIR
			}
			else if ((j == 2 || j == 4 || j == 6 || j == 8 || j == 10) && (i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12)) { //Bloques segun lvl1 practica
				tablero[i][j] = new Wall();
				tablero[i][j]->GameObject_Rect.x = i * 48;
				tablero[i][j]->GameObject_Rect.y = j * 48 + 80;
				//NO PRINTA NADA ME QUIERO MORIR

			}
			else {
				tablero[i][j] = nullptr;
			}

		}
	}
	////neteja memoria
	//for (int i = 0; i < 13; i++)
	//{
	//	for (int j = 0; j < 11; j++)
	//	{
	//		map[i][j] = nullptr;
	//	}
	//}

	////omple tot el mapa de blocs destruibles
	//for (int i = 0; i < 13; i++)
	//{
	//	for (int j = 0; j < 11; j++)
	//	{
	//		map[i][j] = new Wall(true, i, j);
	//	}
	//}

	////neteja els llocs que han de ser buits segons el mapa de la practica
	//map[1][1] = nullptr;
	//map[1][3] = nullptr;
	//map[1][5] = nullptr;
	//map[1][7] = nullptr;
	//map[1][9] = nullptr;

	//map[3][1] = nullptr;
	//map[3][3] = nullptr;
	//map[3][5] = nullptr;
	//map[3][7] = nullptr;
	//map[3][9] = nullptr;

	//map[5][1] = nullptr;
	//map[5][3] = nullptr;
	//map[5][5] = nullptr;
	//map[5][7] = nullptr;
	//map[5][9] = nullptr;

	//map[7][1] = nullptr;
	//map[7][3] = nullptr;
	//map[7][5] = nullptr;
	//map[7][7] = nullptr;
	//map[7][9] = nullptr;

	//map[9][1] = nullptr;
	//map[9][3] = nullptr;
	//map[9][5] = nullptr;
	//map[9][7] = nullptr;
	//map[9][9] = nullptr;

	//map[11][1] = nullptr;
	//map[11][3] = nullptr;
	//map[11][5] = nullptr;
	//map[11][7] = nullptr;
	//map[11][9] = nullptr;

	////canvia destruibles per no destruibles 
	//for (int i = 2; i <= 12; i = i + 2)
	//{
	//	for (int j = 2; j <= 10; j = j + 2)
	//	{
	//		map[i][j] = new Wall(false, i, j);
	//	}
	//}


}


Level::~Level()
{

}

void Level::Setup()
{

}

void Level::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(BG_ID, BG_Rect);
	Renderer::Instance()->PushImage(WALL_ID, Wall_Rect);
	Renderer::Instance()->PushImage(LIMIT_ID, Limit_Rect);

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 13; ++j) {
			if (tablero[i][j] != nullptr)
				tablero[i][j]->draw();
		}
	}

	Renderer::Instance()->Render();
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