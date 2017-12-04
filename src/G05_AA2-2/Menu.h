#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Types.h"
#include <iostream>


class Menu : public Scene {

private:
	//variables
public:
	Menu();
	~Menu();

	void EventHandler();
	void Update();
	void Draw();



};

