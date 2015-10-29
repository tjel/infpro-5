#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

/* Grzegorz Małkiewicz
 * Klasa Bazowa po której dziedziczą wszystkie rysowane obiekty,
 * wykorzystywana do polimorfizmu przez klase DrawRound. */

class DrawableObject
{
public:
    DrawableObject();

    //Virtualna funkcja Draw, wywolywana przez kolejke rysowania
    virtual void Draw()=0;
    DrawableObject* AddToRound();
protected:

};

#endif // DRAWABLEOBJECT_H
