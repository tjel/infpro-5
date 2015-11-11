#include "include/MenagerResource.h"
#include <iostream>
#include <memory>
#include <include/Vector3.h>
#include <algorithm>
MenagerResource::MenagerResource(std::string FileName):mFileName(FileName)
{
    File = std::make_shared<std::ifstream> (FileName,std::ios::in);
    if(File->good())
    {
        LoadFile();
        std::cout<<"Good\n";
        Resource["Button"]["TextColorNormal"]->Good();//Przyklad
    }
}
void MenagerResource::LoadFile()
{
    std::string temp;
    std::string ClassName;
    int a;   //mozna zminic na short! kazdy z int
    int b;
    int c;
    int d;
    int e;
    int f;
    while(!File->eof())//czeka na koniec pliku
    {
        std::getline(*File,temp);
        if(temp.find("Part(",0) != std::string::npos && temp.find("Middle",0) != std::string::npos)
        {
            a = temp.find("Part",0)+4; //Znajduje gdzi jest w danej lini Part;
            b = temp.find(')',a); //
            c = temp.find("Middle",b)+6;
            d = temp.find(';',c);
            e = temp.find(':',0);
            f = temp.find(',',e);
            Resource[ClassName][RemoveAllCharacter(temp.substr(0,e-1),' ')] = std::make_shared<ObjectGUI>(temp.substr(e+1,f-e-1),
            IntRect::StringToRect(temp.substr(a,(b-a)+1)),IntRect::StringToRect(temp.substr(c,(d-c)+1)));
        }
        else if(temp.find("Middle",0) == std::string::npos && temp.find("Part",0) != std::string::npos)
        {
            a = temp.find("Part",0)+4; //Znajduje gdzi jest w danej lini Part;
            b = temp.find(')',a);
            d = temp.find(';',c);
            e = temp.find(':',0);
            f = temp.find(',',e);
            Resource[ClassName][RemoveAllCharacter(temp.substr(0,e-1),' ')] = std::make_shared<ObjectGUI>(temp.substr(e+1,f-e-1),IntRect::StringToRect(temp.substr(a,(b-a)+1)));
        }
        else if(temp.find("rgb",0) != std::string::npos)
        {
            a = temp.find("rgb",0)+3;
            d = temp.find(';',a);
            e = temp.find(':',0);
            Resource[ClassName][RemoveAllCharacter(temp.substr(0,e-1),' ')] = std::make_shared<ObjectGUI>(Vector3i::StringToVector3(temp.substr(a,d-a)));
        }
        else if(temp.find("}",0) != std::string::npos)
        {

        }
        else if(temp.find("{",0) != std::string::npos)
        {
            a = temp.find('{',0);
            ClassName = RemoveAllCharacter(temp.substr(0,a-1),' ');
        }
    }
    File->close();
}
std::string MenagerResource::RemoveAllCharacter(std::string Date,char character)
{
    Date.erase(std::remove(Date.begin(),Date.end(),character),Date.end()); //Usuwanie dany znak  z tekstu
    return Date;
}

MenagerResource::~MenagerResource()
{

}
