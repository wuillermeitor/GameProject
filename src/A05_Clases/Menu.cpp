#include <iostream>
#include "Menu.h"


Menu::Menu() {
	Renderer::Instance()->LoadTexture(MENU_BG, PATH_IMG + "bg.jpg");


}

Menu::~Menu() {
}


void Menu::HandleEvent() {
	SDL_Event MenuEvent;
	/*
	while (SDL_PollEvent(&MenuEvent)) {
		switch (MenuEvent.type) {
		case SDL_MOUSEBUTTONDOWN:
			if (MenuEvent.button.button == SDL_BUTTON_LEFT)
			{
				mouse_x = MenuEvent.button.x;
				mouse_y = MenuEvent.button.y;
				if ((mouse_x >= textoRect.x) && (mouse_y >= textoRect.y) && (mouse_x <= textoRect.x + textoRect.w) && (mouse_y <= textoRect.y + textoRect.h))
				{
					std::cout << "has hecho click" << std::endl;
					gamestat = GameState::PLAY;
				}
			}
		}
	}
	*/
}

void Menu::Update() {
	
}

void Menu::Draw() {
	
	Renderer::Instance()->Clear();
	
	Renderer::Instance()->PushImage(MENU_BG, { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });

	Renderer::Instance()->Render();

}