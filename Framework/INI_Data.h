#ifndef INI_DATA_H
#define INI_DATA_H

#include <string>
#include <vector>

struct Parameter
{
    std::string parameter_name;
    std::string value;
};

struct Section
{
    std::string section_name;
    std::vector<Parameter> parameters;
};

class INI_Data
{
public:
    INI_Data();
    std::string GetDataValue(std::string section, std::string parameter);

    void AddNewSection(std::string section);
    void AddNewParameter(std::string section, std::string parameter);
    void AddNewValue(std::string section, std::string parameter, std::string value);

private:
    std::vector<Section> sections;
};

#endif // INI_DATA_H
