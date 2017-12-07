#pragma once
#include "Play.h"
#include "Renderer.h"


Play::Play() {
	scenestate = SceneState::RUNNING;
	BG_ID = "BackGround";
	std::string BGPath = "../../res/img/bgGame.jpg";
	Renderer::Instance()->LoadTexture(BG_ID, BGPath);
}


Play::~Play() {

}


void Play::EventHandler() {

}

void Play::Update() {
	Renderer::Instance()->Render();
	Renderer::Instance()->Clear();
}

void Play::Draw() {
	Renderer::Instance()->PushImage(BG_ID, BG_Rect);

}