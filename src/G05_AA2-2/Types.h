#pragma once
#include <string>
#include <SDL.h>

	using Rect = struct  Rect{ int  x; int y; int w; int h; };

	using Color = struct Color { Uint8 r; Uint8 g; Uint8 b; Uint8 a; };
	
	struct Vector2 { int x; int y; };

	using Font = struct {
		std::string id;
		std::string path;
		int size;
	};

	using Text = struct {
		std::string id;
		std::string text;
		Color color;
		int w;
		int h;
	};

	struct TextB
	{
		SDL_Rect placeHolder;
		std::string path;
		std::string msg;
		int size;
	};

	enum class Key {UP, DOWN, LEFT, RIGHT, NONE};

	enum class GameState { PLAY, MENU, EXIT };

	enum class SceneState { RUNNING, GOTO, EXIT };
	


