#include "Game.h"


int main(int, char*[]) {
	Game* GameManager = new Game();
	GameManager->LoopGame();
	return 0;
}