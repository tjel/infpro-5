#include "INI_Parser.h"
#include <iostream>
#include <fstream>

INI_Parser::INI_Parser()
{
}

std::string INI_Parser::DeleteSpaces(std::string str)
{
    for(unsigned int i = 0; i < str.length(); i++)
    {
        // usuwanie spacji
        if(str[i] == ' ')
        {
            str.erase(i, 1);
            i -= 1;
        }
    }
    return str;
}

INI_Data INI_Parser::ParsFile(std::string file_name)
{
    INI_Data Data;
    std::fstream ini_file;

    std::string section, parameter, value, line;

    ini_file.open(file_name, std::fstream::in);
    if(!ini_file)
    {
        std::cout << "Nie mozna otworzyc pliku \"" << file_name << "\"";
        std::cout << " Plik moze jeszcze nie istniec" << std::endl;
    }
    else
    {
        while(getline(ini_file, line))
        {
            // jezeli lnia nie jest zakomentowana
            if(line[0] != '#')   // sprawdzanie czy w lini znajduja sie nawiasy kwadratowe
            {
                if(line.find_first_of(']') > 1 && line.find('[') < line.length())   // wyciagniecie nazwy sekcji
                {
                    section = DeleteSpaces(line.substr(line.find_first_of('[') + 1, line.find_first_of(']') - 1));
                    // Data.AddSections(section);
                }
                else                                     // czy znajdue sie znak przypisania
                {
                    if(line.find('=') < line.length())   // wyciagniecie nazwy parametru i wartosci do niego przypisanej
                    {
                        parameter = DeleteSpaces(line.substr(0, line.find_first_of('=')));
                        value = DeleteSpaces(line.substr(line.find_first_of('=') + 1, line.length()));
                        Data.AddValue(section, parameter, value);
                    }
                }
            }
        }
    }
    ini_file.close();

    return Data;
}

void INI_Parser::SaveFile(std::string file_name, INI_Data data)
{
    std::fstream ini_file;
    remove(file_name.c_str());
    ini_file.open(file_name, std::ios::out);
    // tworzenie odpowiedniego iteratora i przeszukanie mapy i zapisanie do pliku
    // sekcji, nastepnie parametru z wartoscia
    // data.GetSections().size();
    for(std::map<SECTION, std::map<PARAMETER, VALUE> >::iterator it = data.GetSections().begin();
            it != data.GetSections().end(); it++)
    {
        if(it->first != "")
        {
            ini_file << "[" << it->first << "]\n";
            std::cout << "[" << it->first << "]\n";
        }
        for(std::map<PARAMETER, VALUE>::iterator it2 = it->second.begin(); it2 != it->second.cend(); it2++)
        {
            if(data.Exist(it->first, it2->first))
            {
                ini_file << it2->first << "=" << it2->second << "\n";
                std::cout<< it2->first << "="<< it2->second << "\n";
            }
        }
    }
    ini_file.close();
}
