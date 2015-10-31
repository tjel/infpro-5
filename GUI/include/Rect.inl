template <typename T>
inline Rect<T>::Rect():left(0),top(0),width(0),height(0)
{

}
template <typename T>
inline Rect<T>::Rect(T A,T B,T C,T D):left(A),top(B),width(C),height(D)
{

}
template <typename T>
template <typename U>
inline Rect<T>::Rect(const Rect<U>& vector) :
    left(static_cast<T>(vector.left)),
    top(static_cast<T>(vector.top)),
    width(static_cast<T>(vector.width)),
    height(static_cast<T>(vector.height))
{
}
template <typename T>
Rect<T> Rect<T>::StringToRect(std::string  date)
{
    int b,c,d,e;
    b = date.find(',',1);
    c = date.find(',',b+1);
    d = date.find(',',c+1);
    e = date.find(')',d+1);
    return Rect<T>(std::stoi(date.substr(1,b-1)),std::stoi(date.substr(b+1,c-b-1)),std::stoi(date.substr(c+1,d-c-1)),std::stoi(date.substr(d+1,e-d-1)));
}
