#pragma once
#include <string>
#include <SDL.h>
#include "Constants.h"

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

	enum class casillas : char {
		DESTRUCTIBLE_WALL='w', INDESTRUCTIBLE_WALL = 'W', EMPTY = 'E', PLAYER1 = '1', PLAYER2 = '2', BOMB = 'B'
	};

	enum class Key {UP, DOWN, LEFT, RIGHT, NONE};

	enum class GameState { PLAY, MENU, RANKING, EXIT };

	enum class SceneState { RUNNING, GOTORANKING, GOTOLVL1, GOTOLVL2, GOTOMENU, EXIT };
	


