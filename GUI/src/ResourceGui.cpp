#include "include/ResourceGui.hpp"

ResourceGui::ResourceGui(Vector3i Color)
{
    mColor = Color;

}

ResourceGui::ResourceGui(IntRect Part):mPart(Part),mMiddle(IntRect(0,0,0,0))
{
    this->SDLPart.h = mPart.height;
    this->SDLPart.w = mPart.width;
    this->SDLPart.x = mPart.x;
    this->SDLPart.y = mPart.y;
    this->SDLMiddle.h = mMiddle.height;
    this->SDLMiddle.w = mMiddle.width;
    this->SDLMiddle.x = mMiddle.x;
    this->SDLMiddle.y = mMiddle.y;

}

ResourceGui::ResourceGui(IntRect Part,IntRect Middle):mPart(Part),mMiddle(Middle)
{
    this->SDLPart.h = mPart.height;
    this->SDLPart.w = mPart.width;
    this->SDLPart.x = mPart.x;
    this->SDLPart.y = mPart.y;
    this->SDLMiddle.h = mMiddle.height;
    this->SDLMiddle.w = mMiddle.width;
    this->SDLMiddle.x = mMiddle.x;
    this->SDLMiddle.y = mMiddle.y;
}
ResourceGui::~ResourceGui()
{

}
