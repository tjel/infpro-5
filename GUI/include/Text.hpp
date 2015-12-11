#ifndef TEXT_H
#define TEXT_H
#include <include/Widget.hpp>
#include <SDL2/SDL.h>
class Text : public Widget
{
public:
    Text();
    Text(std::string Txt,SDL_Point Pos);
    Text(std::string Txt, int x, int y);
    Text(std::string Txt,int x,int y,TTF_Font * Font);
    std::string GetString();
    int Lenght();
    void setColor(int a,int b,int c);
    void setColor(SDL_Color fc);
    void setString(std::string txt);
    SDL_Point GetSize(int index);
    void addChars(std::string chars,int index);
    void RemoveChars();
    void RemoveChars(int index);
    std::string GetText(){return mText;}
    virtual void Draw();
    ~Text();
private:
    SDL_Surface* mTxtSur;
    void CreateText();
    SDL_Texture * mTextureTxt;
    std::string mText;
    TTF_Font * mFont;
    SDL_Color mColorTxt;
};

#endif // TEXT_H
