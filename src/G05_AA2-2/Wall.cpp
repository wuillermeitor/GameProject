#pragma once
#include "Wall.h"
#include "Constants.h"
#include "GameObject.h"



Wall::Wall(bool dest, int x, int y)
{
	destructible = dest;
	pos = { x, y };

	sprite = SDL_Rect{ pos.x * SCRIPT_SIZE, pos.y *  SCRIPT_SIZE + HUD_HEIGHT, SCRIPT_SIZE, SCRIPT_SIZE };

	if (destructible)
	{
		blocksPJ = true;
		rect = SDL_Rect{ SCRIPT_SIZE, 0, SCRIPT_SIZE, SCRIPT_SIZE };
	}
	else rect = SDL_Rect{ 0, 0, SCRIPT_SIZE, SCRIPT_SIZE };

	Renderer::Instance()->LoadTexture(ROLLER, PATH_IMG + "items.png");
}


Wall::~Wall()
{
}

void Wall::setup()
{

}

void Wall::draw()
{
	Renderer::Instance()->PushSprite(ROLLER, rect, sprite);
}

void Wall::update()
{
	//La idea es: 
	/*if bombContact && destructible


	al poco

	llamar destructor
	*/
}
