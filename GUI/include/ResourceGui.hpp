#ifndef RESOURCEGUI_H
#define RESOURCEGUI_H
#include <Vector/Rect.hpp>
#include <Vector/Vector3.h>
#include <memory>
#include <SDL2/SDL_rect.h>
class ResourceGui
{
public:
    ResourceGui(Vector3i Color);
    ResourceGui(IntRect Part);
    ResourceGui(IntRect Part,IntRect Middle);
    IntRect GetPart(){return mPart;}
    IntRect GetMiddle(){return mMiddle;}
    SDL_Rect GetSDLPart(){return SDLPart;}
    SDL_Rect GetSDLMiddle(){return SDLMiddle;}
    Vector3i GetColor(){return mColor;}
    ~ResourceGui();
private:
    IntRect mPart;
    IntRect mMiddle;
    SDL_Rect SDLPart;
    SDL_Rect SDLMiddle;
    Vector3i mColor;
};

#endif // RESOURCEGUI_H
