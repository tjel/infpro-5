#include "Engine.h"
#include "INI_Parser.h"
#include "Renderer.h"
#include "GL/glu.h"
#include "Shape.h"
#include "Events_Manager.h"
#include "Sprite_Object.h"
#include "include/Events_Queue.h"

#include <iostream>

Engine* Engine::singleton = nullptr;

Engine::Engine()
{
}

Engine* Engine::Get()
{
    if(!singleton)
        singleton = new Engine();
    return singleton;
}

void Engine::LoadConfigure()
{
    ini_file = INI_Parser::ParsFile("config.ini");

    SDL_DisplayMode current;

    if(SDL_GetDesktopDisplayMode(0, &current) != 0)
        std::cout << "Nie mozna odczytac rozdzielczosci" << std::endl;
    else
    {
        std::cout << "X = " << current.w << " Y = " << current.h << std::endl;
    }

    if(!ini_file.Exist("VIDEO", "resolution_x"))
    {
        std::cout << "resolution_x nie istnieje" << std::endl;
        ini_file.AddValue("VIDEO", "resolution_x", std::to_string(800));
    }

    if(!ini_file.Exist("VIDEO", "resolution_y"))
    {
        std::cout << "resolution_y nie istnieje" << std::endl;
        ini_file.AddValue("VIDEO", "resolution_y", std::to_string(600));
    }

    if(!ini_file.Exist("VIDEO", "fullscreen"))
    {
        std::cout << "fullscreen nie istnieje" << std::endl;
        ini_file.AddValue("VIDEO", "fullscreen", "false");
    }

    if(!ini_file.Exist("VIDEO", "synchronizacja_pionowa"))
    {
        std::cout << "synchronizacja pionowa nie istenieje" << std::endl;
        ini_file.AddValue("VIDEO", "synchronizacja_pionowa", "true");
    }

    //INI_Parser::SaveFile("config.ini", ini_file);
}

void Engine::StartEngine()
{
    SDL_Init(SDL_INIT_VIDEO);
    LoadConfigure();

    if(ini_file.GetValue("VIDEO", "fullscreen") == "true")
        SDL_CreateWindowAndRenderer(std::stoi(ini_file.GetValue("VIDEO", "resolution_x")),
                                    std::stoi(ini_file.GetValue("VIDEO", "resolution_y")),
                                    SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN,
                                    &display_window, &Renderer::Get()->display_renderer);
    else if(ini_file.GetValue("VIDEO", "fullscreen") == "false")
        SDL_CreateWindowAndRenderer(std::stoi(ini_file.GetValue("VIDEO", "resolution_x")),
                                    std::stoi(ini_file.GetValue("VIDEO", "resolution_y")),
                                    SDL_WINDOW_OPENGL, &display_window,
                                    &Renderer::Get()->display_renderer);

    glHint(GL_LINE_SMOOTH_HINT, true);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    if(ini_file.GetValue("VIDEO", "synchronizacja_pionowa") == "true")
        SDL_GL_SetSwapInterval(1);

    MainLoop();

    SDL_DestroyWindow(display_window);
    SDL_DestroyRenderer(Renderer::Get()->display_renderer);
    SDL_Quit();
    INI_Parser::SaveFile("config.ini", ini_file);
}

void Engine::MainLoop()
{
    bool run = true;

    while(run)
    {
        Events_Manager::Get()->RefreshKeys();
        Events_Queue::Get()->Execute();
        Renderer::Get()->Render();

        if(Events_Manager::Get()->IsClicked(SDLK_ESCAPE))
        {
            run = false;
            std::cout << run << "\nWyjście ...\n";

        }
        //system("sleep 0.02");
    }

}
