#ifndef BUTTON_H
#define BUTTON_H
#include "include/Widget.hpp"
#include  "include/Text.hpp"
#include "include/Gui.hpp"
#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_opengl.h>
#include <vector>
class Button : public Widget
{
public:
    Button(Gui & mGui);
    Button(Gui & mGui, int x, int y);
    Button(Gui & mGui, int x, int y, std::string Txt);
    ~Button();
protected:
    void Init(Gui & mGui);
    void Creation_Text();
    void Calculating_Element();
    virtual void handleEvent(SDL_Event * events);
    virtual void Draw();
private:
    std::vector<SDL_Rect> mPositionTex; //Pozycja Textury Button w Black.png
    std::vector<SDL_Rect> mMiddleTex; //Srodek textury
    enum option {normal,clicked,hover};
    SDL_Point mElement;
    int mDifference;
    Text * mText;
    int tryb;



};

#endif // BUTTON_H
