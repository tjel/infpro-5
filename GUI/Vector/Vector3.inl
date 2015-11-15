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
template <typename T>
Vector3<T> Vector3<T>::StringToVector3(std::string date)
{
    int b,c,d;
    b = date.find(',',1);
    c = date.find(',',b+1);
    d = date.find(',',c+1);
    return Vector3<T>(std::stoi(date.substr(1,b-1)),std::stoi(date.substr(b+1,c-b-1)),std::stoi(date.substr(c+1,d-c-1)));
}


