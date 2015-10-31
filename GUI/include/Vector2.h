#ifndef VECTOR2_H
#define VECTOR2_H
template <typename T>
class Vector2
{
public:
    Vector2();
    Vector2(T A,T B);
    template <typename U>
    explicit Vector2(const Vector2<U>& vector);
    T a;
    T b;
};
#include "Vector2.inl"
typedef Vector2<int>          Vector2i;
typedef Vector2<unsigned int> Vector2u;
#endif // VECTOR4_H

