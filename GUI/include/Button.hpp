#ifndef BUTTON_H
#define BUTTON_H
#include "include/Widget.hpp"
#include "include/Gui.hpp"
#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_image.h"
#include<vector>
class Button : public Widget
{
public:
    Button(Gui & mGui);
    Button(Gui &mGui, Vector2i Position);
    Button(Gui & mGui, Vector2i Position,std::string Text);
    ~Button();
protected:
    void Init(Gui & mGui);
    void Creation_Text();
    void Creation_Element();
    virtual void handleEvent(SDL_Event * events);
    virtual void Draw();
private:
    SDL_Rect RectText;
    SDL_Point mElement;
    std::string mText;  //Nazwa Tekstu
    std::vector<SDL_Rect> mPositionTex; //Pozycja Textury Button w Black.png
    std::vector<SDL_Rect> mMiddleTex; //Srodek textury
    SDL_Texture * mSDLText;
    SDL_Surface* solid;
    int tryb;
    enum option {normal,clicked,hover};

};

#endif // BUTTON_H
