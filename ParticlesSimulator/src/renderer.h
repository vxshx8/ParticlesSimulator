#pragma once
#include <SDL.h>
class renderer {
public:
	SDL_Renderer* WindowRenderer; 
	SDL_Window* window;
	renderer(const char *title,int width,int height);
	void haldleEvents(SDL_Event &e);
	void update();
	void close();
	bool isrunning() { return running; }
	

private:
	bool running;

};