#ifndef DRAWROUND_H
#define DRAWROUND_H

#include <vector>

#include "Drawable_Object.h"

class Draw_Queue
{
public:
    // statyczna metoda zwracająca wskaźnik na instancje
    static Draw_Queue* Get();

    Draw_Queue* AddToQueue(Drawable_Object* obj);
    Draw_Queue* RemoveFromQueue(Drawable_Object* obj);
    Draw_Queue* DrawAll();

private:
    // Kolejka ma być jedna więc konstruktor jest prywatny
    Draw_Queue();

    // Jedna jedyna instancja klasy, i wskaźnik na nią
    static Draw_Queue* singleton;
    std::vector<Drawable_Object*> queue;
};

#endif // DRAWROUND_H
