#pragma once
#include "Scene.h"


Scene::Scene() {
	scenestate = SceneState::RUNNING;
}


Scene::~Scene() {
}


SceneState Scene::getState() {
	return scenestate;
}