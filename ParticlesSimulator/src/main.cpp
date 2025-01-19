#include <SDL.h>
#include <imgui.h>
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include <iostream>
#include "particles.h"
#include <vector>
#include "renderer.h"


int main(int argc, char* argv[]) {

   
    renderer ren("ParticleSimulator", 800, 800);


    SDL_Renderer* Renderer = ren.WindowRenderer;
    particles p;
    bool isrunning = true;
    std::vector<Particle> part;
    SDL_Event event;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui_ImplSDL2_InitForSDLRenderer(ren.window, ren.WindowRenderer);
    ImGui_ImplSDLRenderer2_Init(ren.WindowRenderer);
    ImGui::StyleColorsDark();
   
    int countP;
    
    int initvalue = 2;
    int max = 100;
    int min = 1;


    while (ren.isrunning()) {
        
            ren.haldleEvents(event);
            
            ren.update();
            countP = initvalue;
           
            ImGui_ImplSDLRenderer2_NewFrame();
            ImGui_ImplSDL2_NewFrame();
            ImGui::NewFrame();
            ImGui::Begin("Particles Select");
            if(ImGui::SliderInt("Particles", &initvalue, min, max)) {
                if (part.size() < initvalue) {
                    while (part.size() < initvalue) {
                        part.push_back(p.CreateParticles(800, 800));
                    }

                }
                else {
                    p.ParticleRemove(part, initvalue);
                }
            }

            ImGui::End();
            ImGui::Render();

           

            for (auto& particle : part) {
                p.UpdateParticles(particle);
                p.Colision(part,particle);
            }
            
    

            for (const auto& particle : part) {
                p.RenderParticles(Renderer, particle);
            }

            ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(),ren.WindowRenderer);
            SDL_RenderPresent(ren.WindowRenderer);
            SDL_Delay(16);
    }
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
   
    ren.close();
    return 0;
}


