#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class Renderer
{
public:
    static Renderer* Get();
    void Render();

    SDL_Renderer* display_renderer;

private:
    Renderer();
    static Renderer* singleton;
};

#endif // RENDERER_H
