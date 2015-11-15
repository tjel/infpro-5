#include "include/Button.hpp"
#include <iostream>
Button::Button(Gui & mGui):mText("Button")
{
    setPosition(0,0);
    Init(mGui);
    mGui.AddClassGui(GetPtr());
}
Button::Button(Gui &mGui, Vector2i Position):mText("Button")
{
    setPosition(Position);
    Init(mGui);
    mGui.AddClassGui(GetPtr());
}
Button::Button(Gui & mGui,Vector2i Position, std::string Text):mText(Text)
{
    setPosition(Position);
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
    Creation_Text();
    Creation_Element();
    setSize(temp.w,temp.h);

}
void Button::Draw()
{
     SDL_Rect temp = GetRect();
     //for(int i = 0;i<mElement.y;i++)Rysowanie
     //{
     //temp.y=temp.y+31;
     //}
     for(int j = 0;j<mElement.x;j++)
     {
          switch(tryb)
          {
          case normal:
          SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&mPositionTex[0],&temp);
          break;
          case hover:
          SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&mPositionTex[1],&temp);
          break;
          case clicked:
          SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&mPositionTex[2],&temp);
          break;
          }
          temp.x=temp.x+31;
     }
     SDL_RenderCopy(CRender::GetRender()->mRender,mSDLText,NULL,&RectText);


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
void Button::Creation_Text()
{
        SDL_Color textColor = { 190, 190, 190, 255 };
        solid = TTF_RenderText_Blended_Wrapped( ResourceManager::GetManagerResource()->GetFont(),mText.c_str(), textColor,5550 );
        mSDLText = SDL_CreateTextureFromSurface(CRender::GetRender()->mRender,solid);
        RectText.h = solid->h;
        RectText.w = solid->w;
        RectText.x = GetRect().x+31; // zeby tekst nie byl z pocztku Buttona to + 31 (jest to szerokosc jednej kafelki) \\as
        RectText.y = GetRect().y+6;
        SDL_FreeSurface(solid);

}
void Button::Creation_Element()
{
    int a =  RectText.w;
    int b =  RectText.h;

    int c = 31;
    int d = 45;

    for(int i = 0;i != -1;i++)//Nieskonczona petla
    {
       if(c * i >= a)
       {
           mElement.x = i+1;//ilosc kafelek do narysowania
           break;
       }
    }

    mElement.y = 1;//ilosc kafelek do narysowania


}
//Szukamy ile bede musial narysowac elemnetow Buttona zeby zmiescil sie w nim tekst.

Button::~Button()
{
    SDL_DestroyTexture(mSDLText);
}
