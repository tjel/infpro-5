#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <SDL2/SDL.h>

class texture
{
public:
    texture();
    texture(std::string _file_name);
    std::string file_name;
    SDL_Texture* file;
};

#endif // TEXTURE_H
