#include "Bombas.h"



Bombas::Bombas()
{
	BombasPath = "../../res/img/items.png";
	ExplosionPath = "../../res/img/explosion.png";
	Bombas_ID = BOMB;
	Explosion_ID = EXPLOSION;
	Renderer::Instance()->LoadTexture(Bombas_ID, BombasPath);
	Renderer::Instance()->LoadTexture(Explosion_ID, ExplosionPath);
	Renderer::Instance()->GetTextureSize(Bombas_ID);
	Renderer::Instance()->GetTextureSize(Explosion_ID);
	//BOMB
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
	//EXPLOSION
	Explosion_Position.x = 0;
	Explosion_Position.y = 0;
	Explosion_Rect.x = 0;
	Explosion_Rect.y = 0;
	Explosion_Position.h = 48;
	Explosion_Rect.h = frameHeight;
	Explosion_Position.w = 48;
	Explosion_Rect.w = frameWidth;
	lastTime = clock();
	timeDown = 3.;
	deltaTime = 0;
	explosion = false;
}


Bombas::~Bombas(){
}

void Bombas::Update() {
	if (timeDown > 0) {
		deltaTime = (clock() - lastTime);
		lastTime = clock();
		deltaTime /= CLOCKS_PER_SEC;
		timeDown -= deltaTime;
		std::cout << timeDown << std::endl;
	}
	if (timeDown <= 0) {
		std::cout<<"destruir bomba"<<std::endl;
		explosion = true;
		Renderer::Instance()->PushSprite(Explosion_ID, Explosion_Rect, Explosion_Position);
	}
}

void Bombas::Draw(int i, int j) {
	Bombas_Position.x = i;
	Bombas_Position.y = j;
	Renderer::Instance()->PushSprite(Bombas_ID, Bombas_Rect, Bombas_Position);
	Renderer::Instance()->PushSprite(Explosion_ID, Explosion_Rect, Explosion_Position);
	if (timeDown <= 0) {
		std::cout << "destruir bomba" << std::endl;
		explosion = true;
		Renderer::Instance()->PushSprite(Explosion_ID, Explosion_Rect, Explosion_Position);
	}	
}

