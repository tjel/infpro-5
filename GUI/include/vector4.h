#ifndef VECTOR4_H
#define VECTOR4_H
template <typename T>
class Vector4
{
public:
    Vector4();
    Vector4(T A,T B,T C, T D);
    template <typename U>
    explicit Vector4(const Vector4<U>& vector);
    T a;
    T b;
    T c;
    T d;
};
#include <src/vector4.inl>
typedef Vector4<int>          Vector4i;
typedef Vector4<unsigned int> Vector4u;
#endif // VECTOR4_H
