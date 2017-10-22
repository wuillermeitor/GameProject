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
int cambio = 1;

int main(int, char*[]) {

	// --- INIT ---
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw "No es pot inicialitzar SDL subsystems";
	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
	if (!(IMG_Init(imgFlags) & imgFlags)) throw "Error: SDL_image init";
	if (TTF_Init() != 0)throw"nanai";

	const Uint8 mixFlags{ MIX_INIT_MP3 | MIX_INIT_OGG };
	if (!(Mix_Init(mixFlags) & mixFlags))throw"Error:SDL_mixer init";

	// --- WINDOW ---
	SDL_Window *window{ SDL_CreateWindow("Mini-Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN) };
	if (window == nullptr) throw "No es pot inicialitzar SDL_Window";

	// --- RENDERER ---
	SDL_Renderer *renderer{ SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) };
	if (renderer == nullptr) throw "No es pot inicialitzar SDL_Renderer";
	SDL_Texture *bgTexture{ IMG_LoadTexture(renderer, "../../res/img/bgCastle.jpg") };
	if (bgTexture == nullptr) throw "No s'han pogut crear les textures";
	SDL_Rect bgRect{ 0,0,1064, SCREEN_HEIGHT };


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

	// --- TEXT ---
	TTF_Font *font{ TTF_OpenFont("../../res/ttf/saiyan.ttf", 80) };
	if (font == nullptr)throw"no es pot inicialitzar ttf font";
	SDL_Surface *tmpSurf{ TTF_RenderText_Blended(font, "OMAE WA MO SHINDEIRU", SDL_Color{ 255, 0, 0, 255 }) };
	if (tmpSurf == nullptr)TTF_CloseFont(font), throw "Unable to create the sdl text surface";
	SDL_Texture *textTexture{ SDL_CreateTextureFromSurface(renderer, tmpSurf) };
	SDL_Rect textRect{ 50, 50, tmpSurf->w, tmpSurf->h };
	SDL_FreeSurface(tmpSurf);
	TTF_CloseFont(font);

	// --- AUDIO ---
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		throw "Unable o initialize SDL_mixer audio systems";
	}
	Mix_Music *soundtrack{ Mix_LoadMUS("../../res/au/mainTheme3.mp3") };
	if (!soundtrack) throw "Unable to load the Mix_Music soundtrack";
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	//Mix_PlayMusic(soundtrack, -1);

	// --- TIME ---
	/*
	clock_t lastTime = clock();
	float timeDown = 10.;
	float deltaTime = 0;
	*/

	// --- GAME LOOP ---
	SDL_Event event;
	bool isRunning = true;
	while (isRunning) {
		// HANDLE EVENTS
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:	isRunning = false; break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
				else if (event.key.keysym.sym == SDLK_d && PlayerPosition.x + PlayerPosition.w < SCREEN_WIDTH) {
					playerRect.y = frameHeight * 2;
					PlayerPosition.x += 10;
				}
				else if (event.key.keysym.sym == SDLK_a && PlayerPosition.x > 0) {
					playerRect.y = frameHeight;
					PlayerPosition.x -= 10;
				}
				else if (event.key.keysym.sym == SDLK_w && PlayerPosition.y > 170) {
					playerRect.y = frameHeight * 3;
					PlayerPosition.y -= 10;
				}
				else if (event.key.keysym.sym == SDLK_s && PlayerPosition.y + PlayerPosition.h < SCREEN_HEIGHT) {
					playerRect.y = frameHeight * 0;
					PlayerPosition.y += 10;
				}
				break;
			default:;
			}
		}

		// UPDATE
		/*
		deltaTime = (clock() - lastTime);
		lastTime = clock();
		deltaTime /= CLOCKS_PER_SEC;
		timeDown -= deltaTime;
		std::cout << timeDown << std::endl;
		*/

		frameTime++;
		if (FPS / frameTime <= 10) {
			frameTime = 0;
			if (playerRect.x == frameWidth*5)
				cambio = -1;
			else if (playerRect.x == frameWidth*3)
				cambio = 1;
			playerRect.x += frameWidth*cambio;

		}

		/*
		playerRect.x += (playerTarget.x - playerRect.x)/5;
		playerRect.y += (playerTarget.y - playerRect.y)/5;
		*/
		// DRAW
		//Background
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bgTexture, nullptr, &bgRect);
		//Animated Sprite
		SDL_RenderCopy(renderer, playerTexture, &playerRect, &PlayerPosition);

		SDL_RenderCopy(renderer, goldTexture, nullptr, &goldRect[0]);
		SDL_RenderCopy(renderer, goldTexture, nullptr, &goldRect[1]);
		SDL_RenderCopy(renderer, goldTexture, nullptr, &goldRect[2]);
		SDL_RenderCopy(renderer, goldTexture, nullptr, &goldRect[3]);
		SDL_RenderCopy(renderer, goldTexture, nullptr, &goldRect[4]);

		//SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

		SDL_RenderPresent(renderer);


	}

	// --- DESTROY ---
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(bgTexture);
	SDL_DestroyTexture(playerTexture);
	SDL_DestroyTexture(goldTexture);
	SDL_DestroyTexture(textTexture);

	// --- QUIT ---
	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
	Mix_CloseAudio();
	SDL_Quit();
	return 0;
}