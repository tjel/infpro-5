#include "RM.h"
#include <fstream>

RM* RM::singleton = nullptr;

RM::RM()
{
}

RM* RM::Get()
{
    if(singleton==nullptr)
        singleton = new RM();

    return singleton;
}

texture* RM::GetTexture(std::string file_name)
{
    if(textures.find(file_name)==textures.end())
    {
        textures[file_name] = new texture(file_name);
    }
    return textures[file_name];
}

void RM::LoadTexture(std::string path)
{
    textures[path] = new texture(path);
}

void RM::SaveShape(Shape *_shape, std::string file_name)
{
    std::fstream file(file_name.c_str(), std::ios::binary | std::ios::out);
    file.write((char*)_shape, sizeof(Shape));
    file.close();
}

void RM::SaveSpriteObject(Sprite_Object _sprite, std::string file_name)
{
    std::fstream file(file_name.c_str(), std::ios::binary | std::ios::out | std::ios::app);
    file.write(reinterpret_cast<const char*>(&_sprite), sizeof(_sprite));
    file.close();
}

Sprite_Object RM::LoadSpriteObject(std::string file_name)
{

}
