#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <include/Widget.hpp>
#include <include/Text.hpp>
#include <include/Gui.hpp>
#include <vector>
#include <Vector/Vector3.h>
class CheckBox : public Widget
{
public:
    CheckBox(Gui & mGui);
    CheckBox(Gui & mGui, int x, int y, std::string Txt);
    void handleEvent(SDL_Event * events);
    void Draw();
private:
    Text * mText;
    void Init(Gui & gui);
    enum option {normal,clicked,hover_normal,hover_clicked};
    std::vector<SDL_Rect> mPositionTex; //Pozycja Textury Button w Black.png
    std::vector<Vector3i> mColor; //Pozycja Textury Button w Black.
    int x;
    int y; //Pozycja myszy;
};

#endif // CHECKBOX_H
