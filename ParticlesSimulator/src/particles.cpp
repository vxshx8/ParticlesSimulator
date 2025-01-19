#include "particles.h"


particles::particles() {
	
}

Particle particles::CreateParticles(int winH, int winW) {
	Particle p;
	p.position.x = rand() % winH ;
	p.position.y = rand() % winW;
	p.position.h = 10;
	p.position.w = 10;
	p.vx = (rand() % 100) / 10.0f; 
	p.vy = (rand() % 100) / 10.0f;
	p.r = rand() % 256;
	p.g = rand() % 256;
	p.b = rand() % 256;
	p.a = 255;
	particleCount++;
	return p;
};


void particles::UpdateParticles(Particle& p) {
	p.position.x += p.vx;
	p.position.y += p.vy;
}

void particles::RenderParticles(SDL_Renderer* renderer, const Particle& p) {
	SDL_SetRenderDrawColor(renderer, p.r, p.g, p.b, p.a);
	SDL_RenderFillRect(renderer, &p.position);
}

void particles::Colision(std::vector<Particle>& p, Particle& a) {
 
    for (const auto& partvec : p) {
       
        if (&a == &partvec) continue;

       
      
        if (SDL_HasIntersection(&a.position, &partvec.position)) {
            a.vx = -a.vx;
            a.vy = -a.vy;
            return;
        }
    }

    if (a.position.x <= 0 || a.position.x + a.position.w >= 800) {
        a.vx = -a.vx;
    }
    if (a.position.y <= 0 || a.position.y + a.position.h >= 800) {
        a.vy = -a.vy;
    }
}

void particles::ParticleRemove(std::vector<Particle>&p, int ParticleQtd) {
	if (p.size() > ParticleQtd) {
			p.erase(p.begin() + ParticleQtd, p.end());
		
	}
}

