#ifndef OBJECTGUI_H
#define OBJECTGUI_H
#include<vector>
#include<include/Vector3.h>
#include<string>
#include<include/Rect.h>
#include<memory>
#include<SDL2/SDL_image.h>
class ObjectGUI
{
public:
    ObjectGUI(std::string name);
    ObjectGUI(std::string Dir,IntRect Part,IntRect Middle);
    ObjectGUI(std::string Dir,IntRect Part);
    ObjectGUI(Vector3i Color);
    void Good();
protected:
private:
    std::string mDir;
    IntRect mPart;
    IntRect mMiddle;
    std::shared_ptr<Vector3i> mColor;
    std::shared_ptr<SDL_Texture> mTexture;
    std::shared_ptr<SDL_Texture> LoadTexture(std::string & name);

};

#endif // OBJECTGUI_H
