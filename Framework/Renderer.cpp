#include "Renderer.h"
#include "Draw_Queue.h"

Renderer* Renderer::instance=nullptr;

Renderer::Renderer()
{

}

Renderer* Renderer::GetRenderer()
{
    if(!instance)
        instance=new Renderer();
    return instance;
}


void Renderer::Render()
{
    //Ustawienie koloru tła na czarny
    SDL_SetRenderDrawColor(display_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //czyszczenie renderu
    SDL_RenderClear(display_renderer);



    Draw_Queue::GetInstance()->DrawAll();
    SDL_RenderPresent(display_renderer);
    //return this;
}

