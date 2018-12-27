#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
class Game
{
public:
	Game();
	~Game();

	void init(const char * title, int x, int y, int w, int h, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	inline bool running() { return isRunning; }
private:
	bool isRunning;
	SDL_Window * window;
	SDL_Renderer * renderer;
};

