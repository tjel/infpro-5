#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
#include <SDL2/SDL_image.h>
#include <sstream>
#include <memory>
#include <fstream>
#include <vector>
#include <vector3.h>
class Object_Resource
{
    unsigned short heigh;
    unsigned short width;
    unsigned short x_pos;
    unsigned short y_pos;
    std::string name;

};
class Object_Button
{
 Vector3i RGA = Vector3i(5,10,14);
};

class Resource_Manager
{
public:
    Resource_Manager(std::string mNameFile);
    std::string LoadFile(std::string mNameFile);
private:
    int lenght;
    std::string NameFile;
    std::shared_ptr<Resource_Manager> GetResource;
};

#endif // RESOURCE_MANAGER_H
