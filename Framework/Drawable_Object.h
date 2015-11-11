#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

/* Klasa Bazowa po której dziedziczą wszystkie rysowane obiekty,
 * wykorzystywana do polimorfizmu przez klase DrawRound. */

class Drawable_Object
{
public:
    Drawable_Object();

    //Virtualna funkcja Draw, wywolywana przez kolejke rysowania
    virtual void Draw()=0;
    Drawable_Object* AddToQueue();
protected:

};

#endif // DRAWABLEOBJECT_H
