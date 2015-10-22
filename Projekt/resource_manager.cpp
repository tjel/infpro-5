#include "resource_manager.h"

Resource_Manager::Resource_Manager(std::string mNameFile):NameFile(mNameFile)
{
    std::istringstream date(LoadFile(mNameFile));


}
std::string Resource_Manager::LoadFile(std::string mNameFile)
{
    std::fstream file;
    std::stringstream  sstream;
    file.open(NameFile.c_str(), std::ios::in);
    if(file.is_open() == 1)
    {
        sstream << file.rdbuf();
    }
    return sstream.str();
}
