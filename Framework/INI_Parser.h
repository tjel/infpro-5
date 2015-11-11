#ifndef CONFIGUREPARSER_H
#define CONFIGUREPARSER_H

#include <string>
#include "INI_Data.h"

class INI_Parser
{
public:
    static INI_Data ParsFile(std::string file_name);
    static void SaveFile(std::string file_name, INI_Data data);

private:
    INI_Parser();
};

#endif // CONFIGUREPARSER_H
