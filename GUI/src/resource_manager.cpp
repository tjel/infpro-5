#include "include/resource_manager.h"

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
    std::map<std::string,std::map<std::string,std::shared_ptr<Object_Image>>> Date;
    Date["Button"]["Normal"] = std::make_shared<Object_Image>(Vector3i(5,5,5));
    return sstream.str();
}
