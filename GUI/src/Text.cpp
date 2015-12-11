#include "include/Text.hpp"
Text::Text()
{

}

Text::Text(std::string Txt, SDL_Point Pos):mText(Txt)
{
    mFont = ResourceManager::GetManagerResource()->GetFont();
    mColorTxt =  {190,190,190,190};
    setPosition(Pos);
    CreateText();
}

Text::Text(std::string Txt, int x,int y):mText(Txt)
{
    mFont = ResourceManager::GetManagerResource()->GetFont();
    setPosition(x,y);
    CreateText();
}

Text::Text(std::string Txt, int x,int y,TTF_Font * Font):mText(Txt),mFont(Font)
{
    setPosition(x,y);
}

void Text::CreateText()
{
    SDL_Color textColor = { 190, 190, 190, 255 };
    if(mText.empty() == 1)
    {
        mTxtSur = TTF_RenderText_Blended_Wrapped( ResourceManager::GetManagerResource()->GetFont()," ", mColorTxt ,10);
    }
    else
    {
        mTxtSur = TTF_RenderText_Blended_Wrapped( ResourceManager::GetManagerResource()->GetFont(),mText.c_str(), mColorTxt ,10);
    }


    mTextureTxt = SDL_CreateTextureFromSurface(CRender::GetRender()->mRender,mTxtSur);
    setSize(mTxtSur->w,mTxtSur->h);
}
void Text::setColor(int a, int b, int c)
{
    mColorTxt = {a,b,c,0};
    CreateText();
}

void Text::setColor(SDL_Color fc)
{

}
void Text::setString(std::string txt)
{
    mText += txt;
    CreateText();
}
void Text::RemoveChars()
{
    if(mText.length() > 0)
    mText.pop_back();

    CreateText();
}
void Text::RemoveChars(int index)
{
    mText.erase(index,1);
    CreateText();

}
std::string Text::GetString()
{
    return mText;
}
SDL_Point Text::GetSize(int index)
{
    SDL_Point temp; //Zostanie usuniete i przeniesione do klasy aby nie tworzyc caly czas nowej zminej i potem jej nie niszczycna stosie
    std::string Txt = GetString().substr(0,index);
    TTF_SizeText(ResourceManager::GetManagerResource()->GetFont(),Txt.c_str(),&temp.x,&temp.y);
    return temp;
}
void Text::addChars(std::string chars, int index)
{
    mText.insert(index,chars.c_str());
    CreateText();
}

int Text::Lenght()
{
    return mText.size();
}


void Text::Draw()
{
    SDL_Rect Rect = GetRect();
    SDL_RenderCopy(CRender::GetRender()->mRender,mTextureTxt,NULL,&Rect);
}

Text::~Text()
{
    SDL_DestroyTexture(mTextureTxt);
    SDL_FreeSurface(mTxtSur);
}

