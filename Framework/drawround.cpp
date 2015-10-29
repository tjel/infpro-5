#include "drawround.h"

DrawRound* DrawRound::instance = nullptr;

DrawRound::DrawRound()
{

}

DrawRound* DrawRound::GetInstance()
{
    if(instance==nullptr)
        instance = new DrawRound();

    return instance;
}

DrawRound* DrawRound::AddToRound(DrawableObject *obj)
{
    round.push_back(obj);

    return instance;
}

DrawRound* DrawRound::DrawAll()
{
    for(unsigned int i=0; i<round.size(); i++)
        round[i]->Draw();

    return instance;
}
