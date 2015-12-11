#include "include/CheckBox.hpp"
#include <QDebug>
CheckBox::CheckBox(Gui & mGui)
{
    setPosition(0,0);
    Init(mGui);
    mGui.AddClassGui(GetPtr());
}
CheckBox::CheckBox(Gui & mGui,int x,int y, std::string Txt)
{

    Init(mGui);
    mText = new Text(Txt,x + mPositionTex[0].w,y);
    setPosition(x,y);
    mGui.AddClassGui(GetPtr());
}
void CheckBox::Init(Gui &gui)
{
    setMode(normal);
    mPositionTex.push_back(SDL_Rect(ResourceManager::GetManagerResource()->GetResource()["Checkbox"]["UncheckedImage"]->GetSDLPart()));
    mPositionTex.push_back(SDL_Rect(ResourceManager::GetManagerResource()->GetResource()["Checkbox"]["CheckedImage"]->GetSDLPart()));
    mPositionTex.push_back(SDL_Rect(ResourceManager::GetManagerResource()->GetResource()["Checkbox"]["UncheckedHoverImage"]->GetSDLPart()));
    mPositionTex.push_back(SDL_Rect(ResourceManager::GetManagerResource()->GetResource()["Checkbox"]["CheckedHoverImage"]->GetSDLPart()));
    mColor.push_back(Vector3i(ResourceManager::GetManagerResource()->GetResource()["Checkbox"]["TextColorNormal"]->GetColor()));
    mColor.push_back(Vector3i(ResourceManager::GetManagerResource()->GetResource()["Checkbox"]["TextColorHover"]->GetColor()));
    SDL_Rect temp = mPositionTex[0];
    setSize(temp.w,temp.h);
}
void CheckBox::handleEvent(SDL_Event *events)
{
    SDL_GetMouseState( &x, &y );
    if(events->type == SDL_MOUSEBUTTONUP)
    {
        if(events->button.button == SDL_BUTTON_LEFT)
        {
            x = events->button.x;
            y = events->button.y;
            if ( ( x > GetPosition().x ) && ( x < GetPosition().x + GetSize().x  ) && ( y > GetPosition().y ) && ( y < GetPosition().y + GetSize().y ) )
            {
                switch(GetMode())
                {
                case normal:
                    setMode(hover_clicked);
                    break;
                case clicked:
                    setMode(hover_normal);
                    break;
                case hover_normal:
                    setMode(hover_clicked);
                    break;
                case hover_clicked:
                    setMode(hover_normal);
                    break;
                }
            }
        }
    }
    else if(events->type == SDL_MOUSEMOTION)
    {
        if ( ( x > GetPosition().x ) && ( x < GetPosition().x + GetSize().x  ) && ( y > GetPosition().y ) && ( y < GetPosition().y + GetSize().y ) )
        {
            switch(GetMode())
            {
            case normal:
                setMode(hover_normal);
                break;
            case clicked:
                setMode(hover_clicked);
                break;
            }
        }
        else
        {
            switch(GetMode())
            {
            case hover_normal:
                setMode(normal);
                break;
            case hover_clicked:
                setMode(clicked);
                break;
            }
        }


    }

}

void CheckBox::Draw()
{
    SDL_Rect Rect = GetRect();
    SDL_Rect TexPos = mPositionTex[0];
    switch(GetMode())
    {
    case normal:
        mText->setColor(mColor[0].a,mColor[0].b,mColor[0].c);
        SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&mPositionTex[0],&Rect);
        break;
    case clicked:
        mText->setColor(mColor[0].a,mColor[0].b,mColor[0].c);
        SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&mPositionTex[1],&Rect);
        break;
    case hover_normal:
        mText->setColor(mColor[1].a,mColor[1].b,mColor[1].c);
        SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&mPositionTex[2],&Rect);
        break;
    case hover_clicked:
        mText->setColor(mColor[1].a,mColor[1].b,mColor[1].c);
        SDL_RenderCopy(CRender::GetRender()->mRender,ResourceManager::GetManagerResource()->mTexture,&mPositionTex[3],&Rect);
        break;

    }
    mText->Draw();
}
