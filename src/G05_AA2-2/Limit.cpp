#include "Limit.h"



Limit::Limit()
{
	LimitPath = "../../res/img/items.png";
	Limit_ID = LIMIT;
	Renderer::Instance()->LoadTexture(Limit_ID, LimitPath);
	Renderer::Instance()->GetTextureSize(Limit_ID);
	frameWidth = textWidth / 3;
	frameHeight = textHeight / 2;
	Limit_Position.x = 0;
	Limit_Position.y = 0;
	Limit_Rect.x = 0;
	Limit_Rect.y = frameHeight;
	Limit_Position.h = 48;
	Limit_Rect.h = frameHeight;
	Limit_Position.w = 48;
	Limit_Rect.w = frameWidth;
}


Limit::~Limit()
{
}

void Limit::setup() {

}

void Limit::draw() {
	Renderer::Instance()->PushSprite(Limit_ID, Limit_Rect, Limit_Position);
}

void Limit::update() {

}