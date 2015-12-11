#include "include/Button.hpp"
#include <iostream>
#include <QDebug>
#include <SDL2/SDL_opengl.h>
Button::Button(Gui & mGui)
{
    setPosition(0,0);
    Init(mGui);
    mGui.AddClassGui(GetPtr());
}
Button::Button(Gui &mGui, int x,int y)
{
    setPosition(x,y);
    mText = new Text();
    Init(mGui);
    mGui.AddClassGui(GetPtr());

}
Button::Button(Gui & mGui,int x,int y, std::string Txt)
{
    setPosition(x,y);
    mText = new Text(Txt,x,y);
    Init(mGui);
    mGui.AddClassGui(GetPtr());
}
void Button::Init(Gui & mGui)
{
    SDL_Rect temp = ResourceManager::GetManagerResource()->GetResource()["Button"]["NormalImage"]->GetSDLPart();
    mPositionTex.push_back(SDL_Rect(ResourceManager::GetManagerResource()->GetResource()["Button"]["NormalImage"]->GetSDLPart()));
    mPositionTex.push_back(SDL_Rect(ResourceManager::GetManagerResource()->GetResource()["Button"]["HoverImage"]->GetSDLPart()));
    mPositionTex.push_back(SDL_Rect(ResourceManager::GetManagerResource()->GetResource()["Button"]["DownImage"]->GetSDLPart()));
    mMiddleTex.push_back(SDL_Rect(ResourceManager::GetManagerResource()->GetResource()["Button"]["NormalImage"]->GetSDLMiddle()));
    mMiddleTex.push_back(SDL_Rect(ResourceManager::GetManagerResource()->GetResource()["Button"]["HoverImage"]->GetSDLMiddle()));
    mMiddleTex.push_back(SDL_Rect(ResourceManager::GetManagerResource()->GetResource()["Button"]["DownImage"]->GetSDLMiddle()));
    setSize(temp.w,temp.h);
    Calculating_Element();

}
void Button::handleEvent(SDL_Event *events)
{
    int x ,y;//nie bedzie tego tu potem
    SDL_GetMouseState( &x, &y );
    if( events->type == SDL_MOUSEMOTION )
    {

        if( ( x > GetPosition().x ) && ( x < GetPosition().x + 31 * mElement.x ) && ( y > GetPosition().y ) && ( y < GetPosition().y + GetSize().y ) )
        {
            tryb = hover;
        }
        else
        {
            tryb = normal;
        }
    }
    else if(events->type == SDL_MOUSEBUTTONDOWN || events->type == SDL_MOUSEMOTION )
    {
        if (events->button.button == SDL_BUTTON_LEFT && ( x > GetPosition().x ) && (GetPosition().x + 31 * mElement.x ) && ( y > GetPosition().y ) && ( y < GetPosition().y + GetSize().y ) )
        {
            tryb = clicked;
        }

    }
    else
    {
        if( ( x > GetPosition().x ) && ( x <  GetPosition().x + 31 * mElement.x ) && ( y > GetPosition().y ) && ( y < GetPosition().y + GetSize().y ) )
        {
            tryb = hover;
        }
        else
        {
            tryb = normal;
        }
    }
}
void Button::Calculating_Element()
{

}

void Button::Draw()
{
    int end = mElement.x-1;
    SDL_Rect Rect = GetRect();
    SDL_Rect TexPos = mPositionTex[0];
    for(int j = 0;j<mElement.x;j++)
    {
        switch(tryb)
        {
        case normal:
            SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&TexPos,&Rect);
            break;
        case hover:
            SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&mPositionTex[1],&Rect);
            break;
        case clicked:
            SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&mPositionTex[2],&Rect);
            break;
        }
    }
    mText->Draw();
}
Button::~Button()
{
    delete mText;
}
