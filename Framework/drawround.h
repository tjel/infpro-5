#ifndef DRAWROUND_H
#define DRAWROUND_H

#include<vector>

#include "drawableobject.h"

class DrawRound
{
public:
    //statyczna metoda zwracająca wskaźnik na instancje
    static DrawRound* GetInstance();

    DrawRound* AddToRound(DrawableObject* obj);
    DrawRound* DrawAll();
private:
    //Kolejka ma być jedna więc konstruktor jest prywatny
    DrawRound();

    //Jedna jedyna instancja klasy, i wskaźnik na nią
    static DrawRound* instance;
    std::vector<DrawableObject*> round;
};

#endif // DRAWROUND_H
