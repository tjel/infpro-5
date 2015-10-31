#ifndef LoadGui_H
#define LoadGui_H
#include <include/ObjectGUI.h>
#include <map>
#include <fstream>
#include <memory>
class LoadGui
{
public:
    LoadGui(std::string FileName);
    ~LoadGui();
    std::string LoadFile();
protected:
private:
    void LoadGUI();
    std::string mFileName;
    std::shared_ptr<std::ifstream> File;
    std::string RemoveAllCharacter(std::string Date,char character); //Usuwanie danego znaku z tekstu
    std::map<std::string,std::map<std::string,std::shared_ptr<ObjectGUI> > > Date; //
};

#endif // LoadGui_H
//Funckja LoadGui() jest wykonywana az dojdzie do konca plijku
//Potem jest pobierana jedna linia kodu z pliku i sprawdzane jest czy wystepuje w niej
//a.) Part and Middle
//b.) Middle
//c.) rgb
//d.) } albo {
//Jezeli wykruje to sa wykon\ywane operacje w if czyli wycina liczby i nazwe i kozystajacac
// z funkcji statycznej z Rect i Vector3 konweruje je na liczby i dalej tworzymy element w Date(map))
