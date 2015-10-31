#include "include/ObjectGUI.h"
#include "include/Rect.h"
ObjectGUI::ObjectGUI(std::string Dir,IntRect Part,IntRect Middle):mDir(Dir),mPart(Part),mMiddle(Middle)
{

}
ObjectGUI::ObjectGUI(std::string Dir,IntRect Part):mDir(Dir),mPart(Part),mMiddle(IntRect(0,0,0,0))
{

}
ObjectGUI::ObjectGUI(Vector3i Color)
{
    mColor = std::make_shared<Vector3i>(Color);
}
ObjectGUI::~ObjectGUI()
{

}
void ObjectGUI::Good()
{
    if(mColor == nullptr)
        std::cout<<mDir<<"  "<<mPart.left<<" "<<mPart.top<<" "<<mPart.width<<" "<<mPart.height<<"\n";
    else
        std::cout<<mColor->a<<"\n";
}
