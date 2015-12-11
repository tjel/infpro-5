#include <include/CRender.hpp>
#include <include/Gui.hpp>
#include <include/Button.hpp>
#include <include/CheckBox.hpp>
#include <include/RadioButton.hpp>
#include <include/LineEdit.hpp>
int main()
{
    Gui gui("Black.txt","Black.png");
    CheckBox* Checkbox = new CheckBox(gui,100,200,"CheckBox1");
    RadioButton * radio = new RadioButton(gui,100,100,"RadioButton");
    LineEdit * Edit = new LineEdit(gui,100,300,175,50);
    LineEdit * Edit_a = new LineEdit(gui,300,200,100,100);
    while(1)
    {

        gui.Event_Gui();
        gui.Draw_Gui();

        SDL_SetRenderDrawColor(CRender::GetRender()->mRender,255, 0, 0, 255);
        SDL_GL_SwapWindow(CRender::GetRender()->mWin);
        SDL_RenderClear(CRender::GetRender()->mRender);
    }
    SDL_Quit();
    delete Checkbox,radio,Edit;
}
