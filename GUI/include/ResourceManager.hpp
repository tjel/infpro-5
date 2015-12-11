#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include<fstream>
#include<string>
#include<memory>
#include<map>
#include<include/ResourceGui.hpp>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_log.h>
#include<SDL2/SDL.h>
#include<include/CRender.hpp>
#include<SDL2/SDL_ttf.h>
#include"include/LogSDL.hpp"
#include <algorithm>
class ResourceManager :public LogSDL
{
public:
    ResourceManager(std::string FileName);
    std::map<std::string,std::map<std::string,std::shared_ptr<ResourceGui> > > GetResource() {return Resource;}
    static ResourceManager * GetManagerResource();//GetResMan;
    ~ResourceManager();
    TTF_Font * GetFont(){return mFont;}
    SDL_Texture * mTexture;
protected:
     TTF_Font * mFont;

private:
    void LoadFont();
    void LoadFileConfigurate();
    std::shared_ptr<std::ifstream> File;
    std::map<std::string,std::map<std::string,std::shared_ptr<ResourceGui> > > Resource;
    std::string RemoveAllCharacter(std::string Date,char character); //Usuwanie danego znaku z tekstu
    static ResourceManager * instance;

    std::string mFileName;

};

#endif // RESOURCEMANAGER_H
