#include "Bombas.h"



Bombas::Bombas(int i, int j)
{
	BombasPath = "../../res/img/items.png";
	Bombas_ID = BOMB;
	Renderer::Instance()->LoadTexture(Bombas_ID, BombasPath);
	Renderer::Instance()->GetTextureSize(Bombas_ID);
	frameWidth = textWidth / 3;
	frameHeight = textHeight / 4;
	Bombas_Position.x = i;
	Bombas_Position.y = j;
	Bombas_Rect.x = 0;
	Bombas_Rect.y = 0;
	Bombas_Position.h = 48;
	Bombas_Rect.h = frameHeight;
	Bombas_Position.w = 48;
	Bombas_Rect.w = frameWidth;
	timer = clock();
}


Bombas::~Bombas(){
}

void Bombas::Update() {
	//Mientras life span de bomba <= 0 push image bomba
	//Luego explosion de colores
	if (clock() - timer >= CLOCKS_PER_SEC * 3 ) { // 3 = segundos delay de la bomba
		Renderer::Instance()->PushSprite(Bombas_ID, Bombas_Rect, Bombas_Position);
	}
}

void Bombas::Draw() {
	Renderer::Instance()->PushSprite(Bombas_ID, Bombas_Rect, Bombas_Position);
}