#include "include/LineEdit.hpp"
#include <QDebug>
LineEdit::LineEdit(Gui & mGui, int x, int y,int w,int h)
{
    Init(mGui);
    setPosition(x,y);
    SizeW = w;
    mText = new Text("Edit",x,y);
    mGui.AddClassGui(GetPtr());
    Create();
    Index_Txt = mText->GetString().length();
}
void LineEdit::Init(Gui &gui)
{
    SDL_Rect temp = ResourceManager::GetManagerResource()->GetResource()["EditBox"]["NormalImage"]->GetSDLPart();
    mPositionTex.push_back(SDL_Rect(ResourceManager::GetManagerResource()->GetResource()["EditBox"]["NormalImage"]->GetSDLPart()));
    mPositionTex.push_back(SDL_Rect(ResourceManager::GetManagerResource()->GetResource()["EditBox"]["HoverImage"]->GetSDLPart()));
    setSize(temp.w,temp.h);

}
void LineEdit::Create()
{
    int a = 0;
    int b = 0;
    SDL_Rect temp = ResourceManager::GetManagerResource()->GetResource()["EditBox"]["NormalImage"]->GetSDLPart();
    for(int i = 1;i<100;i++)
    {
        a = GetSize().x-10 + (i * (GetSize().x - 2 *10)) + GetSize().x-10 ;
        if(a >= SizeW)
        {
            ElementW = i;
            End = a - SizeW;
            break;
        }
    }
}

void LineEdit::handleEvent(SDL_Event *events)
{
    int x ,y;//nie bedzie tego tu potem
    SDL_GetMouseState( &x, &y );
    //Obsluga Eventu myszy//
    if(events->type == SDL_MOUSEBUTTONUP)
    {
        if(events->button.button == SDL_BUTTON_LEFT)
        {
            x = events->button.x;
            y = events->button.y;
            if ( ( x > GetPosition().x ) && ( x < GetPosition().x + SizeW ) && ( y > GetPosition().y ) && ( y < GetPosition().y + GetSize().y ) )
            {
               SDL_StartTextInput();
               OptionEdit = true;
            }
            else
            {
                OptionEdit = false;
            }
        }
    }
    else
    {
         //Obsluga Eventu Klawiszy//
        if( events->type == SDL_KEYDOWN )
        {
            if( events->key.keysym.sym == SDLK_BACKSPACE && mText->Lenght() > 0 && OptionEdit == 1)
            {
                mText->RemoveChars(Index_Txt-1);
                Index_Txt--;
            }
        }
    }
    if(OptionEdit == true)
    {
        if(events->type == SDL_TEXTINPUT)
        {
            mText->addChars(events->text.text,Index_Txt);
            if(events->text.text != 0)
                Index_Txt++;
        }
        if(events->type == SDL_TEXTEDITING)
        {

        }
    }

    if(events->type == SDL_KEYDOWN && OptionEdit == 1)
    {
        if( events->key.keysym.sym == SDLK_RIGHT && Index_Txt < mText->GetString().length())
        {
            Index_Txt++;
        }
        else if(events->key.keysym.sym == SDLK_LEFT && Index_Txt > 0)
        {
            Index_Txt--;
        }
    }
}
void LineEdit::Draw()
{
    SDL_Rect Pos = GetRect();
    SDL_Rect BRect = GetRect();
    SDL_Point Pos_Tex = mText->GetSize(Index_Txt);
    SDL_Rect BTexPos = mPositionTex[0];
    BTexPos.w-=10;
    BRect.w-=10;
    SDL_Rect ERect = GetRect();
    SDL_Rect ETexPos = mPositionTex[0];
    ETexPos.w-=10;
    ETexPos.x+=10;
    ERect.x-=10;
    SDL_Rect MRect = GetRect();
    SDL_Rect MTexPos = mPositionTex[0];
    MTexPos.w -=20;
    MTexPos.x +=10;
    MRect.w -=20;
    for(int i = 0;i<ElementW+2;i++)
    {
        if(i == 0)
        {
            BRect.x = Pos.x;
            SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&BTexPos,&BRect);
            Pos.x+=BRect.w;
        }
        else if( i != 0 && i != ElementW +1)
        {
            MRect.x = Pos.x;
            SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&MTexPos,&MRect);
            Pos.x+=MRect.w;
        }
        else if(i == ElementW+1)
        {
            ERect.x = Pos.x-End;
            SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&ETexPos,&ERect);
        }
    }
    SDL_SetRenderDrawColor( CRender::GetRender()->mRender, 0x00, 0x00, 0xFF, 0xFF );
    if(OptionEdit == EDIT)
    SDL_RenderDrawLine(CRender::GetRender()->mRender,GetPosition().x+Pos_Tex.x,GetPosition().y+5,GetPosition().x+Pos_Tex.x,GetPosition().y+35);
    mText->Draw();
}
