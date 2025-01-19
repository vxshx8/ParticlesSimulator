#include "renderer.h"
#include "iostream"
#include "imgui_impl_sdlrenderer2.h"
#include "imgui_impl_sdl2.h"
renderer::renderer(const char* title,int width,int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "cannot init SDL2" << std::endl;
		return;
	}
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (!window) {
		std::cout << "cannot create window " << SDL_GetError() << std::endl;
		running = false;
		return;
	}
	WindowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!WindowRenderer) {
		std::cout << "cannot create renderer " << SDL_GetError() << std::endl;
		running = false;
		return;
	}
	running = true;
}


void renderer::haldleEvents(SDL_Event &e) {
	while (SDL_PollEvent(&e)) {
		ImGui_ImplSDL2_ProcessEvent(&e);
		if (e.type == SDL_QUIT) {
			running = false;
		}
	}
}

void renderer::update() {
	SDL_SetRenderDrawColor(WindowRenderer, 0, 0, 0, 255);
	SDL_RenderClear(WindowRenderer);

}

void renderer::close() {
	SDL_DestroyRenderer(WindowRenderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}