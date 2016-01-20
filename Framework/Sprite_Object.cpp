#include "Sprite_Object.h"
#include "Renderer.h"
#include "RM.h"

Sprite_Object::Sprite_Object(std::string source_path, SDL_Rect _position)
    : Drawable_Object()
{
    file_name = source_path;
    this->position = _position;
    frame = 0;
    animation_name = "default";
    angle = 0;
    center.x=0;
    center.y=0;
    flip =SDL_RendererFlip::SDL_FLIP_NONE;
}

Sprite_Object::Sprite_Object() : Drawable_Object()
{

}

void Sprite_Object::Draw()
{
    frame++;
    if(frame>=animations[animation_name].size())
        frame = 0;
    SDL_RenderCopyEx(Renderer::Get()->display_renderer, RM::Get()->GetTexture(file_name)->file,
                   &animations[animation_name][frame], &position, angle, &center, flip);
}

void Sprite_Object::AddAnimation(std::string name, std::vector<SDL_Rect> _frames)
{
    animations[name]=_frames;
}

void Sprite_Object::MoveDown(int value)
{
    position.y += value;
}

void Sprite_Object::MoveUp(int value)
{
    position.y -= value;
}

void Sprite_Object::MoveRight(int value)
{
    position.x+=value;
}

void Sprite_Object::MoveLeft(int value)
{
    position.x-=value;
}

void Sprite_Object::SetAngle(unsigned _angle)
{
    angle = _angle;
}

void Sprite_Object::SetFlip(SDL_RendererFlip _flip)
{
    flip = _flip;
}

void Sprite_Object::SetCenter(SDL_Point _center)
{
    center = _center;
}

void Sprite_Object::SetPosition(SDL_Rect _position)
{
    position = _position;
}
