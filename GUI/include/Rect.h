#ifndef VECTOR4_H
#define VECTOR4_H
#include <include/Vector2.h>
#include <string>
#include <iostream>
template <typename T>
class Rect
{
public:
    Rect();
    Rect(T A,T B,T C, T D);
    Rect(Vector2<T> Position,Vector2<T> Size);
    static Rect<T> StringToRect(std::string  date); //Zastanaiwam sie czy to ma sens zeby tu byl static ?
    template <typename U>
    explicit Rect(const Rect<U>& vector);
    T left;
    T top;
    T width;
    T height;
private:

};
#include <include/Rect.inl>
typedef Rect<int>          IntRect;
typedef Rect<float>        FloatRect;
#endif // VECTOR4_H

