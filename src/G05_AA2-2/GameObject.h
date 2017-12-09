#pragma once
#include <SDL.h>		
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include "Types.h"
#include "Renderer.h"

class GameObject
{
public:	
	std::string GameObject_ID, GameObjectPath;
	SDL_Rect GameObject_Rect, GameObject_Position;
	int frameWidth, frameHeight;
	int textWidth = 144;
	int textHeight = 96;

	GameObject();
	~GameObject();

	virtual void setup() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

};

