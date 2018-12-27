#include "Game.h"

SDL_Texture* playerTexture;
SDL_Rect destR;

Game::Game()
{
}


Game::~Game()
{
}

void Game::init(const char * title, int x, int y, int w, int h, bool fullScreen)
{
	int flag = 0;
	if (fullScreen) {
		flag = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "init subsystem successfully " << std::endl;
		window = SDL_CreateWindow(title, x, y, w, h, flag);
		if (window) {
			std::cout << "init window successfully " << std::endl;
		}
		else {
			std::cout << "init window failed " << std::endl;
			exit(0);
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			std::cout << "init renderer successfully " << std::endl;
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		else {
			std::cout << "init renderer failed " << std::endl;
			exit(0);
		}

		SDL_Surface * surface = IMG_Load("Assets/player.png");
		playerTexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);


		isRunning = true;
	}
	else {
		isRunning = true;
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	destR.h = 100;
	destR.w = 100;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTexture, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}