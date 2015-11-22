#ifndef INI_DATA_H
#define INI_DATA_H

#include <string>
#include <vector>
#include <map>

typedef std::string SECTION;
typedef std::string PARAMETER;
typedef std::string VALUE;

class INI_Data
{
public:
    INI_Data();
    std::string GetValue(std::string section,
                             std::string parameter);

    void AddValue(std::string section,
                     std::string parameter,
                     std::string value);

    void AddSections(std::string section);

    unsigned int GetSize();

    bool IsEmpty();

    bool Exist(std::string section,
               std::string parameter);

    std::map<SECTION,
    std::map<PARAMETER,VALUE>> GetSections();

private:
    std::map<SECTION,
    std::map<PARAMETER,VALUE>> sections;
    unsigned size;
};

#endif // INI_DATA_H
