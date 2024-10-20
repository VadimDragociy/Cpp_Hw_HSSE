#include <iostream>


template <typename T>
inline T searchMin(T const& arg0)
{
    return arg0;
}
template<typename T, typename... Args>
inline T searchMin(T const & arg0, T const & arg1, Args const &... args)
{
    if(arg0 < arg1) return searchMin(arg0, args...);
    return searchMin(arg1, args...);
}

int main(){
    std:: cout << searchMin(1,2,-3,4,-10,100,-500,30,8,9,10);
}