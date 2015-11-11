#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


class Renderer
{
public:
    Renderer();
    Renderer* Render();

private:
    SDL_Renderer* display_renderer;
};

#endif // RENDERER_H
