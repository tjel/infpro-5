#include "Engine.h"
#include "INI_Parser.h"
#include "Renderer.h"
#include "GL/glu.h"

#include <iostream>


Engine* Engine::instance=nullptr;

Engine::Engine()
{
}

Engine* Engine::GetEngine()
{
    if(!instance)
       instance = new Engine();
    return instance;
}

void Engine::LoadConfigure()
{
    ini_file=INI_Parser::ParsFile("config.ini");

    SDL_DisplayMode current;

    if(SDL_GetDesktopDisplayMode(0, &current)!=0)
        std::cout<<"Nie mozna odczytac rozdzielczosci"<<std::endl;
    else
    {
        std::cout<<"X = "<<current.w<<" Y = "<<current.h<<std::endl;
    }

    if(!ini_file.Exist("VIDEO", "resolution_x"))
    {
        std::cout<<"resolution_x nie istnieje"<<std::endl;
        ini_file.AddValue("VIDEO","resolution_x",std::to_string(current.w));
    }

    if(!ini_file.Exist("VIDEO", "resolution_y"))
    {
        std::cout<<"resolution_y nie istnieje"<<std::endl;
        ini_file.AddValue("VIDEO", "resolution_y", std::to_string(current.h));
    }

    if(!ini_file.Exist("VIDEO", "fullscreen"))
    {
        std::cout<<"fullscreen nie istnieje"<<std::endl;
        ini_file.AddValue("VIDEO", "fullscreen", "true");
    }

    INI_Parser::SaveFile("config.ini",ini_file);
}

void Engine::StartEngine()
{
    SDL_Init(SDL_INIT_VIDEO);
    LoadConfigure();
    /*display_window = SDL_CreateWindow
            ("Framework_Test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
             std::stoi(ini_file.GetValue("VIDEO","resolution_x")),
             std::stoi(ini_file.GetValue("VIDEO","resolution_y")),
             SDL_WINDOW_OPENGL);*/

    if(ini_file.GetValue("VIDEO","fullscreen")=="true")
        SDL_CreateWindowAndRenderer(
                std::stoi(ini_file.GetValue("VIDEO","resolution_x")),
                std::stoi(ini_file.GetValue("VIDEO","resolution_y")),
                SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN, &display_window,
                &Renderer::GetRenderer()->display_renderer);
    else if (ini_file.GetValue("VIDEO","fullscreen")=="false")
        SDL_CreateWindowAndRenderer(
                std::stoi(ini_file.GetValue("VIDEO","resolution_x")),
                std::stoi(ini_file.GetValue("VIDEO","resolution_y")),
                SDL_WINDOW_OPENGL, &display_window,
                &Renderer::GetRenderer()->display_renderer);

    glHint(GL_LINE_SMOOTH_HINT,true);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    SDL_GL_SetSwapInterval(1);

    SDL_Event event;

    bool run=true;

    while(run)
    {
        Renderer::GetRenderer()->Render();
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT || (event.type == SDL_KEYDOWN &&
                                                event.key.keysym.sym == SDLK_ESCAPE))
            {
                run=false;
            }
        }
    }

    SDL_DestroyWindow(display_window);
    SDL_DestroyRenderer(Renderer::GetRenderer()->display_renderer);
    SDL_Quit();
}
