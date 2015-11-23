#include "INI_Data.h"

INI_Data::INI_Data()
{
}

std::string INI_Data::GetValue(std::string section, std::string parameter)
{
    return sections[section][parameter];
}

void INI_Data::AddValue(std::string section, std::string parameter,
                           std::string value)
{
    sections[section][parameter]=value;
}

unsigned int INI_Data::GetSize()
{
    return sections.size();
}

bool INI_Data::IsEmpty()
{
    bool empty=true;

    if(sections.size()>0)
        empty=false;

    return empty;
}

std::map<SECTION,
std::map<PARAMETER,VALUE>> INI_Data::GetSections()
{
    return sections;
}
