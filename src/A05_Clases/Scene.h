#pragma once

enum SceneState { RUNNING, GOTO, EXIT };
enum CurrentScene { MENU, PLAY, EXIT };

class Scene
{
public:
	Scene();
	~Scene();
	SceneState scenestate;
	CurrentScene currentscene;
};