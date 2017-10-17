#include <SDL.h>		// Always needs to be included for an SDL app
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

//Game general information
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int, char*[]) {

	// --- INIT ---
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) throw "No es pot inicialitzar SDL subsystems";
	const Uint8 imgFlags{ IMG_INIT_PNG | IMG_INIT_JPG };
	if (!(IMG_Init(imgFlags) & imgFlags)) throw "Error: SDL_image init";
	if (TTF_Init() != 0)throw"nanai";

	const Uint8 mixFlags{ MIX_INIT_MP3 | MIX_INIT_OGG };
	if (!(Mix_Init(mixFlags) & mixFlags))throw"Error:SDL_mixer init";

	// --- WINDOW ---
	SDL_Window *window{ SDL_CreateWindow("SDL...", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN) };
	if (window == nullptr) throw "No es pot inicialitzar SDL_Window";

	// --- RENDERER ---
	SDL_Renderer *renderer{ SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) };
	if (renderer == nullptr) throw "No es pot inicialitzar SDL_Renderer";
	SDL_Texture *bgTexture{ IMG_LoadTexture(renderer, "../../res/img/bg.jpg") };
	if (bgTexture == nullptr) throw "No s'han pogut crear les textures";
	SDL_Rect bgRect{ 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };

	SDL_Texture *playerTexture{ IMG_LoadTexture(renderer, "../../res/img/kintoun.png") };
	if (playerTexture == nullptr)throw"No s'han pogut crear les textures";
	SDL_Rect playerRect{ 0,0,350,189 };
	SDL_Rect playerTarget{ 0,0,100,100 };

	// --- SPRITES ---

		// --- Animated Sprite ---

	// --- TEXT ---
	TTF_Font *font{ TTF_OpenFont("../../res/ttf/saiyan.ttf", 80) };
	if (font == nullptr)throw"no es pot inicialitzar ttf font";
	SDL_Surface *tmpSurf{ TTF_RenderText_Blended(font, "OMAE WA MO SHINDEIRU", SDL_Color{244, 150, 0, 255}) };
	if (tmpSurf == nullptr)TTF_CloseFont(font), throw "Unable to create the sdl text surface";
	SDL_Texture *textTexture{ SDL_CreateTextureFromSurface(renderer, tmpSurf) };
	SDL_Rect textRect{50, 50, tmpSurf->w, tmpSurf->h };
	SDL_FreeSurface(tmpSurf);
	TTF_CloseFont(font);

	// --- AUDIO ---
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		throw"Unable o initialize SDL_mixer audio systems";
	}
	Mix_Music *soundtrack{ Mix_LoadMUS("../../res/au/mainTheme.mp3") };
	if (!soundtrack) throw "Unable to load the Mix_Music soundtrack";
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	Mix_PlayMusic(soundtrack, -1);

	// --- GAME LOOP ---
	SDL_Event event;
	bool isRunning = true;
	while (isRunning){
		// HANDLE EVENTS
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:		isRunning = false; break;
			case SDL_KEYDOWN:	if (event.key.keysym.sym == SDLK_ESCAPE) isRunning = false; break;
			case SDL_MOUSEMOTION:
				playerTarget.x = event.motion.x-50;
				playerTarget.y = event.motion.y-50;
				break;
			default:;
			}
		}

		// UPDATE
		playerRect.x += (playerTarget.x - playerRect.x) /10;
		playerRect.y += (playerTarget.y - playerRect.y) /10;
		// DRAW
			//Background
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bgTexture, nullptr, &bgRect);
			//Animated Sprite
		SDL_RenderCopy(renderer, playerTexture, nullptr, &playerRect);

		SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

		SDL_RenderPresent(renderer);


	}

	// --- DESTROY ---
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(bgTexture);
	SDL_DestroyTexture(playerTexture);
	SDL_DestroyTexture(textTexture);

	// --- QUIT ---
	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
	Mix_CloseAudio();
	Mix_Quit();
	SDL_Quit();
	return 0;
}