#ifndef GUI_H
#define GUI_H
#include<vector>
#include<memory>
#include<include/Widget.hpp>
#include<SDL2/SDL_events.h>
class Gui
{
public:
    Gui(std::string FileName,std::string FileTexture);
    void AddClassGui(std::shared_ptr<Widget> Ptr);
    std::vector<std::shared_ptr<Widget> > GetContener;
    void Draw_Gui();
    void Event_Gui();
private:
    const std::string mNameFile;
    const std::string mFileTexture;
    std::vector<std::shared_ptr<Widget> > mContener;
    SDL_Event event;
};

#endif // GUI_H
///////ID///////
//1 = Button//
