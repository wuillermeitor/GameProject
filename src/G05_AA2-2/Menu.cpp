#pragma once
#include "Menu.h"



Menu::Menu()
{
	//variables
	scenestate = SceneState::RUNNING;
	BG_ID = "BackGround";
	std::string BGPath = "../../res/img/bgGame.jpg";
	std::cout << BGPath << std::endl;
	Renderer::Instance()->LoadTexture(BG_ID, BGPath);
	Renderer::Instance()->PushImage(BG_ID, BG_Rect);
	Renderer::Instance()->Clear();
	Renderer::Instance()->Render();
}


Menu::~Menu()
{
}

void Menu::EventHandler() {
}

void Menu::Update() {
}

void Menu::Draw() {
}