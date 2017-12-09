#include "Bombas.h"



Bombas::Bombas()
{
	BombasPath = "../../res/img/items.png";
	Bombas_ID = BOMB;
	Renderer::Instance()->LoadTexture(Bombas_ID, BombasPath);
	Renderer::Instance()->GetTextureSize(Bombas_ID);
	frameWidth = textWidth / 3;
	frameHeight = textHeight / 2;
	Bombas_Position.x = 0;
	Bombas_Position.y = 0;
	Bombas_Rect.x = 0;
	Bombas_Rect.y = frameHeight;
	Bombas_Position.h = 48;
	Bombas_Rect.h = frameHeight;
	Bombas_Position.w = 48;
	Bombas_Rect.w = frameWidth;
	lastTime = clock();
	timeDown = 3.;
	deltaTime = 0;
	explosion = false;
}


Bombas::~Bombas(){
}

void Bombas::Update() {
	//Mientras life span de bomba <= 0 push image bomba
	//Luego explosion de colores
	if (timeDown > 0) {
		deltaTime = (clock() - lastTime);
		lastTime = clock();
		deltaTime /= CLOCKS_PER_SEC;
		timeDown -= deltaTime;
		std::cout << timeDown << std::endl;
	}
	if (timeDown <= 0) {
		std::cout<<"destruir bomba"<<std::endl;
		Renderer::Instance()->PushSprite(Bombas_ID, Bombas_Rect, Bombas_Position);
		explosion = true;
	}
}

void Bombas::Draw(int i, int j) {
	Bombas_Position.x = i;
	Bombas_Position.y = j;
	Renderer::Instance()->PushSprite(Bombas_ID, Bombas_Rect, Bombas_Position);
}