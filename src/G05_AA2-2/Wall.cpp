#include "Wall.h"



Wall::Wall()
{
	WallPath = "../../res/img/items.png";
	Wall_ID = INDESTRUCTIBLE_WALL;
	Renderer::Instance()->LoadTexture(Wall_ID, WallPath);
	Renderer::Instance()->GetTextureSize(Wall_ID);
	frameWidth = textWidth / 3;
	frameHeight = textHeight / 2;
	Wall_Position.x = 0;
	Wall_Position.y = 0;
	Wall_Rect.x = frameWidth;
	Wall_Rect.y = 0;
	Wall_Position.h = 48;
	Wall_Rect.h = frameHeight;
	Wall_Position.w = 48;
	Wall_Rect.w = frameWidth;
}


Wall::~Wall()
{
}


void Wall::Update() {

}
void Wall::Draw(int i, int j) {
	Wall_Position.x = i;
	Wall_Position.y = j; 
	Renderer::Instance()->PushSprite(Wall_ID, Wall_Rect, Wall_Position);
}
