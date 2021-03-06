#ifndef VECTOR3_H
#define VECTOR3_H
#include <string>
template <typename T>
class Vector3
{
public:
    Vector3();
    Vector3(T A,T B,T C);
    static Vector3<T> StringToVector3(std::string date);
    template <typename U>
    explicit Vector3(const Vector3<U>& vector);
    T a;
    T b;
    T c;
};
#include <Vector/Vector3.inl>
typedef Vector3<int>          Vector3i;
typedef Vector3<unsigned int> Vector3u;
#endif // VECTOR4_H

