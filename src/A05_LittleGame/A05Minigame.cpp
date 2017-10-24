#include <SDL.h>		// Always needs to be included for an SDL app
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <time.h>
#include <vector>

//Game general information
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FPS 60
int cambiop1 = 1;
int cambiop2 = 1;
enum class GameState { PLAY, EXIT, MENU };
GameState gamestat = GameState::MENU;
int mouse_x, mouse_y;
int player1Counter = 0;
int player2Counter = 0;

void mainMenu(SDL_Window *window, SDL_Renderer *renderer) {

	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
	if (!(IMG_Init(imgFlags) & imgFlags)) throw "Error: SDL_image init";
	if (TTF_Init() != 0)throw"nanai";

	const Uint8 mixFlags{ MIX_INIT_MP3 | MIX_INIT_OGG };
	if (!(Mix_Init(mixFlags) & mixFlags))throw"Error:SDL_mixer init";

	SDL_Texture *bgTexture{ IMG_LoadTexture(renderer, "../../res/img/bg.jpg") };
	if (bgTexture == nullptr) throw "No s'han pogut crear les textures";
	SDL_Rect bgRect{ 0,0,1064, SCREEN_HEIGHT };

	// --- TEXT ---
	TTF_Font *font{ TTF_OpenFont("../../res/ttf/MarioLuigi2.ttf", 70) };
	if (font == nullptr)throw"no es pot inicialitzar ttf font";
	//PLAY
	SDL_Surface *tmpSurfPLAY{ TTF_RenderText_Blended(font, "PLAY", SDL_Color{ 0, 255, 0, 255 }) };
	if (tmpSurfPLAY == nullptr)TTF_CloseFont(font), throw "Unable to create the sdl text surface";
	SDL_Texture *textoTexture{ SDL_CreateTextureFromSurface(renderer, tmpSurfPLAY) };
	SDL_Rect textoRect{ 300,  200, tmpSurfPLAY->w, tmpSurfPLAY->h };
	SDL_FreeSurface(tmpSurfPLAY);

	TTF_CloseFont(font);


	// --- GAME LOOP ---
	SDL_Event menuevent;
	while (gamestat == GameState::MENU) {
		// HANDLE EVENTS
			while (SDL_PollEvent(&menuevent)) {
				switch (menuevent.type) {
				case SDL_MOUSEBUTTONDOWN:
					if (menuevent.button.button == SDL_BUTTON_LEFT)
					{
						mouse_x = menuevent.button.x;
						mouse_y = menuevent.button.y;
						if ((mouse_x >= textoRect.x) && (mouse_y >= textoRect.y) && (mouse_x <= textoRect.x+ textoRect.w) && (mouse_y <= textoRect.y+ textoRect.h))
						{
							std::cout << "has hecho click" << std::endl;
							gamestat = GameState::PLAY;
						}
					}
				}
			}

		// DRAW
		//Background
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bgTexture, nullptr, &bgRect);
		//Animated Sprite
		SDL_RenderCopy(renderer, textoTexture, nullptr, &textoRect);

		SDL_RenderPresent(renderer);
	}

	// --- DESTROY ---
	SDL_DestroyTexture(bgTexture);
	SDL_DestroyTexture(textoTexture);
}

void game(SDL_Window *window, SDL_Renderer *renderer) {
	srand(time(NULL));

	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
	if (!(IMG_Init(imgFlags) & imgFlags)) throw "Error: SDL_image init";
	if (TTF_Init() != 0)throw"nanai";

	const Uint8 mixFlags{ MIX_INIT_MP3 | MIX_INIT_OGG };
	if (!(Mix_Init(mixFlags) & mixFlags))throw"Error:SDL_mixer init";

	SDL_Texture *bgGTexture{ IMG_LoadTexture(renderer, "../../res/img/bgCastle.jpg") };
	if (bgGTexture == nullptr) throw "No s'han pogut crear les textures";
	SDL_Rect bgGRect{ 0,0,1064, SCREEN_HEIGHT};

	// --- SPRITES ---
	SDL_Texture *goldTexture{ IMG_LoadTexture(renderer, "../../res/img/gold.png") };
	if (goldTexture == nullptr)throw "No s'han pogut crear les textures";
	std::vector<SDL_Rect>goldRect;
	goldRect.push_back({ 300,400,75,56 });
	goldRect.push_back({ 250,500,75,56 });
	goldRect.push_back({ 700,300,75,56 });
	goldRect.push_back({ 500,150,75,56 });
	goldRect.push_back({ 100,200,75,56 });

	// --- Animated Sprite ---
	SDL_Texture *playerTexture{ IMG_LoadTexture(renderer, "../../res/img/spCastle.png") };
	//Player 1
	SDL_Rect playerRect, PlayerPosition;
	int textWidth, textHeight, frameWidth, frameHeight;
	SDL_QueryTexture(playerTexture, NULL, NULL, &textWidth, &textHeight);
	frameWidth = textWidth / 12;
	frameHeight = textHeight / 8;
	PlayerPosition.x = 200;
	PlayerPosition.y = 300;
	playerRect.x = frameWidth * 3;
	playerRect.y = 0;
	PlayerPosition.h = 100;
	playerRect.h = frameHeight;
	PlayerPosition.w = 100;
	playerRect.w = frameWidth;
	int frameTime = 0;
	//Player 2
	SDL_Rect player2Rect, Player2Position;
	Player2Position.x = 400;
	Player2Position.y = 300;
	player2Rect.x = frameWidth * 9;
	player2Rect.y = frameHeight * 4;
	Player2Position.h = 100;
	player2Rect.h = frameHeight;
	Player2Position.w = 100;
	player2Rect.w = frameWidth;

	// --- TEXT ---
	//player 1
	TTF_Font *font{ TTF_OpenFont("../../res/ttf/MarioLuigi2.ttf", 20) };
	if (font == nullptr)throw"no es pot inicialitzar ttf font";
	SDL_Surface *tmpSurf{ TTF_RenderText_Blended(font, "Pl 1:", SDL_Color{ 255, 0, 0, 255 }) };
	if (tmpSurf == nullptr)TTF_CloseFont(font), throw "Unable to create the sdl text surface";
	SDL_Texture *textoTexture{ SDL_CreateTextureFromSurface(renderer, tmpSurf) };
	SDL_Rect textoRect{ 20, 20, tmpSurf->w, tmpSurf->h };
	SDL_FreeSurface(tmpSurf);
	TTF_CloseFont(font);
	//player 2
	TTF_Font *font2{ TTF_OpenFont("../../res/ttf/MarioLuigi2.ttf", 20) };
	if (font2 == nullptr)throw"no es pot inicialitzar ttf font";
	SDL_Surface *tmp2Surf{ TTF_RenderText_Blended(font, "Pl 2:", SDL_Color{ 255, 0, 0, 255 }) };
	if (tmp2Surf == nullptr)TTF_CloseFont(font2), throw "Unable to create the sdl text surface";
	SDL_Texture *texto2Texture{ SDL_CreateTextureFromSurface(renderer, tmp2Surf) };
	SDL_Rect texto2Rect{ 20, 50, tmp2Surf->w, tmp2Surf->h };
	SDL_FreeSurface(tmp2Surf);
	TTF_CloseFont(font2);

	// --- AUDIO ---
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		throw "Unable o initialize SDL_mixer audio systems";
	}
	Mix_Music *soundtrack{ Mix_LoadMUS("../../res/au/mainTheme3.mp3") };
	if (!soundtrack) throw "Unable to load the Mix_Music soundtrack";
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	Mix_PlayMusic(soundtrack, -1);

	// --- TIME ---
	clock_t lastTime = clock();
	float timeDown = 30.;
	float deltaTime = 0;

	// --- GAME LOOP ---
	SDL_Event event;
	while (gamestat == GameState::PLAY) {
		const Uint8 *keyboardstate = SDL_GetKeyboardState(NULL);
		//Player 1
		if (keyboardstate[SDL_SCANCODE_D] && PlayerPosition.x + PlayerPosition.w < SCREEN_WIDTH) {
			playerRect.y = frameHeight * 2;
			PlayerPosition.x += 10;
		}
		else if (keyboardstate[SDL_SCANCODE_A] && PlayerPosition.x > 0) {
			playerRect.y = frameHeight;
			PlayerPosition.x -= 10;
		}
		if (keyboardstate[SDL_SCANCODE_W] && PlayerPosition.y > 130) {
			playerRect.y = frameHeight * 3;
			PlayerPosition.y -= 10;
		}
		else if (keyboardstate[SDL_SCANCODE_S] && PlayerPosition.y + PlayerPosition.h < SCREEN_HEIGHT) {
			playerRect.y = frameHeight * 0;
			PlayerPosition.y += 10;
		}
		//Player 2
		if (keyboardstate[SDL_SCANCODE_RIGHT] && Player2Position.x + Player2Position.w < SCREEN_WIDTH) {
			player2Rect.y = frameHeight * 6;
			Player2Position.x += 10;
		}
		else if (keyboardstate[SDL_SCANCODE_LEFT] && Player2Position.x > 0) {
			player2Rect.y = frameHeight * 5;
			Player2Position.x -= 10;
		}
		if (keyboardstate[SDL_SCANCODE_UP] && Player2Position.y > 130) {
			player2Rect.y = frameHeight * 7;
			Player2Position.y -= 10;
		}
		else if (keyboardstate[SDL_SCANCODE_DOWN] && Player2Position.y + Player2Position.h < SCREEN_HEIGHT) {
			player2Rect.y = frameHeight * 4;
			Player2Position.y += 10;
		}
			// HANDLE EVENTS
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_KEYDOWN:
					break;
				default:;
				}
		}

		// UPDATE
		for (int i = 0; i < goldRect.size(); i++) {
			if (goldRect[i].x + goldRect[i].w / 2 >= PlayerPosition.x && goldRect[i].y + goldRect[i].h / 2 >= PlayerPosition.y && goldRect[i].x + goldRect[i].w / 2 <= PlayerPosition.x + PlayerPosition.w && goldRect[i].y + goldRect[i].h / 2 <= PlayerPosition.y + PlayerPosition.h) {
				player1Counter++;
				std::cout << player1Counter << std::endl;
				goldRect[i].x = 70 + rand() % (SCREEN_WIDTH - 70 - 70);
				goldRect[i].y = 180 + rand() % (SCREEN_HEIGHT - 70 - 180);
			}
			if (goldRect[i].x + goldRect[i].w / 2 >= Player2Position.x && goldRect[i].y + goldRect[i].h / 2 >= Player2Position.y && goldRect[i].x + goldRect[i].w / 2 <= Player2Position.x + Player2Position.w && goldRect[i].y + goldRect[i].h / 2 <= Player2Position.y + Player2Position.h) {
				player2Counter++;
				std::cout << player2Counter << std::endl;
				goldRect[i].x = 70 + rand() % (SCREEN_WIDTH - 70 - 70);
				goldRect[i].y = 180 + rand() % (SCREEN_HEIGHT - 70 - 180);
			}
		}
		if (timeDown > 0) {
			deltaTime = (clock() - lastTime);
			lastTime = clock();
			deltaTime /= CLOCKS_PER_SEC;
			timeDown -= deltaTime;
			std::cout << timeDown << std::endl;
		}
		else {
			int x;
			gamestat=GameState::EXIT;
			if (player1Counter > player2Counter) {
				std::cout << "ha ganado player 1" << std::endl;
			}
			else if (player1Counter < player2Counter) {
				std::cout << "ha ganado player 2" << std::endl;
			}
			else {
				std::cout << "Habeis empatado" << std::endl;
			}
			std::cout << "Pulsa 0 para salir" << std::endl;
			std::cin >> x;
		}

		frameTime++;
		if (FPS / frameTime <= 10) {
			frameTime = 0;
			//player 1
			if (playerRect.x == frameWidth * 5)
				cambiop1 = -1;
			else if (playerRect.x == frameWidth * 3)
				cambiop1 = 1;
			playerRect.x += frameWidth*cambiop1;
			//player 2
			if (player2Rect.x == frameWidth * 11)
				cambiop2 = -1;
			else if (player2Rect.x == frameWidth * 9)
				cambiop2 = 1;
			player2Rect.x += frameWidth*cambiop2;

		}

		// DRAW
		//Background
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bgGTexture, nullptr, &bgGRect);
		//Animated Sprite
		//player 1
		SDL_RenderCopy(renderer, playerTexture, &playerRect, &PlayerPosition);
		//player 2
		SDL_RenderCopy(renderer, playerTexture, &player2Rect, &Player2Position);

		SDL_RenderCopy(renderer, goldTexture, nullptr, &goldRect[0]);
		SDL_RenderCopy(renderer, goldTexture, nullptr, &goldRect[1]);
		SDL_RenderCopy(renderer, goldTexture, nullptr, &goldRect[2]);
		SDL_RenderCopy(renderer, goldTexture, nullptr, &goldRect[3]);
		SDL_RenderCopy(renderer, goldTexture, nullptr, &goldRect[4]);

		SDL_RenderCopy(renderer, textoTexture, nullptr, &textoRect);
		SDL_RenderCopy(renderer, texto2Texture, nullptr, &texto2Rect);

		SDL_RenderPresent(renderer);
	}

	// --- DESTROY ---
	SDL_DestroyTexture(bgGTexture);
	SDL_DestroyTexture(playerTexture);
	SDL_DestroyTexture(goldTexture);
	SDL_DestroyTexture(textoTexture);
	SDL_DestroyTexture(texto2Texture);
}

int main(int, char*[]) {
	// --- INIT ---
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw "No es pot inicialitzar SDL subsystems";

	// --- WINDOW ---
	SDL_Window *window{ SDL_CreateWindow("Mini-Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN) };
	if (window == nullptr) throw "No es pot inicialitzar SDL_Window";

	// --- RENDERER ---
	SDL_Renderer *renderer{ SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) };
	if (renderer == nullptr) throw "No es pot inicialitzar SDL_Renderer";


	SDL_Event gamevent;
	while(gamestat != GameState::EXIT){
		while (SDL_PollEvent(&gamevent)) {
			switch (gamestat) {
			case GameState::MENU:
				mainMenu(window, renderer);
				break;
			case GameState::PLAY:
				game(window, renderer);
				break;
			case GameState::EXIT:
				break;
			}
		}

	}
	// --- DESTROY ---
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	// --- QUIT ---
	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
	return 0;
}