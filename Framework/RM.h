#ifndef RM_H
#define RM_H

#include <string>
#include <map>

#include "Data/texture.h"
#include "Data/sound.h"
#include "Sprite_Object.h"
#include "Shape.h"


class RM
{
public:
    static RM* Get();

    void LoadTexture(std::string path);
    void LoadSound(std::string path);

    texture* GetTexture(std::string file_name);
    sound* GetSound(std::string file_name);

    void SaveSpriteObject(Sprite_Object _sprite, std::string file_name);
    void SaveShape(Shape *_shape, std::string file_name);

    Sprite_Object LoadSpriteObject(std::string file_name);
    Shape* LoadShape(std::string file_name);

private:
    RM();
    static RM* singleton;
    std::map<std::string, texture*> textures;
    std::map<std::string, sound*> sounds;
};

#endif // RM_H
