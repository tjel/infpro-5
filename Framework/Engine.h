#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "INI_Data.h"

class Engine
{
public:
    static Engine* GetEngine();

    void LoadConfigure();
    void StartEngine();
    void SaveConfigure();

private:
    Engine();
    static Engine* instance;
    SDL_Window* display_window;

    INI_Data ini_file;
};

#endif // ENGINE_H
