#include "Level.h"




Level::Level()
{
	Renderer::Instance()->LoadTexture(BACKGROUND, PATH_IMG + "bgGame.jpg");


	//if gamestate = PLAY
	///////////////////////////////gamestate = GameState::PLAY; NO SE USAR GAMESTATE PORQUE SOY UN PUTO INUTIL
	//neteja memoria
	for (int i = 1; i < 14; i++)
	{
		for (int j = 1; j < 12; j++)
		{
			map[i][j] = nullptr;
		}
	}

	//omple tot el mapa de blocs destruibles
	for (int i = 1; i < 14; i++)
	{
		for (int j = 1; j < 12; j++)
		{
			map[i][j] = new Wall(true, i, j);
		}
	}

	//neteja els llocs que han de ser buits segons el mapa de la practica
	map[1][1] = nullptr;
	map[1][2] = nullptr;
	map[1][3] = nullptr;
	map[2][1] = nullptr;
	map[3][1] = nullptr;

	map[13][11] = nullptr;
	map[13][10] = nullptr;
	map[13][9] = nullptr;
	map[12][11] = nullptr;
	map[11][11] = nullptr;

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

void Level::setup()
{

}

void Level::draw()
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

void Level::update()
{

}

void Level::inputHandler()
{

}

void Level::spawnObject()
{

}

void Level::destroyObject()
{

}