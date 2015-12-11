#include "include/Gui.hpp"

Gui::Gui(std::string FileName, std::string FileTexture):mNameFile(FileName),mFileTexture(FileTexture)
{

}
void Gui::AddClassGui(std::shared_ptr<Widget> Ptr)
{
    mContener.push_back(Ptr);
}
void Gui::Draw_Gui()
{
    for(int i = 0;i<mContener.size();i++)
    {
        // SDL_RenderCopy(CRender::GetRender()->mRender,this->mTexture,IntRect::RectToSDLRect(Date[i]->GetPosTex()[0]),IntRect::RectToSDLRect(Date[i]->GetRect()));
        mContener[i]->Draw();
    }
}
void Gui::Event_Gui()
{
    while( SDL_PollEvent( &event ) != 0 )
    {
        for(int i = 0;i<mContener.size();i++)
        {
            // SDL_RenderCopy(CRender::GetRender()->mRender,this->mTexture,IntRect::RectToSDLRect(Date[i]->GetPosTex()[0]),IntRect::RectToSDLRect(Date[i]->GetRect()));
            mContener[i]->handleEvent(&event);
        }
    }
}
