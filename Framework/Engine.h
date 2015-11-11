#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class Engine
{
public:
    static Engine* GetEngine();

    void LoadConfigure();
    void SetConfigure();
    void SaveConfigure();

private:
    Engine();
    SDL_Window* displayWindow;
    static Engine* instance;
};

#endif // ENGINE_H
