#include "Renderer.h"
#include "Draw_Queue.h"

Renderer* Renderer::singleton = nullptr;

Renderer::Renderer()
{
}

Renderer* Renderer::Get()
{
    if(!singleton)
        singleton = new Renderer();
    return singleton;
}

void Renderer::Render()
{
    // Ustawienie koloru tła na czarny
    SDL_SetRenderDrawColor(display_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    // czyszczenie renderu
    SDL_RenderClear(display_renderer);
    

    Draw_Queue::Get()->DrawAll();
    SDL_RenderPresent(display_renderer);
    // return this;
}
