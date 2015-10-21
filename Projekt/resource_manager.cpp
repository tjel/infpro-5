#include "resource_manager.h"

Resource_Manager::Resource_Manager(std::string mNameFile):NameFile(mNameFile)
{
std::fstream file;
file.open(NameFile.c_str(), std::ios::in | std::ios::out );
}

