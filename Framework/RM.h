#ifndef RM_H
#define RM_H

#include <string>
#include "Data/texture.h"
#include "Data/sound.h"

class RM
{
public:
    static RM* GetRM();

    texture* LoadTexture(std::string path);
    sound* LoadSound(std::string path);

private:
    RM();
    static RM* instance;
};

#endif // RM_H
