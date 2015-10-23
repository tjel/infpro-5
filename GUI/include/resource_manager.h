#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
#include <SDL2/SDL_image.h>
#include <sstream>
#include <memory>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <include/vector3.h>
#include <include/vector4.h>
class Object_Image
{
public:
Object_Image(Vector3i a,Vector3i b):Date(a),Middle(b)
{
}
Object_Image(Vector3i a):Date(a),Middle(Vector3i())
{

}
Object_Image(const Object_Image & object)
:Date(object.Date),
 Middle(object.Middle)
{

}
Vector3i Date;    //wspol na osi i h i w
Vector3i Middle;  //Zmiene środka
};
class Resource_Manager
{
public:
    Resource_Manager(std::string mNameFile);
    std::string LoadFile(std::string mNameFile);
private:
    std::map<std::string,std::map<std::string,Object_Image>> Date;
    std::string NameFile;
    int lenght;



};

#endif // RESOURCE_MANAGER_H
