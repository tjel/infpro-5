#include "texture.h"
#include <iostream>
#include "../Renderer.h"
#include <SDL2/SDL_image.h>

//SDL_Texture texture::file = NULL;

texture::texture()
{
}

texture::texture(std::string _file_name)
{
    //SDL_SetColorKey(temporary_surface, SDL_SRCCOLORKEY, SDL_MapRGB(picture->format, 0, 0, 255));
    file = IMG_LoadTexture(Renderer::Get()->display_renderer, _file_name.c_str());
    if(file == NULL)
    {
        std::cout<< "Nie udalo sie utworzyc textury\n";
    }

    //SDL_SetTextureBlendMode(file, SDL_BLENDMODE_NONE);
    //std::cout<<" texture color mode : "<<SDL_SetTextureColorMod(file,0,5,2)<<std::endl;
}
