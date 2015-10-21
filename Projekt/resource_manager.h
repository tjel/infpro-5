#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
#include <SDL2/SDL_image.h>
#include <string>
#include <memory>
#include <fstream>
#include <vector>
struct Coordinate
{
    Coordinate(int mwys,int mszer,int mx,int my)
    :wys(mwys),szer(mszer),x(mx),y(my)
    {

    };
    int wys;
    int szer;
    int x;
    int y;
    std::string name;
};

class Resource_Manager
{
public:
    Resource_Manager(std::string mNameFile);
private:
    std::string NameFile;
    int lenght;
    std::vector<Coordinate> mCoordinate;
    std::shared_ptr<Resource_Manager> GetResource;
};

#endif // RESOURCE_MANAGER_H
