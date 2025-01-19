#pragma once
#include <SDL.h>
#include <vector>


struct Particle {
	SDL_Rect position;
	float vx, vy;
	Uint8 r, g, b, a;
};

class particles {
public:
	int count;
	SDL_Window* window;
	SDL_Renderer* renderer;
	particles();
	void UpdateParticles(Particle& p);
	Particle CreateParticles(int winH,int winW);
	void RenderParticles(SDL_Renderer*ren, const Particle& part);
	void Colision(std::vector<Particle>& p, Particle& a);
	void ParticleRemove(std::vector<Particle> &p, int SlideValue);
private:
	int particleCount;
};