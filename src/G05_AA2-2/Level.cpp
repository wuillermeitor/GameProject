#include "Level.h"




Level::Level()
{
	Renderer::Instance()->LoadTexture(BACKGROUND, "../../res/img/bgGame.jpg");

	if (gamestate == GameState::PLAY) {
		gamestate = GameState::PLAY;
	}
	//neteja memoria
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			map[i][j] = nullptr;
		}
	}

	//omple tot el mapa de blocs destruibles
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			map[i][j] = new Wall(true, i, j);
		}
	}

	//neteja els llocs que han de ser buits segons el mapa de la practica
	map[1][1] = nullptr;
	map[1][3] = nullptr;
	map[1][5] = nullptr;
	map[1][7] = nullptr;
	map[1][9] = nullptr;

	map[3][1] = nullptr;
	map[3][3] = nullptr;
	map[3][5] = nullptr;
	map[3][7] = nullptr;
	map[3][9] = nullptr;

	map[5][1] = nullptr;
	map[5][3] = nullptr;
	map[5][5] = nullptr;
	map[5][7] = nullptr;
	map[5][9] = nullptr;

	map[7][1] = nullptr;
	map[7][3] = nullptr;
	map[7][5] = nullptr;
	map[7][7] = nullptr;
	map[7][9] = nullptr;

	map[9][1] = nullptr;
	map[9][3] = nullptr;
	map[9][5] = nullptr;
	map[9][7] = nullptr;
	map[9][9] = nullptr;

	map[11][1] = nullptr;
	map[11][3] = nullptr;
	map[11][5] = nullptr;
	map[11][7] = nullptr;
	map[11][9] = nullptr;

	//canvia destruibles per no destruibles 
	for (int i = 2; i <= 12; i = i + 2)
	{
		for (int j = 2; j <= 10; j = j + 2)
		{
			map[i][j] = new Wall(false, i, j);
		}
	}


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

	for (int i = 1; i < 14; i++)
	{
		for (int j = 1; j < 12; j++)
		{
			if (map[i][j] != nullptr) map[i][j]->draw();
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