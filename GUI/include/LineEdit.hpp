#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <include/Widget.hpp>
#include <include/Text.hpp>
#include <include/Gui.hpp>
#include <string>
#include <SDL2/SDL.h>
class LineEdit : public Widget
{
public:
    LineEdit(Gui & mGui, int x, int y, int w, int h);
    void handleEvent(SDL_Event * events);
    void Draw();

private:
    void Init(Gui & gui);
    Text * mText;
    std::vector<SDL_Rect> mPositionTex; //Pozycja Textury Button w Black.png
    std::vector<Vector3i> mColor; //Pozycja Textury Button w Black.
    enum Option {NORMAL,EDIT};
    void AddText(int index);
    void Create();
    bool OptionEdit;
    int ElementW = 0;
    int End = 0;
    int SizeW;
    short Index_Txt;
};

#endif // LINEEDIT_H
