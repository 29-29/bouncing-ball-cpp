#include <stdio.h>
#include <SDL.h>

#include "Circle.h"

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600
#define FRAME_RATE 60

#define COLOR_BACKGROUND 0x0f0f0f0f

int
main (int argc, char *args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		printf("Failed to initialize SDL!\nSDL Error: '%s'\n", SDL_GetError());
	}

	SDL_Window* window = SDL_CreateWindow(
		"Bouncing ball", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		SCREEN_WIDTH, SCREEN_HEIGHT, 
		SDL_WINDOW_BORDERLESS);
	if (!window) {
		printf("Failed to create window!\nSDL Error: '%s'\n", SDL_GetError());
		return 1;
	}

//	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, NULL);
//	if (!renderer) {
//		printf("Failed to create renderer!\nSDL Error: '%s'\n", SDL_GetError());
//	}

	SDL_Surface* surface = SDL_GetWindowSurface(window);
	if (!surface) {
		printf("Failed to get surface!\nSDL Error: '%s'\n", SDL_GetError());
	}

	/* SETUP */
	bool running = true;
	Circle circle = Circle(450, 300, 50);

	/* EVERY FRAME */
	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
					break;
				}

			default:
				break;
			}
		}

		// other renderings here
		SDL_Rect background = SDL_Rect{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
		SDL_FillRect(surface, &background, COLOR_BACKGROUND);
		circle.update(SCREEN_WIDTH, SCREEN_HEIGHT);
		circle.draw(surface);
		SDL_UpdateWindowSurface(window);

		/* frame_rate */
		SDL_Delay(1000 / FRAME_RATE);
	}
	return 0;
}
