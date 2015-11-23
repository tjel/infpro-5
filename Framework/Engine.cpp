#include "Engine.h"
#include "INI_Parser.h"
#include "Renderer.h"
#include "GL/glu.h"


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
    if(ini_file.IsEmpty())
    {
        ini_file.AddValue("VIDEO","resolution_x","800");
        ini_file.AddValue("VIDEO","resolution_y","600");
        ini_file.AddValue("VIDEO","fullscreen","0");
        INI_Parser::SaveFile("config.ini",ini_file);
    }
}

void Engine::StartEngine()
{
    LoadConfigure();
    /*display_window = SDL_CreateWindow
            ("Framework_Test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
             std::stoi(ini_file.GetValue("VIDEO","resolution_x")),
             std::stoi(ini_file.GetValue("VIDEO","resolution_y")),
             SDL_WINDOW_OPENGL);*/
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

    while(true)
        Renderer::GetRenderer()->Render();
}
