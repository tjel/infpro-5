template <typename T>
inline Vector4<T>::Vector4():a(0),b(0),c(0),d(0)
{

}
template <typename T>
inline Vector4<T>::Vector4(T A,T B,T C,T D):a(A),b(B),c(C),d(d)
{

}
template <typename T>
template <typename U>
inline Vector4<T>::Vector4(const Vector4<U>& vector) :
a(static_cast<T>(vector.a)),
b(static_cast<T>(vector.b)),
c(static_cast<T>(vector.c)),
d(static_cast<T>(vector.d))
{
}
