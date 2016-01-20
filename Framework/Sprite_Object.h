#ifndef SPRITE_OBJECT_H
#define SPRITE_OBJECT_H

#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <map>

#include "Drawable_Object.h"
//#include "RM.h"

class Sprite_Object : public Drawable_Object
{
public:
    Sprite_Object(std::string source_path, SDL_Rect _position);
    Sprite_Object();
    void AddAnimation(std::string name, std::vector<SDL_Rect> _frames);
    void SetAnimation(std::string name);
    virtual void Draw();

    void MoveUp(int value);
    void MoveDown(int value);
    void MoveRight(int value);
    void MoveLeft(int value);

    void SetAngle(unsigned _angle);
    void SetFlip(SDL_RendererFlip _flip);
    void SetCenter(SDL_Point _center);
    void SetPosition(SDL_Rect _position);
private:
    std::map<std::string, std::vector<SDL_Rect> > animations;
    SDL_Rect position;
    unsigned frame;
    std::string animation_name;
    std::string file_name;
    unsigned angle;
    SDL_RendererFlip flip;
    SDL_Point center;
};

#endif // SPRITE_OBJECT_H
