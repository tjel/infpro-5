
template <typename T>
inline Vector3<T>::Vector3():a(0),b(0),c(0)
{

}
template <typename T>
inline Vector3<T>::Vector3(T A,T B,T C):a(A),b(B),c(C)
{

}
template <typename T>
template <typename U>
inline Vector3<T>::Vector3(const Vector3<U>& vector) :
a(static_cast<T>(vector.a)),
b(static_cast<T>(vector.b)),
c(static_cast<T>(vector.c))
{
}
