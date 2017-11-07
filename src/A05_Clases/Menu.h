#pragma once
#include "Renderer.h"
#include "Constants.h"
#include "Types.h"
#include <string.h>



class Menu {
public:
	Menu();

	void HandleEvent();
	void Update();
	void Draw();

	~Menu();
};