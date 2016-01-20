#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "INI_Data.h"

class Engine
{
public:
    static Engine* Get();

    void LoadConfigure();
    void StartEngine();
    void SaveConfigure();
    SDL_Window* GetSDL_Window();

private:
    Engine();
    static Engine* singleton;
    SDL_Window* display_window;
    
    void MainLoop();
    
    INI_Data ini_file;
};

#endif // ENGINE_H
