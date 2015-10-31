template <typename T>
inline Vector2<T>::Vector2():a(0),b(0)
{

}
template <typename T>
inline Vector2<T>::Vector2(T A,T B):a(A),b(B)
{

}
template <typename T>
template <typename U>
inline Vector2<T>::Vector2(const Vector2<U>& vector) :
    a(static_cast<T>(vector.a)),
    b(static_cast<T>(vector.b))
{
}
