#include "include/ResourceManager.hpp"
ResourceManager * ResourceManager::instance = nullptr;
ResourceManager::ResourceManager(std::string FileName)
{
    File = std::make_shared<std::ifstream> (FileName,std::ios::in); //Tworzymy intligentny wskaznik std::ifstream//
    if(File->good())//Sprawdzamy czy plik zostal wczytany//
    {
        mTexture = IMG_LoadTexture(CRender::GetRender()->mRender,"Black.png");//Wczytywanie Textury
        if(mTexture == nullptr)
        {
            logSDLError(std::cout,"IMG_LoadTexture");
        }
        LoadFileConfigurate();
        LoadFont();
    }
    else
    {
        std::cout<<"Plik konfiguracyjny nie zostal wczytany\n";
        exit(1);
    }
}
ResourceManager * ResourceManager::GetManagerResource()
{
    if(instance == nullptr)instance = new ResourceManager("Black.txt");
    return instance;
}

void ResourceManager::LoadFileConfigurate()
{
    std::string temp;
    std::string ClassName;
    int a = 0;   //mozna zminic na short! kazdy z int
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    while(!File->eof())//czeka na koniec pliku
    {
        std::getline(*File,temp);
        if(temp.find("Part(",0) != std::string::npos && temp.find("Middle",0) != std::string::npos)
        {
            a = temp.find("Part",0)+4; //Znajduje gdzi jest w danej lini Part;
            b = temp.find(')',a); //
            c = temp.find("Middle",b)+6;
            d = temp.find(':',0);
            Resource[ClassName][RemoveAllCharacter(temp.substr(0,d-1),' ')] =
            std::make_shared<ResourceGui>(IntRect::StringToRect(temp.substr(a,(b-a)+1))),IntRect::StringToRect(temp.substr(c,d-c+1));
        }
        else if(temp.find("Middle",0) == std::string::npos && temp.find("Part",0) != std::string::npos)
        {
            a = temp.find("Part",0)+4; //Znajduje gdzi jest w danej lini Part;
            b = temp.find(')',a); //
            d = temp.find(':',0);
            Resource[ClassName][RemoveAllCharacter(temp.substr(0,d-1),' ')] = std::make_shared<ResourceGui>(IntRect::StringToRect(temp.substr(a,(b-a)+1)));
        }
        else if(temp.find("rgb",0) != std::string::npos)
        {
            a = temp.find("rgb",0)+3;
            d = temp.find(';',a);
            e = temp.find(':',0);
            Resource[ClassName][RemoveAllCharacter(temp.substr(0,e-1),' ')] = std::make_shared<ResourceGui>(Vector3i::StringToVector3(temp.substr(a,d-a)));
        }
        else if(temp.find("{",0) != std::string::npos)
        {
            a = temp.find('{',0);
            ClassName = RemoveAllCharacter(temp.substr(0,a-1),' ');
        }
    }
}
std::string ResourceManager::RemoveAllCharacter(std::string Date,char character)
{
    Date.erase(std::remove(Date.begin(),Date.end(),character),Date.end()); //Usuwanie dany znak  z tekstu
    return Date;
}
void ResourceManager::LoadFont()
{
    TTF_Init();
    mFont = TTF_OpenFont( "DejaVuSans.ttf", 30 );
    if(mFont == nullptr)
    {
        logSDLError(std::cout,"TTF_OpenFont");
    }

}
ResourceManager::~ResourceManager()
{
    TTF_CloseFont(mFont);
    SDL_DestroyTexture(mTexture);
}
