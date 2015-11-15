#include <include/CRender.hpp>
#include <include/Gui.hpp>
#include <include/Button.hpp>
int main()
{
    Gui gui("Black.txt","Black.png");
    Button * A = new Button(gui,Vector2i(10,100),"Borys");
    Button * C = new Button(gui,Vector2i(250,300),"NOWA GRA");
    while(1)
    {
        gui.Event_Gui();
        gui.Draw_Gui();
        SDL_RenderPresent(CRender::GetRender()->mRender);
        SDL_RenderClear(CRender::GetRender()->mRender);
    }
    SDL_Quit();
    delete C;
}
